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
const int N = 2e5 + 13;
const int M = 998244353;
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

vector<int> g[N];
int a[N];
int cnt = 0;

int dfs(int v, int par, int xr) {
//    cout << "dfs " << v << ' ' << cnt << endl;
    int res = a[v];

    for(auto u : g[v]) {
        if(u == par)
            continue;

        int x = dfs(u, v, xr);

        if(x == xr) {
            cnt++;
        } else {
            res ^= x;
        }
    }

    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;

    int xr = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        xr ^= a[i];

        g[i].erase(g[i].begin(), g[i].end());
    }

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    if(xr == 0) {
        cout << "YES" << endl;
        return;
    }

    cnt = 0;
    dfs(0, 0, xr);

//    cout << "---------" << xr << ' ' << cnt << endl;

    cout << (cnt >= 2 && k >= 3 ? "YES" : "NO") << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}