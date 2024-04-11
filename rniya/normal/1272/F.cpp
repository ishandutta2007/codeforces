#include <bits/stdc++.h>
using namespace std;
const int MAX_S=210,INF=1e9;

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;} return false;
}

int dp[MAX_S][MAX_S][MAX_S];
vector<int> pre[MAX_S][MAX_S][MAX_S];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S,T; cin >> S >> T;
    int n=S.size(),m=T.size();
    S+='$',T+='$';
    for (int i=0;i<=n;++i)
        for (int j=0;j<=m;++j)
            for (int k=0;k<MAX_S;++k)
                dp[i][j][k]=INF;
    dp[0][0][0]=0;
    for (int i=0;i<=n;++i){
        for (int j=0;j<=m;++j){
            for (int k=0;k<MAX_S-1;++k){
                int ni=i+(S[i]=='('),nj=j+(T[j]=='(');
                if (chmin(dp[ni][nj][k+1],dp[i][j][k]+1))
                    pre[ni][nj][k+1]={i,j,k};
            }
            for (int k=MAX_S-1;k>0;--k){
                int ni=i+(S[i]==')'),nj=j+(T[j]==')');
                if (chmin(dp[ni][nj][k-1],dp[i][j][k]+1))
                    pre[ni][nj][k-1]={i,j,k};
            }
        }
    }
    string ans="";
    int i=n,j=m,k=0;
    while(i||j||k){
        int pi=pre[i][j][k][0],pj=pre[i][j][k][1],pk=pre[i][j][k][2];
        ans+=(k-pk==1?'(':')');
        i=pi,j=pj,k=pk;
    }
    reverse(ans.begin(),ans.end());
    cout << ans << '\n';
}