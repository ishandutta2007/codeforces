#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

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
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) {
        a += MOD;
    }
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


const int N = 3e5 + 10;

int f[N], rf[N], p[N], invp[N];
int total2[N];

int cnk(int n, int k) {
    if (n < 0 || n < k) {
        return 0;
    } 
    // cerr << "n = " << n << " k = " << k << endl;
    return mul(f[n], mul(rf[k], rf[n - k]));
}

void build() {
    f[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = mul(f[i - 1], i);
    }
    rf[N - 1] = inv(f[N - 1]);
    for (int i = N - 1; i > 0; --i) {
        rf[i - 1] = mul(rf[i], i);
    }
    invp[0] = 1;
    p[0] = 1;
    int inv2 = inv(2);
    for (int i = 1; i < N; ++i) {
        p[i] = mul(p[i - 1], 2);
        invp[i] = mul(invp[i - 1], inv2);
    }
    total2[0] = 1;
    total2[1] = 1;
    total2[2] = 2;
    for (int n = 3; n < N; ++n) {
        total2[n] = add(total2[n - 1], mul(total2[n - 2], n - 1));
    }
}

int getTotal2(int n) {
    return total2[n];
}

void solve() {
    int n;
    cin >> n;
    int ans = 0;

    for (int cnt4 = 0; cnt4 * 4 <= n; ++cnt4) {
        int for4 = mul(cnk(n - cnt4 * 2, cnt4 * 2), mul(f[cnt4 * 2], rf[cnt4]));
        int cur_n = n - cnt4 * 4;
        int total2 = getTotal2(cur_n);
        ans = add(ans, mul(total2, for4));
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    build();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }   
    return 0;
}