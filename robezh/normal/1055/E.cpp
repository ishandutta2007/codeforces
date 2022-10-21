#include <bits/stdc++.h>
using namespace std;

const int N = 1505, INF = (int)1e9 + 500;
typedef pair<int, int> P;

int n,s,m,k;
int a[N], psum[N];
int dp[N][N];
int jp[N];
int l[N], r[N];

bool check(int val){
    for(int i = 1; i <= n; i++) psum[i] = (a[i] <= val) + psum[i-1];
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(dp[i][j] == -1) continue;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(jp[i] > 0) dp[jp[i]+1][j+1] = max(dp[jp[i]+1][j+1], dp[i][j] + psum[jp[i]] - psum[i-1]);
        }
    }
    return dp[n+1][m] >= k;
}

int main(){
    cin >> n >> s >> m >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= s; i++){
        cin >> l[i] >> r[i];
        for(int j = l[i]; j <= r[i]; j++) jp[j] = max(jp[j], r[i]);
    }

    int l = 0, r = INF, mid;
    while(l + 1 < r){
        mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << (r == INF ? -1 : r) << endl;
}