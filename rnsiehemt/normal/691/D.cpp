#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 1000*1000+5;

int n, m, p[maxn], r[maxn];
std::vector<int> g[maxn];

int find(int i) {
    return (i == r[i] ? i : r[i] = find(r[i]));
}

void join(int i, int j) {
    r[find(i)] = find(j);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", p+i);
        r[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        join(a, b);
    }
    for (int i = 0; i < n; i++) {
        g[find(i)].pb(i);
    }
    for (int i = 0; i < n; i++) {
        std::sort(all(g[i]));
        std::vector<int> v;
        for (int j : g[i]) {
            v.pb(p[j]);
        }
        std::sort(all(v));
        std::reverse(all(v));
        for (int j = 0; j < sz(g[i]); j++) {
            p[g[i][j]] = v[j];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d%c", p[i], " \n"[i == n-1]);
    }
}