#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 100*1000+5;

int n, m, best, acolor[maxn], bcolor[maxn], ans1, ans2;
std::vector<std::pair<int, int>> e[maxn];
bool aseen[maxn], bseen[maxn], ans1rip, ans2rip;
std::vector<int> v, first, second, ans1v, ans2v;

int size, blah;
bool rip;
void go(int i, bool *seen, int *color) {
    seen[i] = true;
    v.pb(i);
    size++;
    if (color[i]) {
        blah++;
        first.pb(i);
    } else second.pb(i);
    for (auto &edge : e[i]) {
        int j = edge.first, type = edge.second;
        int nextcolor = color[i];
        if (type == 1) nextcolor = 1 - nextcolor;
        if (seen[j]) {
            if (color[j] != nextcolor) rip = true;
        } else {
            color[j] = nextcolor;
            go(j, seen, color);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; char c; scanf("%d%d %c", &a, &b, &c); a--; b--;
        e[a].eb(b, c == 'B');
        e[b].eb(a, c == 'B');
    }
    for (int i = 0; i < n; i++) if (!aseen[i]) {
        v.clear();
        int best = 1e9;
        size = blah = 0; rip = false; first.clear(); second.clear();
        go(i, aseen, acolor);
        std::vector<int> bestv;
        if (!rip) {
            if (blah < size-blah) { best = blah; bestv = first; }
            else { best = size - blah; bestv = second; }
            ans1 += best;
            for (int j : bestv) ans1v.pb(j);
        } else {
            ans1rip = true;
        }
        for (int j : v) for (auto &edge : e[j]) {
            edge.second = 1 - edge.second;
        }
        best = 1e9;
        bestv.clear();
        size = blah = 0; rip = false; first.clear(); second.clear();
        go(i, bseen, bcolor);
        if (!rip) {
            if (domin(best, blah)) bestv = first;
            if (domin(best, size-blah)) bestv = second;
            ans2 += best;
            for (int j : bestv) ans2v.pb(j);
        } else {
            ans2rip = true;
        }
    }
    if (ans1rip && ans2rip) {
        printf("-1\n");
        return 0;
    }
    if (ans1rip) ans1 = 1e9;
    if (ans2rip) ans2 = 1e9;
    if (ans2 < ans1) { std::swap(ans1, ans2); std::swap(ans1v, ans2v); }
    printf("%d\n", ans1);
    for (int i : ans1v) printf("%d ", i+1);
    printf("\n");
}