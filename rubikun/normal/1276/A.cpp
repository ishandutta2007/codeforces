#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        string S;cin>>S;
        int N=int(S.size());
        vector<vector<int>> dp(N+1,vector<int>(5,INF));
        vector<vector<pair<int,int>>> par(N+1,vector<pair<int,int>>(5));
        dp[0][4]=0;
        
        for(int i=0;i<N;i++){
            if(S[i]=='n'){
                if(dp[i+1][1]>dp[i][0]) par[i+1][1]={i,0};
                dp[i+1][1]=min(dp[i+1][1],dp[i][0]);
            }else if(S[i]=='o'){
                if(dp[i+1][0]>dp[i][0]) par[i+1][0]={i,0};
                dp[i+1][0]=min(dp[i+1][0],dp[i][0]);
            }else if(S[i]=='t'){
                if(dp[i+1][2]>dp[i][0]) par[i+1][2]={i,0};
                dp[i+1][2]=min(dp[i+1][2],dp[i][0]);
            }else{
                if(dp[i+1][4]>dp[i][0]) par[i+1][4]={i,0};
                dp[i+1][4]=min(dp[i+1][4],dp[i][0]);
            }
            if(dp[i+1][0]>dp[i][0]+1) par[i+1][0]={i,0};
            dp[i+1][0]=min(dp[i+1][0],dp[i][0]+1);
            
            if(S[i]=='e'){
                if(dp[i+1][1]>dp[i][1]+1) par[i+1][1]={i,1};
                dp[i+1][1]=min(dp[i+1][1],dp[i][1]+1);
            }else if(S[i]=='t'){
                if(dp[i+1][2]>dp[i][1]) par[i+1][2]={i,1};
                dp[i+1][2]=min(dp[i+1][2],dp[i][1]);
            }else if(S[i]=='o'){
                if(dp[i+1][0]>dp[i][1]) par[i+1][0]={i,1};
                dp[i+1][0]=min(dp[i+1][0],dp[i][1]);
            }else{
                if(dp[i+1][4]>dp[i][1]) par[i+1][4]={i,1};
                dp[i+1][4]=min(dp[i+1][4],dp[i][1]);
            }
            if(dp[i+1][1]>dp[i][1]+1) par[i+1][1]={i,1};
            dp[i+1][1]=min(dp[i+1][1],dp[i][1]+1);
            
            if(S[i]=='w'){
                if(dp[i+1][3]>dp[i][2]) par[i+1][3]={i,2};
                dp[i+1][3]=min(dp[i+1][3],dp[i][2]);
            }else if(S[i]=='t'){
                if(dp[i+1][2]>dp[i][2]) par[i+1][2]={i,2};
                dp[i+1][2]=min(dp[i+1][2],dp[i][2]);
            }else if(S[i]=='o'){
                if(dp[i+1][0]>dp[i][2]) par[i+1][0]={i,2};
                dp[i+1][0]=min(dp[i+1][0],dp[i][2]);
            }else{
                if(dp[i+1][4]>dp[i][2]) par[i+1][4]={i,2};
                dp[i+1][4]=min(dp[i+1][4],dp[i][2]);
            }
            if(dp[i+1][2]>dp[i][2]+1) par[i+1][2]={i,2};
            dp[i+1][2]=min(dp[i+1][2],dp[i][2]+1);
            
            if(S[i]=='o'){
                if(dp[i+1][3]>dp[i][3]+1) par[i+1][3]={i,3};
                dp[i+1][3]=min(dp[i+1][3],dp[i][3]+1);
            }else if(S[i]=='t'){
                if(dp[i+1][2]>dp[i][3]) par[i+1][2]={i,3};
                dp[i+1][2]=min(dp[i+1][2],dp[i][3]);
            }else{
                if(dp[i+1][4]>dp[i][3]) par[i+1][4]={i,3};
                dp[i+1][4]=min(dp[i+1][4],dp[i][3]);
            }
            if(dp[i+1][3]>dp[i][3]+1) par[i+1][3]={i,3};
            dp[i+1][3]=min(dp[i+1][3],dp[i][3]+1);
            
            if(S[i]=='o'){
                if(dp[i+1][0]>dp[i][4]) par[i+1][0]={i,4};
                dp[i+1][0]=min(dp[i+1][0],dp[i][4]);
            }else if(S[i]=='t'){
                if(dp[i+1][2]>dp[i][4]) par[i+1][2]={i,4};
                dp[i+1][2]=min(dp[i+1][2],dp[i][4]);
            }else{
                if(dp[i+1][4]>dp[i][4]) par[i+1][4]={i,4};
                dp[i+1][4]=min(dp[i+1][4],dp[i][4]);
            }
            if(dp[i+1][4]>dp[i][4]+1) par[i+1][4]={i,4};
            dp[i+1][4]=min(dp[i+1][4],dp[i][4]+1);
        }
        
        int ans=INF,now=N,point=-1;
        
        /*for(int i=1;i<=N;i++){
            for(int j=0;j<5;j++){
                cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }*/
        for(int j=0;j<5;j++){
            if(ans>dp[N][j]) point=j;
            ans=min(ans,dp[N][j]);
        }
        vector<int> res;
        
        while(now>=1){
            int a=par[now][point].first,b=par[now][point].second;
            if(dp[a][b]!=dp[now][point]){
                res.push_back(now);
            }
            now=a;
            point=b;
        }
        
        cout<<ans<<endl;
        for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
        cout<<endl;
    }
}