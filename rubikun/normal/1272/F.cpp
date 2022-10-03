#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=205,INF=1<<30;
int dp[MAX][MAX][MAX];
struct p{
    int s;
    int t;
    int diff;
};
p par[MAX][MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S,T;cin>>S>>T;
    int N=S.size();
    int M=T.size();
    S+='a';
    T+='a';
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            for(int k=0;k<MAX;k++){
                dp[i][j][k]=INF;
            }
        }
    }
    for(int k=0;k<=200;k++){
        dp[0][0][k]=k;
    }
    for(int i=0;i<=N;i++){
        for(int j=0;j<=M;j++){
            for(int k=0;k<=200;k++){
                if(S[i]=='('){
                    if(T[j]=='('){
                        if(dp[i+1][j+1][k+1]>dp[i][j][k]+1){
                            dp[i+1][j+1][k+1]=min(dp[i+1][j+1][k+1],dp[i][j][k]+1);
                            par[i+1][j+1][k+1]={i,j,k};
                        }
                    }else if(T[j]==')'){
                        if(dp[i+1][j][k+1]>dp[i][j][k]+1){
                            dp[i+1][j][k+1]=min(dp[i+1][j][k+1],dp[i][j][k]+1);
                            par[i+1][j][k+1]={i,j,k};
                        }
                        if(k-1>=0){
                            if(dp[i][j+1][k-1]>dp[i][j][k]+1){
                                dp[i][j+1][k-1]=min(dp[i][j+1][k-1],dp[i][j][k]+1);
                                par[i][j+1][k-1]={i,j,k};
                            }
                        }else{
                            if(dp[i][j+1][k]>dp[i][j][k]+2){
                                dp[i][j+1][k]=min(dp[i][j+1][k],dp[i][j][k]+2);
                                par[i][j+1][k]={i,j,k};
                            }
                        }
                    }else{
                        if(dp[i+1][j][k+1]>dp[i][j][k]+1){
                            dp[i+1][j][k+1]=min(dp[i+1][j][k+1],dp[i][j][k]+1);
                            par[i+1][j][k+1]={i,j,k};
                        }
                    }
                }else if(S[i]==')'){
                    if(T[j]=='('){
                        if(k-1>=0){
                            if(dp[i+1][j][k-1]>dp[i][j][k]+1){
                                dp[i+1][j][k-1]=min(dp[i+1][j][k-1],dp[i][j][k]+1);
                                par[i+1][j][k-1]={i,j,k};
                            }
                        }else{
                            if(dp[i+1][j][k]>dp[i][j][k]+2){
                                dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]+2);
                                par[i+1][j][k]={i,j,k};
                            }
                        }
                        if(dp[i][j+1][k+1]>dp[i][j][k]+1){
                            dp[i][j+1][k+1]=min(dp[i][j+1][k+1],dp[i][j][k]+1);
                            par[i][j+1][k+1]={i,j,k};
                        }
                    }else if(T[j]==')'){
                        if(k-1>=0){
                            if(dp[i+1][j+1][k-1]>dp[i][j][k]+1){
                                dp[i+1][j+1][k-1]=min(dp[i+1][j+1][k-1],dp[i][j][k]+1);
                                par[i+1][j+1][k-1]={i,j,k};
                            }
                        }else{
                            if(dp[i+1][j+1][k]>dp[i][j][k]+2){
                                dp[i+1][j+1][k]=min(dp[i+1][j+1][k],dp[i][j][k]+2);
                                par[i+1][j+1][k]={i,j,k};
                            }
                        }
                    }else{
                        if(k-1>=0){
                            if(dp[i+1][j][k-1]>dp[i][j][k]+1){
                                dp[i+1][j][k-1]=min(dp[i+1][j][k-1],dp[i][j][k]+1);
                                par[i+1][j][k-1]={i,j,k};
                            }
                        }else{
                            if(dp[i+1][j][k]>dp[i][j][k]+2){
                                dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]+2);
                                par[i+1][j][k]={i,j,k};
                            }
                        }
                    }
                }else{
                    if(T[j]=='('){
                        if(dp[i][j+1][k+1]>dp[i][j][k]+1){
                            dp[i][j+1][k+1]=min(dp[i][j+1][k+1],dp[i][j][k]+1);
                            par[i][j+1][k+1]={i,j,k};
                        }
                    }else if(T[j]==')'){
                        if(k-1>=0){
                            if(dp[i][j+1][k-1]>dp[i][j][k]+1){
                                dp[i][j+1][k-1]=min(dp[i][j+1][k-1],dp[i][j][k]+1);
                                par[i][j+1][k-1]={i,j,k};
                            }
                        }else{
                            if(dp[i][j+1][k]>dp[i][j][k]+2){
                                dp[i][j+1][k]=min(dp[i][j+1][k],dp[i][j][k]+2);
                                par[i][j+1][k]={i,j,k};
                            }
                        }
                    }
                }
            }
        }
    }
    
    int ans=INF,point=-1;
    for(int k=0;k<=200;k++){
        if(ans>dp[N][M][k]+k){
            ans=min(ans,dp[N][M][k]+k);
            point=k;
        }
    }
    
    string res;
    
    for(int i=0;i<point;i++) res+=')';
    
    int i=N,j=M,k=point;
    while(i>0||j>0){
        p from=par[i][j][k];
        int d=dp[i][j][k]-dp[from.s][from.t][from.diff];
        if(from.diff==k){
            for(int l=0;l<d/2;l++) res+=')';
            for(int l=0;l<d/2;l++) res+='(';
        }else if(from.diff+1==k){
            for(int l=0;l<(d-1)/2;l++) res+=')';
            for(int l=0;l<(d+1)/2;l++) res+='(';
        }else if(from.diff-1==k){
            for(int l=0;l<(d+1)/2;l++) res+=')';
            for(int l=0;l<(d-1)/2;l++) res+='(';
        }
        
        i=from.s;
        j=from.t;
        k=from.diff;
    }
    
    reverse(all(res));
    cout<<res<<endl;
}