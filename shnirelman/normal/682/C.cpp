#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 22;
//const int M = 1e9 + 7;
const int M = 998244353;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int a[N];
vector<pii> g[N];


int dfs(int v, li mx) {
    int res = 0;
    if(a[v] < mx) {
        res++;
        mx = INF64;
    }

    for(pii pr : g[v]) {
        res += dfs(pr.f, max(0ll, mx + pr.s));
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i < n; i++) {
        int p, c;
        cin >> p >> c;

        p--;

        g[p].emplace_back(i, c);
    }

    cout << dfs(0, 0) << endl;
}