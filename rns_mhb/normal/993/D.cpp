#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const ll INF = 1ll << 50;

#define N 55
#define M 5050

ll dp[N][M][N];
pii a[N];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i].first;
    for(int i = 1; i <= n; i ++) cin >> a[i].second;
    sort(a+1, a+n+1, greater <pii> ());
    for(int i = 0; i < N; i ++) for(int j = 0; j < M; j ++) for(int k = 0; k < N; k ++) dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    for(int l = 1, r = 1; l <= n; l = r) {
        while(r <= n && a[l].first == a[r].first) r ++;
        int sb = 0;
        ll sa = 0;
        for(int i = l; i <= r; i ++) {
            int x = i-l, y = r-i;
            for(int s = 0; s+sb < M; s ++) for(int z = y; z < l; z ++) {
                dp[r-1][s+sb][z-y+x] = min(dp[r-1][s+sb][z-y+x], dp[l-1][s][z]+sa);
            }
            if(i < r) sa += a[i].first, sb += a[i].second;
        }
    }
    long long ans = INF * 1001;
    for(int i = 1; i < M; i ++) for(int j = 0; j <= n; j ++) {
        ans = min(ans, ll((dp[n][i][j] * 1000 + i-1) / i));
    }
    cout << ans << endl;
}