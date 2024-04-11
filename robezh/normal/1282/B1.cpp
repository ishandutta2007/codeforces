#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;
typedef long long ll;
const ll INF = (ll)1e18;

int n, p, k;
int a[N];
ll gsum[N];
ll psum[N];
ll dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {

        cin >> n >> p >> k;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++) {
            psum[i] = psum[i-1] + a[i];
            gsum[i] = a[i] + (i - k >= 0 ? gsum[i - k] : 0);
        }
        fill(dp, dp + n + 1, -INF);
        dp[0] = p;
        int res = 0;
        for(int i = 1; i <= n; i++) {
            dp[i] = max(dp[i], dp[i-1] - a[i]);
            if(i >= k) dp[i] = max(dp[i], dp[i-k] - a[i]);
            if(dp[i] >= 0) res = max(res, i);
        }
        cout << res << '\n';
    }

}