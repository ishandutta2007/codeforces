#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MOD = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += MOD;
    return a;
}

int mul(int a, int b) {
    return (ll) a * b % MOD;
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

int n, m, k;

void read() {
    cin >> n >> m >> k;
}

const int MAXN = 2010;
vector<int> g[MAXN];
bool used[MAXN];

void dfs(int v) {
    used[v] = true;
    for (auto i : g[v]) {
        if (used[i]) continue;
        dfs(i);
    }
}

void build() {
    for (int i = 0; i + k - 1 < n; i++) {
        for (int j = k - 1; j > 0; j -= 2) {
            if (i + j >= n) continue;
            g[i].push_back(i + j);
            g[i + j].push_back(i);
        }
    }
}

int ans = 0;

void run() {
    build();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        dfs(i);
        cnt++;
    }
    ans = binpow(m, cnt);
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}