#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
const int A = 1e6 + 13;
const int N = 2e5 + 13;
const int B = 400;
const int LOGN = 20;

mt19937 rnd(2);

int sum(int a, int b) {
    a += b;
    return (a < M ? a : a - M);
}

int ans[N];
int dp[N], ndp[N], s[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    dp[0] = 1;
    for(int i = 0; i < 700; i++) {
//    for(int i = 0; i < 5; i++) {
        for(int j = 0; j <= n; j++)
            s[j] = /*ndp[j] = */0;

        for(int j = 0; j < k + i; j++) {
            s[j] = dp[j];
            dp[j] = 0;
        }


        for(int j = k + i; j <= n; j++) {
            s[j] = sum(s[j - k - i], dp[j]);
            dp[j] = s[j - k - i];
            ans[j] = sum(ans[j], dp[j]);
//            cout << "add " << j << ' ' << dp[j] << endl;
        }

//        for(int j = 0; j <= n; j++)
//            cout << dp[j] << ' ';
//        cout << endl;
//        for(int j = 0; j <= n; j++)
//            cout << ans[j] << ' ';
//        cout << endl;
//        cout << endl;
    }

    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;


//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}