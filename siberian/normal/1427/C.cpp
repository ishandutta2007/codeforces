#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int N = 1e5 + 10;
int r, n;
int t[N], x[N], y[N];

int dist(int a, int b) {
    return abs(x[a] - x[b]) + abs(y[a] - y[b]);
}

void read() {
    cin >> r >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> x[i] >> y[i];
    }
}

int dp[N];

void run() {
    int mx = -1e9;
    for (int i = 0; i < n; ++i) {
        dp[i] = 0;
        if (x[i] + y[i] - 2 <= t[i]) {
            dp[i] = 1;
        }
        chkmax(dp[i], mx + 1);
        for (int j = 1; i - j >= 0 && j <= 2 * r + 10; ++j) {
            if (t[i - j] + dist(i, i - j) <= t[i] && dp[i - j] > 0) {
                chkmax(dp[i], dp[i - j] + 1);
            }
        }
        if (i - 2 * r - 10 >= 0 && dp[i - 2 * r - 10] > 0) {
            chkmax(mx, dp[i - 2 * r - 10]);
        }
    }
}

void write() {
    cout << *max_element(dp, dp + n) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}