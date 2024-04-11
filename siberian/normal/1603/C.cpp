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

const int N = 1e5 + 10;
int n;
int a[N];
int curK[N];

int ans;

int get(int x, int k) {
    return (x + k - 1) / k;
}

int max(int a, int b) {
    return (a > b ? a : b);
}

int genNext(int x, int k) {
    return max(x / (x / k), k + 1);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        curK[i] = 1;
        int pos = i;
        while (pos > 0) {
            bool ok = false;
            int now = a[pos] / curK[pos];
            while ((a[pos - 1] + curK[pos - 1] - 1) / curK[pos - 1] > now) {
                int nxtK = genNext(a[pos - 1], curK[pos - 1]);
                ans += (ll)(nxtK - curK[pos - 1]) * (n - i) * pos % MOD;
                curK[pos - 1] = nxtK;
                ok = true;
            }
            if (!ok) break;
            --pos;
        }
    }
    cout << ans % MOD << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }    
    return 0;
}