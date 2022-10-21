#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

typedef long long ll;
const int N = (int)2e5 + 500;

int n;
int a1[N], a2[N];
ll dp[2][N], sdp[2][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a1[i];
    for(int i = 0; i < n; i++) cin >> a2[i];
    for(int i = n - 1; i >= 0; i--) {
        dp[0][i] = max(dp[0][i+1], dp[1][i+1] + a1[i]);
        dp[1][i] = max(dp[1][i+1], dp[0][i+1] + a2[i]);
    }
    cout << max(dp[0][0], dp[1][0]) << endl;

}