#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int MOD = 1e9 + 7;

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

const int N = 5e3 + 10;
int n, k, q;
int a[N];

void read() {
    cin >> n >> k >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

int dp[N][N];
int ans = 0;
int cnt[N];

void build() {
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 1; 
    }
    for (int moves = 1; moves <= k; ++moves) {
        for (int i = 0; i < n; ++i) {
            dp[i][moves] = 0;
            if (i > 0) dp[i][moves] = add(dp[i][moves], dp[i - 1][moves - 1]);
            if (i + 1 < n) dp[i][moves] = add(dp[i][moves], dp[i + 1][moves - 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        cnt[i] = 0;
        for (int pref = 0; pref <= k; ++pref) {
            cnt[i] = add(cnt[i], mul(dp[i][pref], dp[i][k - pref]));
        }
        ans = add(ans, mul(cnt[i], a[i]));
    }
}

void makeAns(int i, int x) {
    ans = sub(ans, mul(cnt[i], a[i]));
    a[i] = x;
    ans = add(ans, mul(cnt[i], a[i]));
}

void solve() {
    int pos, x;
    cin >> pos >> x;
    --pos;
    makeAns(pos, x);
    cout << ans << '\n';
}

void run() {
    build();
        for (int i = 0; i < q; ++i) {
        solve();
    }
}

void write() {

}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}