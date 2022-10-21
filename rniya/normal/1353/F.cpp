#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=110,dx[2]={1,0},dy[2]={0,1};
const long long INF=1e18;

int n,m;
ll a[MAX_N][MAX_N],dp[MAX_N][MAX_N];

void solve(){
    ll ans=INF;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            ll s=a[i][j]-(i+j);
            if (s>a[0][0]) continue;
            for (int k=0;k<n;++k){
                for (int l=0;l<m;++l){
                    dp[k][l]=INF;
                }
            }
            dp[0][0]=a[0][0]-s;
            for (int k=0;k<n;++k){
                for (int l=0;l<m;++l){
                    for (int d=0;d<2;++d){
                        int nx=k+dx[d],ny=l+dy[d];
                        if (n<=nx||m<=ny) continue;
                        dp[nx][ny]=min(dp[nx][ny],dp[k][l]+(s+nx+ny>a[nx][ny]?INF:a[nx][ny]-(s+nx+ny)));
                    }
                }
            }
            ans=min(ans,dp[n-1][m-1]);
        }
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        cin >> n >> m;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                cin >> a[i][j];
        solve();
    }
}