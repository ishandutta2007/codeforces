//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
//const int M = 1e9 + 7;
const int M = 998244353;
const ld eps = 1e-6;
const int B = 300;
const int K = 400;
const int LOGN = 20;

/*
1
4
3 2 3 4
1 2 4 3
1 4 2 4

1
8
5 4 2 3
6 4 5 4
1 3 5 2
6 8 2 1
3 5 3 4
3 2 2 5
6 7 4 3
*/

int sum(int a, int b) {
    a += b;
    return (a < M ? a : a - M);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

int inv[N];
int d[N];
map<int, int> mp[N];

vector<pair<int, pii>> g[N];

map<int, int>* dfs1(int v, int par) {
    map<int, int>* res = new map<int, int>();

    for(auto pr : g[v]) {
        int u = pr.f;

        if(u == par)
            continue;

        int x = pr.s.f, y = pr.s.s;

        map<int, int>* rs = dfs1(u, v);

        for(auto dv : mp[x]) {
            (*rs)[dv.f] += dv.s;
        }

        for(auto dv : mp[y]) {
            (*rs)[dv.f] = max((*rs)[dv.f] - dv.s, 0);
        }

        if(res->size() < rs->size())
            swap(res, rs);

        for(auto dv : *rs)
            (*res)[dv.f] = max((*res)[dv.f], dv.s);
    }

    return res;
}

int ans = 0;

void dfs2(int v, int par, int res) {
    ans = sum(ans, res);

    for(auto pr : g[v]) {
        int u = pr.f;
        if(u == par)
            continue;

        dfs2(u, v, mul(res, mul(pr.s.s, inv[pr.s.f])));
    }
}

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        g[i].erase(g[i].begin(), g[i].end());
    }

    for(int i = 0; i < n - 1; i++) {
        int v, u, x, y;
        cin >> v >> u >> x >> y;

        v--;
        u--;

        int gcd = __gcd(x, y);
        x /= gcd;
        y /= gcd;

        g[v].emplace_back(u, pii(x, y));
        g[u].emplace_back(v, pii(y, x));
    }

    map<int, int> res = *dfs1(0, -1);

    int x = 1;
    for(auto pr : res) {
        x = mul(x, pow2(pr.f, pr.s));
    }

//    cout << x << endl;

    ans = 0;
    dfs2(0, -1, x);

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 2; i < N; i++) {
        if(d[i] == 0) {
            d[i] = i;

            if(i * 1ll * i < N)
                for(int j = i * i; j < N; j += i)
                    d[j] = i;
        }
    }

    for(int i = 2; i < N; i++) {
        int x = i;
        while(x > 1) {
            mp[i][d[x]]++;
            x /= d[x];
        }
    }

    for(int i = 1; i < N; i++) {
        inv[i] = pow2(i, M - 2);
    }

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}