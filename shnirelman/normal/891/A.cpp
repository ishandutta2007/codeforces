#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1)
            cnt++;
    }

    if(cnt > 0) {
        cout << n - cnt;
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        dp[i][i] = a[i];
    }

    for(int len = 1; len < n; len++) {
        for(int l = 0; l + len < n; l++) {
            int r = l + len;
            dp[l][r] = __gcd(dp[l][r - 1], a[r]);
            if(dp[l][r] == 1) {
                cout << n + len - 1;
                return 0;
            }
        }
    }

    cout << -1;
}