#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 200*1000+5;

int n, m, c[maxn], best, sz, ans;
std::vector<int> e[maxn];
bool seen[maxn];
std::map<int, int> z;

void go(int i) {
    seen[i] = true;
    z[c[i]]++;
    sz++;
    domax(best, z[c[i]]);
    for (int j : e[i]) if (!seen[j]) go(j);
}

int main() {
    scanf("%d%d%*d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", c+i);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d%d", &a, &b); a--; b--;
        e[a].pb(b);
        e[b].pb(a);
    }

    for (int i = 0; i < n; i++) if (!seen[i]) {
        z.clear();
        best = sz = 0;
        go(i);
        ans += sz - best;
    }
    printf("%d\n", ans);
}