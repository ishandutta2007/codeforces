#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAXN = 1e5 + 10;
ll a[2][MAXN], dp[2][MAXN];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[0][i];
    for(int i = 0; i < n; i++)
        cin >> a[1][i];
    for(int i = n - 1; i >= 0; i--) {
        dp[0][i] = max(dp[0][i + 1], a[0][i] + dp[1][i + 1]);
        dp[1][i] = max(dp[1][i + 1], a[1][i] + dp[0][i + 1]);
    }
    cout << max(dp[0][0], dp[1][0]) << '\n';
}