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

const int MOD = 998244353;

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

int getInv(int a) {
    return binpow(a, MOD - 2);
}

const int N = 30, M = 5e4 + 10;

int fact[N];

void precalc() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = mul(fact[i - 1], i);
    }
}

int n, m;
int d[N][M];

int cnt[N];

int calc(int pos) {
    fill(cnt, cnt + N, 0);
    for (int i = 0; i < n; ++i) {
        int dist = d[i][pos];
        cnt[n - dist + 1]++;
    }
    int cur = 0;
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        cur = add(cur, cnt[i]);
        ans = mul(ans, cur);
        cur = sub(cur, 1);
    }
    return sub(fact[n], ans);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    precalc();
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> d[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        ans = add(ans, calc(i));
    }
    ans = mul(ans, getInv(fact[n]));
    cout << ans << endl;
    return 0;
}