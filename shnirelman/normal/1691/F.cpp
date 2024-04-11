#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int K = 9;
const int M = 1e9 + 7;

int add(int a, int b) {
    a += b;
    return (a < M ? a : a - M);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int dif(int a, int b) {
    return add(a, M - b);
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

int f[N], inv[N];

int C(int n, int k) {
    if(k > n)
        return 0;
    else
        return mul(f[n], mul(inv[k], inv[n - k]));
}

int n, k;
vector<int> g[N];
int sz[N];
int cnt[N], sum[N];
int dp[N], res[N];


void dfs1(int v, int par) {
    sz[v] = 1;

    for(int u : g[v]) {
        if(u != par) {
            dfs1(u, v);

            sz[v] += sz[u];
            cnt[v] = dif(cnt[v], sum[u]);
            res[v] = add(res[v], res[u]);
        }
    }

    sum[v] = C(sz[v], k);
    cnt[v] = add(cnt[v], sum[v]);
    dp[v] = mul(cnt[v], sz[v]);
    res[v] = add(res[v], dp[v]);

//    cout << "dfs1 " << v << ' ' << sz[v] << ' ' << cnt[v] << ' ' << sum[v] << ' ' << dp[v] << ' ' << res[v] << endl;
}

int ans = 0;

void rehang(int v, int u) {
    int szv = sz[v];
    int szu = sz[u];
    int sumv = sum[v];
    int sumu = sum[u];
    int cntv = cnt[v];
    int cntu = cnt[u];
//    int dpv = dp[v];
//    int dpu = dp[u];
    int resv = res[v];
    int resu = res[u];

    sz[v] -= sz[u];
    sz[u] = n;

    sum[v] = C(sz[v], k);
    sum[u] = C(sz[u], k);



    cnt[v] = add(dif(cnt[v], sumv), add(sum[v], sumu));
    cnt[u] = add(dif(cnt[u], sumu), dif(sum[u], sum[v]));

    res[v] = add(dif(dif(res[v], resu), mul(cntv, szv)), mul(cnt[v], sz[v]));
    res[u] = add(dif(add(res[u], res[v]), mul(cntu, szu)), mul(cnt[u], sz[u]));
//    res[u] = add(res[u], mul(cnt));
//    res[u] = add(dif(res[u], cnt[u]), add(res[v], sum[v]));
}

void dfs2(int v, int par) {
    ans = add(ans, res[v]);
//    cout << "dfs2 " << v << ' ' << res[v] << ' ' << ans << endl;
//    cout << "dfs2 " << v << ' ' << sz[v] << ' ' << cnt[v] << ' ' << sum[v] << ' ' << dp[v] << ' ' << res[v] << endl;

    for(int u : g[v]) {
        if(u != par) {
//            sz[v] -= sz[u];
//            sz[u] = n;
//            sum[v] = C(sz[v], k);
            rehang(v, u);
            dfs2(u, v);
            rehang(u, v);
//            cout << "dfs2 for " << v << ' ' << sz[v] << ' ' << cnt[v] << ' ' << sum[v] << ' ' << dp[v] << ' ' << res[v] << endl;
//            sz[u] -= sz[v];
//            sz[v] = n;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    f[0] = inv[0] = 1;
    for(int i = 1; i < N; i++) {
        f[i] = mul(f[i - 1], i);
        inv[i] = pow2(f[i], M - 2);
    }

//    cout << C(3, 2) << endl;

    cin >> n >> k;

    for(int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs1(0, -1);
    dfs2(0, -1);

    cout << ans << endl;
}