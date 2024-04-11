#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> x(n);
    for (int i=0;i<n;++i) cin >> x[i];
    sort(x.begin(),x.end());
    vector<vector<int>> dp0(n+1,vector<int>(1<<3,INF))
                        ,dp1(n+1,vector<int>(1<<3,-INF));
    dp0[0][0]=dp1[0][0]=0;
    for (int i=0;i<n;++i){
        for (int mask=0;mask<(1<<3);++mask){
            int nxt=mask;
            if (i&&x[i]-x[i-1]<3) nxt>>=(x[i]-x[i-1]);
            else nxt=0;
            for (int j=0;j<3;++j){
                if (nxt&1<<j){
                    dp0[i+1][nxt]=min(dp0[i+1][nxt],dp0[i][mask]);
                    dp1[i+1][nxt]=max(dp1[i+1][nxt],dp1[i][mask]);
                } else {
                    dp0[i+1][nxt|1<<j]=min(dp0[i+1][nxt|1<<j],dp0[i][mask]+1);
                    dp1[i+1][nxt|1<<j]=max(dp1[i+1][nxt|1<<j],dp1[i][mask]+1);
                }
            }
        }
    }
    int Min=INF,Max=0;
    for (int mask=0;mask<(1<<3);++mask){
        Min=min(Min,dp0[n][mask]);
        Max=max(Max,dp1[n][mask]);
    }
    cout << Min << ' ' << Max << '\n';
}