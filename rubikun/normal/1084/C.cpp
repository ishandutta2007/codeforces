#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=10003,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    string S;cin>>S;
    int N=int(S.size());
    
    ll dp[N+1],sum=0,presum=0;
    dp[0]=0;
    
    for(int i=0;i<=N;i++){
        dp[i]=0;
    }
    
    for(int i=0;i<N;i++){
        if(S[i]=='a'){
            dp[i+1]=sum+1;
            presum+=dp[i+1];
            presum%=mod;
        }else if(S[i]=='b'){
            sum=presum;
        }
    }
    
    ll ans=0;
    
    for(int i=0;i<=N;i++){
        ans+=dp[i];
        if(ans>=mod) ans%=mod;
        //cout<<ans<<endl;
    }
    
    cout<<ans<<endl;
}