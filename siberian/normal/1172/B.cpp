#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MOD = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a -= MOD;
    return a;
} 

int mul(int a, int b) {
    return (ll) a * b % MOD;
}

const int MAXN = 2e5 + 10;

int fact[MAXN];

void build() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
}

int n;
vector<int> g[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

int ans;
int dp[MAXN];
int cnt[MAXN];

void dfs(int v, int p) {
    cnt[v] = 0;
    for (auto i : g[v]) {
        if (i == p) continue;
        dfs(i, v);
        cnt[v]++;
    }

    dp[v] = fact[cnt[v]];

    for (auto i : g[v]) {
        if (i == p) continue;
        dp[v] = mul(dp[v], mul(dp[i], cnt[i] + 1));
    }
}

void run() {
    dfs(0, 0);
    ans = mul(dp[0], n);
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    build();
    read();
    run();
    write();
    return 0;
}