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

const int N = 2e5 + 10;

struct Portal{
    int x, y, s;
};

int n;
Portal a[N];
int coord[N];

int getCoord(int x) {
    return lower_bound(coord, coord + n, x) - coord;
}

int dp[N][2];

int pref[N];

int get(int l, int r) {
    // int ans = 0;
    // for (int i = l; i <= r; ++i) {
    //     ans = add(ans, dp[i][1]);
    // }
    // return ans;
    chkmax(l, 0);
    chkmin(r, n - 1);
    if (l > r) return 0;
    return sub(pref[r], (l > 0 ? pref[l - 1] : 0));
}

void calcDp() {
    for (int i = 0; i < n; ++i) {
        int dist = a[i].x - (i > 0 ? a[i - 1].x : 0);
        dist %= MOD;
        dp[i][0] = dist;

        int& fdp = dp[i][1];

        fdp = dist;
        int prev = getCoord(a[i].y);
        int val = coord[prev] - a[i].y;
        val %= MOD;
        fdp = add(fdp, val);

        if (prev != i) {
            fdp = sub(fdp, val);
            fdp = sub(fdp, (a[i].y - (prev > 0 ? a[prev - 1].x : 0)) % MOD);
            fdp = add(fdp, get(prev, i - 1));
            fdp = add(fdp, dist);
        }
        pref[i] = dp[i][1];
        if (i > 0) pref[i] = add(pref[i], pref[i - 1]);
    }
    // cerr << "dp = " << endl;
    // for (int i = 0; i < n; ++i) {
    //     cerr << dp[i][0] << " " << dp[i][1] << endl;
    // } 
}

int ans;

void calcAns() {
    ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = add(ans, dp[i][a[i].s]);
    }
    ans = add(ans, 1);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].s;
        coord[i] = a[i].x;
    }
    calcDp();
    calcAns();
    cout << ans << endl;
    return 0;
}