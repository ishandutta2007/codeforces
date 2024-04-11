#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18;
const ll INF=1000000000000;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;
    ll K;cin>>N>>K;
    string S;cin>>S;
    vector<vector<int>> pre(N,vector<int>(26,-1));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<26;j++){
            if(i) pre[i][j]=pre[i-1][j];
        }
        pre[i][S[i]-'a']=i;
    }
    
    ll dp[N][N+1];
    
    for(int i=0;i<N;i++){
        for(int j=0;j<=N;j++){
            dp[i][j]=0;
        }
    }
    
    for(int i=0;i<N;i++){
        dp[i][1]=1;
    }
    
    for(int j=2;j<=N;j++){
        for(int i=1;i<N;i++){
            for(int k=0;k<26;k++){
                if(pre[i-1][k]!=-1) dp[i][j]=min(INF,dp[i][j]+dp[pre[i-1][k]][j-1]);
            }
        }
    }
    
    ll ans=0;
    
    for(int j=N;j>=1;j--){
        ll sum=0;
        for(int i=0;i<26;i++){
            if(pre[N-1][i]!=-1) sum=min(INF,sum+dp[pre[N-1][i]][j]);
        }
        if(sum>=K){
            ans+=K*(N-j);
            K=0;
            break;
        }else{
            ans+=sum*(N-j);
            K-=sum;
        }
        //cout<<K<<endl;
    }
    if(K>=2) cout<<-1<<endl;
    else if(K==1) cout<<ans+N<<endl;
    else cout<<ans<<endl;
}