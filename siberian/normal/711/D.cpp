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

const int MAXN = 2e5 + 10;
int pows[MAXN];

void build() {
    pows[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pows[i] = mul(2, pows[i - 1]);
    }
}

int n;
int a[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
}

int in[MAXN];

int ans;

int depth[MAXN];
int used[MAXN];
int cnt;

void dfs(int v) {
    used[v] = 1;
    if (!used[a[v]]) {
        depth[a[v]] = depth[v] + 1;
        dfs(a[v]);
    } else if (used[a[v]] == 1) {
        cnt -= depth[v] - depth[a[v]] + 1;
        ans = mul(ans, sub(pows[depth[v] - depth[a[v]] + 1], 2));
    }    
    used[v] = 2;
}

void run() {
    build();
    for (int i = 0; i < n; i++) {
        in[a[i]]++;
    }

    ans = 1;
    cnt = n;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        dfs(i);
    }
    ans = mul(ans, pows[cnt]);
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