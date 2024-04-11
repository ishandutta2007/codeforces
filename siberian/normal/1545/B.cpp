#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

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

const int N = 1e5 + 228;

int fact[N];
int rfact[N];

void init() {
    fact[0] = rfact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = mul(fact[i - 1], i);
        rfact[i] = inv(fact[i]);
    }
}

int cnk(int n, int k) {
    if (n < k || k < 0) return 0;
    return mul(fact[n], mul(rfact[n - k], rfact[k]));
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    int cntOdd = 0;
    for (int l = 0; l < n; ++l) {
        if (s[l] == '0') continue;
        int r = l;
        while (r < n && s[r] == '1') ++r;
        if ((r - l) & 1) cntOdd++;
        cnt += (r - l) / 2;
        l = r - 1;
    }
    int ans = cnk(n - cntOdd - cnt, cnt);
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    init();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}