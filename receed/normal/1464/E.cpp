#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const ll N = 100001, R = 1025, MOD = 998244353, M2 = MOD * MOD;
vector<int> g[N];
ll m[R][R];
ll used[N], a[N];

void dfs(int v) {
    used[v] = 1;
    vector<int> li;
    for (int u : g[v]) {
        if (!used[u])
            dfs(u);
        li.push_back(a[u]);
    }
    sort(all(li));
    li.resize(unique(all(li)) - li.begin());
    while (a[v] < li.size() && li[a[v]] == a[v])
        a[v]++;
}

ll pw(ll x, ll k) {
    ll r = 1;
    while (k) {
        if (k & 1)
            r = r * x % MOD;
        k >>= 1;
        x = x * x % MOD;
    }
    return r;
}

void subm(ll &x, ll y) {
    x -= y;
    if (x < 0)
        x += M2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, e, u, v;
    cin >> n >> e;
    rep(i, e) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }
    rep(i, n)
        if (!used[i])
            dfs(i);
    ll rn = pw(n + 1, MOD - 2), mx = 0;
    rep(i, n)
        mx = max(mx, a[i] + 1);
    ll p = 1;
    while (p < mx)
        p <<= 1;
    mx = p;
    rep(i, mx)
        m[i][i] = MOD - 1;
    m[0][mx] = rn;
    rep(i, n)
        rep(j, mx)
            m[j][j ^ a[i]] = (m[j][j ^ a[i]] + rn) % MOD;
    rep(i, mx) {
        int r = -1;
        for (int j = i; j < mx; j++)
            if (m[j][i] % MOD) {
                r = j;
                break;
            }
        assert(r != -1);
        rep(j, mx + 1) {
            swap(m[i][j], m[r][j]);
            m[i][j] %= MOD;
        }
        ll cr = pw(m[i][i], MOD - 2);
        rep(j, mx + 1)
            m[i][j] = m[i][j] * cr % MOD;
        rep(j, mx) {
            if (j == i)
                continue;
            ll mm = m[j][i] % MOD;
            for (int k = i; k < mx + 1; k++)
                subm(m[j][k], m[i][k] * mm);
        }
    }
    cout << (MOD + 1 + m[0][mx]) % MOD;
}