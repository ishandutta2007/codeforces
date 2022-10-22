//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 1e6 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

vector<int> g[N];
bool a[N];
int cnt[N];
int dp0[N], dp1[N], dp2[N];
int p1[N];
int p2[N];

/*
10 10
1 2
2 3
3 4
4 5
5 6
6 7
4 8
4 9
4 10
10 3 5 6 7 8 9 1 2 4
*/

void dfs1(int v, int par) {
    cnt[v] = a[v];

    for(auto u : g[v]) {
        if(u == par)
            continue;
        dfs1(u, v);
        cnt[v] += cnt[u];
    }
}

void dfs2(int v, int par) {
    if(cnt[v] == a[v]) {
        dp0[v] = dp1[v] = dp2[v] = 0;
        p1[v] = v;
        p2[v] = v;

        return;
    }

    for(auto u : g[v]) {
        if(u == par || cnt[u] == 0)
            continue;

        dfs2(u, v);

        dp0[v] += dp0[u] + 2;
    }

    dp1[v] = dp0[v];
    dp2[v] = dp0[v];

    int mn1 = INF, mn2 = INF;
    int u1 = -1, u2 = -1;
    for(auto u : g[v]) {
        if(u == par || cnt[u] == 0)
            continue;

//        dp1[v] = min(dp1[v], dp0[v] + dp1[u] - dp0[u]);
        if(dp1[v] > dp0[v] + dp1[u] - dp0[u] - 1) {
            dp1[v] = dp0[v] + dp1[u] - dp0[u] - 1;
            p1[v] = p1[u];
//            dp
        } else if(dp1[v] == dp0[v] + dp1[u] - dp0[u] - 1 && p1[v] > p1[u])
            p1[v] = p1[u];

//        if(dp1[v] > dp0[v] - 1) {
//            dp1[v] = dp0[v] - 1;
//
//        }



        if(dp2[v] > dp0[v] + dp2[u] - dp0[u]) {
            dp2[v] = dp0[v] + dp2[u] - dp0[u];
            p2[v] = p2[u];
//            dp
        } else if(dp2[v] == dp0[v] + dp2[u] - dp0[u] && p2[v] > p2[u])
            p2[v] = p2[u];

        if(dp1[u] - dp0[u] - 1 < mn1 || dp1[u] - dp0[u] - 1 == mn1 && p1[u1] > p1[u]) {
            mn2 = mn1;
            u2 = u1;

            u1 = u;
            mn1 = dp1[u] - dp0[u] - 1;
        } else if(dp1[u] - dp0[u] - 1 < mn2 || dp1[u] - dp0[u] - 1 < mn2 && p1[u2] > p1[u]) {
            u2 = u;
            mn2 = dp1[u] - dp0[u] - 1;
        }

//        dp2[v] = min(dp2[v], dp0[v] + dp2[u] - dp0[u]);
    }

    if(dp2[v] > dp0[v] + mn1 + mn2) {
        dp2[v] = dp0[v] + mn1 + mn2;
        p2[v] = min(p1[u1], p1[u2]);
    } else if(dp2[v] == dp0[v] + mn1 + mn2 && p2[v] > min(p1[u1], p1[u2]))
        p2[v] = min(p1[u1], p1[u2]);

    if(dp2[v] > dp1[v]) {
        dp2[v] = dp1[v];
        p2[v] = min(v, p1[v]);
    } else if(dp2[v] == dp1[v] && p2[v] > min(v, p1[v]))
        p2[v] = min(v, p1[v]);

//    cout << "end dfs2 " << v << ' ' << dp0[v] << ' ' << dp1[v] << ' ' << dp2[v] << endl;
//    cout << "p " << p1[v] << ' ' << p2[v] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    int root = -1;
    for(int i = 0; i < m; i++) {
        int v;
        cin >> v;

        v--;

        a[v] = true;
        root = v;
    }

//    cout << "root " << root << endl;

    dfs1(root, -1);

    dfs2(root, -1);

    cout << p2[root] + 1 << endl << dp2[root] << endl;
}