#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n), dp(n + 1);
    fill(dp.begin(), dp.end(), 1000000000);
    dp[0] = 0;
    for(auto &x : v)
        cin >> x;
    for(int i = 0; i < n; i++) {
        int x = v[i];
        int lo = 0, hi = n;
        while(lo < hi) {
            int mi = (lo + hi + 1)/2;
            if(dp[mi] < x)
                lo = mi;
            else
                hi = mi - 1;
        }
        dp[lo + 1] = min(dp[lo + 1], x);
    }
    for(int i = n; i >= 0; i--) {
        if(dp[i] <= n) {
            cout << i << endl;
            return 0;
        }
    }
}