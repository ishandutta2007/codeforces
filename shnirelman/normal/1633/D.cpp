#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1000 + 13;
const int LOGN = 30;
const int K = 22;
const int M = 1e9 + 7;
const int A = 26;
const ld eps = 1e-15;

mt19937 rnd(45768);

/*
*/

int res[N];
int b[N], c[N];
int dp[N * 12];

void solve() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        b[i] = res[x];
    }

    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }

    if(n * 12 <= k) {
        li sum = 0;
        for(int i = 0; i < n; i++)
            sum += c[i];

        cout << sum << endl;
        return;
    }

    for(int i = 0; i <= k; i++)
        dp[i] = 0;

//    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = k - b[i]; j >= 0; j--) {
            dp[j + b[i]] = max(dp[j + b[i]], dp[j] + c[i]);
        }
    }

    int mx = 0;
    for(int i = 0; i <= k; i++)
        mx = max(mx, dp[i]);

    cout << mx << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < N; i++)
        res[i] = INF;

    res[1] = 0;
    for(int i = 1; i < N; i++) {
        for(int x = 1; x <= i; x++) {
            res[i + i / x] = min(res[i + i / x], res[i] + 1);
        }
    }

//    int mx = 0;
//    for(int i = 1; i < N; i++) {
//        cout << i << ' ' << res[i] << endl;
//        mx = max(mx, res[i]);
//    }
//    cout << mx << endl;

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}