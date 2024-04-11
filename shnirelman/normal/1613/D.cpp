#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 5e5 + 113;
const int M = 998244353;//1e9 + 7;
const int A = 26;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int pw2[N];

int a[N];
int dp1[N];
int dp2[N];

/*
1
3
0 2 1
*/

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i <= n + 3; i++) {
        dp1[i] = 0;
        dp2[i] = 0;
//        pw[i] = 0;
    }

    dp1[0] = 1;
//    int cur = 0;

    int ans = 0;
    for(int i = 0; i < n; i++) {
//        dp[a[i]] = mul(dp[a[i]], pw2[cur - pw[a[i]]);
//        pw[a[i]] = cur;

        ans = sum(ans, dp1[a[i]]);
        if(a[i] > 0) {
            ans = sum(ans, dp1[a[i] - 1]);
            ans = sum(ans, dp2[a[i] - 1]);
            dp2[a[i] - 1] = sum(mul(dp2[a[i] - 1], 2), dp1[a[i] - 1]);
        }

        ans = sum(ans, dp1[a[i] + 1]);
        ans = sum(ans, dp2[a[i] + 1]);

        dp1[a[i] + 1] = sum(mul(dp1[a[i] + 1], 2), dp1[a[i]]);
        dp2[a[i] + 1] = mul(dp2[a[i] + 1], 2);

//        cout << i << ' ' << ans << endl;
//        for(int j = 0; j <= n; j++)
//            cout << dp[j] << ' ';
//        cout << endl;
    }

    cout << ans << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    pw2[0] = 1;
    for(int i = 1; i < N; i++) {
        pw2[i] = mul(pw2[i - 1], 2);
    }

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}