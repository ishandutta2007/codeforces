#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 200*1000+5;

int n, m, s, d, a[maxn], prev[maxn];
std::deque<int> jumps, idx;
std::vector<std::pair<int, int>> v;

void addjump(int a, int b) { v.eb(0, b-a); }
void addrun(int a, int b) { v.eb(1, b-a); }

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    std::sort(a, a+n);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (a[i]-1 >= s) {
                jumps.pb(a[i]-1+d);
                idx.pb(i);
            }
        } else {
            if (!jumps.empty() && a[i]-1 - (a[i-1]+1) >= s) {
                jumps.pb(a[i]-1+d);
                idx.pb(i);
                prev[i] = idx.front();
            }
            while (!jumps.empty() && jumps.front() <= a[i]) {
                jumps.pop_front();
                idx.pop_front();
            }
        }
    }
    if (d == 1 || jumps.empty()) printf("IMPOSSIBLE\n");
    else {
        int cur = idx.front();
        addrun(a[n-1]+1, m);
        addjump(a[cur]-1, a[n-1]+1);
        while (cur) {
            addrun(a[cur-1]+1, a[cur]-1);
            addjump(a[prev[cur]]-1, a[cur-1]+1);
            cur = prev[cur];
        }
        addrun(0, a[0]-1);
        std::reverse(all(v));
        for (auto &pair : v) {
            if (pair.second) printf("%s %d\n", pair.first ? "RUN" : "JUMP", pair.second);
        }
    }
}