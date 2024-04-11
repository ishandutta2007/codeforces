#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int MOD = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= MOD) return a - MOD;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) return a + MOD;
    return a;
}

int mul(int a, int b) {
    return (ll)a * b % MOD;
}

int binpow(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            ans = mul(ans, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return ans;
}

int inv(int a) {
    return binpow(a, MOD - 2);
}

const int N = 210;

int n;
vector<int> g[N];

int dp[N][N];

void precalc() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i < N; ++i) {
        dp[0][i] = 1;
        dp[i][0] = 0;
    }
    for (int len1 = 1; len1 < N; ++len1) {
        for (int len2 = 1; len2 < N; ++len2) {
            int val = 0;
            val = add(val, dp[len1 - 1][len2]);
            val = add(val, dp[len1][len2 - 1]);
            val = mul(val, inv(2));
            dp[len1][len2] = val;
        }
    }
}

const int LOG = 10;
int tin[N], tout[N], timer = 0;
int jump[N][LOG];
int h[N];

void dfs(int v, int p) {
    tin[v] = timer++;
    jump[v][0] = p;
    for (int i = 1; i < LOG; ++i) {
        jump[v][i] = jump[jump[v][i - 1]][i - 1];
    }
    for (auto i : g[v]) {
        if (i == p) continue;
        h[i] = h[v] + 1;
        dfs(i, v);
    }
    tout[v] = timer++;
}

bool isUpper(int v, int u) {
    return tin[v] <= tin[u] && tout[v] >= tout[u];
}

int lca(int u, int v) {
    if (isUpper(u, v)) return u;
    if (isUpper(v, u)) return v;
    for (int i = LOG - 1; i >= 0; --i) {
        if (!isUpper(jump[v][i], u)) {
            v = jump[v][i];
        }
    }
    return jump[v][0];
}

int dist(int u, int v) {
    return h[u] + h[v] - 2 * h[lca(u, v)];
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    precalc();
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for (int start = 0; start < n; ++start) {
        h[start] = 0;
        timer = 0;
        dfs(start, start);
        for (int less = 0; less < n; ++less) {
            for (int greater = less + 1; greater < n; ++greater) {
                int l = lca(less, greater);
                int len1 = dist(l, greater);
                int len2 = dist(l, less);
                ans = add(ans, dp[len1][len2]);
            }
        }
    }
    ans = mul(ans, inv(n));
    cout << ans << '\n';
    return 0;
}