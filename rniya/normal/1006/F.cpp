#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; ll K; cin >> n >> m >> K;
    vector<vector<ll>> a(n,vector<ll>(m));
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            cin >> a[i][j];
        }
    }
    vector<vector<map<ll,ll>>> dp0(n,vector<map<ll,ll>>(m))
                                ,dp1(n,vector<map<ll,ll>>(m));
    dp0[0][0][a[0][0]]=dp1[n-1][m-1][a[n-1][m-1]]=1;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (j>=n-1-i) continue;
            for (int k=0;k<2;++k){
                int nx=i+dx[k],ny=j+dy[k];
                if (n<=nx||m<=ny) continue;
                for (auto p:dp0[i][j]){
                    dp0[nx][ny][p.first^a[nx][ny]]+=p.second;
                }
            }
        }
    }
    for (int i=n-1;i>=0;--i){
        for (int j=m-1;j>=0;--j){
            if (j<=n-1-i) continue;
            for (int k=2;k<4;++k){
                int nx=i+dx[k],ny=j+dy[k];
                if (nx<0||ny<0) continue;
                for (auto p:dp1[i][j]){
                    dp1[nx][ny][p.first^a[nx][ny]]+=p.second;
                }
            }
        }
    }
    ll ans=0;
    for (int i=n-1;i>=0&&n-1-i<m;--i){
        ll nk=K^a[i][n-1-i];
        for (auto p:dp0[i][n-1-i]) ans+=p.second*dp1[i][n-1-i][nk^p.first];
    }
    cout << ans << '\n';
}