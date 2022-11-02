#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int MOD = 998244353;

int add(int a, int b) {
    a += b;
    a %= MOD;
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

const int N = 200200;
int n, m;
int d[N];
int a[N], b[N];
int pref[N];

void read() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    sort(d, d + n);
    for (int i = 0; i < n; ++i) {
        pref[i] = d[i];
        if (i > 0) {
            pref[i] = add(pref[i], pref[i - 1]);
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
    }
}

int get(int l, int r) {
    if (r < l) return 0;
    return sub(pref[r], l > 0 ? pref[l - 1] : 0);
}

int stupidSolve(int a, int b) {
    int suff = d + n - lower_bound(d, d + n, b);
   // cout << "suff = " << suff << endl;
    if (suff < a) return 0;
    int ans = 0;
    int prefSum = get(0, n - suff - 1);
    /*for (int i = 0; i + suff < n; ++i) {
        prefSum = add(prefSum, d[i]);
    }*/
    int suffSum = get(n - suff, n - 1);
    /*for (int i = n - suff; i < n; ++i) {
        suffSum = add(suffSum, d[i]);
    }*/
   // cout << "prefSum = " << prefSum << " suffSum = " << suffSum << endl;
    ans = add(ans, mul(suffSum, mul(suff - a, getInv(suff))));
    ans = add(ans, mul(prefSum, mul(suff - a + 1, getInv(suff + 1))));
    return ans;
}

int ans[N];

void run() {
    for (int i = 0; i < m; ++i) {
        ans[i] = stupidSolve(a[i], b[i]);
        //ans[i] = mul(ans[i], rfact[n]);
    }
}

void write() {
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}