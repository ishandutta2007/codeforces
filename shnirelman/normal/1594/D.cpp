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
using pli = pair<li, li>;
using pci = pair<char, li>;
//using matr

//const li INF = 2e18 + 13;
const int INF = 1e9 + 13;
const int N = 3e5 + 13;
const int M = 1e9 + 7;//998244353;
const int B = 350;
//const int A = 26;
//const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

int sum(int a, int b) {
    a += b;

    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

/*
*/

vector<pii> g[N];
int col[N];
int c[2] = {0, 0};

bool dfs(int v, int cl) {
    col[v] = cl;
    c[cl]++;

    bool res = false;
    for(auto p : g[v]) {
        int u = p.f, w = p.s;
        int ncl = w ^ cl;

        if(col[u] == -1)
            res |= dfs(u, ncl);
        else if(col[u] != ncl)
            res = true;
    }

    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        g[i].erase(g[i].begin(), g[i].end());
    }

    for(int i = 0; i < m; i++) {
        int v, u;
        string s;
        cin >> v >> u >> s;

        v--;
        u--;

        g[v].emplace_back(u, (s[0] == 'i'));
        g[u].emplace_back(v, (s[0] == 'i'));
    }

    for(int i = 0; i < n; i++)
        col[i] = -1;

    int ans = 0;
    bool fl = false;
    for(int i = 0; i < n; i++) {
        if(col[i] == -1) {
            c[0] = c[1] = 0;
            fl |= dfs(i, 0);
            ans += max(c[0], c[1]);
        }
    }

    cout << (fl ? -1 : ans) << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}