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


#define int ll
const int MOD = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
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

const int N = 2e5 + 10;

int n;
int a[N];

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    int ans = sub(binpow(2, n), 1);
    map<int, int> have;
    int even = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            ++even;
            // ans = sub(ans, 1);    
            int x = a[i];
            int cnt = 0;
            while (x % 2 == 0) {
                ++cnt;
                x /= 2;
            }   
            have[-cnt]++;
        }
    }

    int now = 0;
    for (auto i : have) {
        ans = sub(ans, mul(binpow(2, i.second - 1), binpow(2, now)));
        now += i.second;
    }
    // ans = sub(ans, binpow(2, even));
    // ans = add(ans, 1);
    
    // ans = sub(ans, fans);
    // cerr << "cnt1 = " << cnt1 << " cnt2 = " << cnt2 << endl;
    // ans = sub(ans, mul(cnt2, sub(binpow(2, cnt1), 1)));
    cout << ans << endl;

    return 0;
}