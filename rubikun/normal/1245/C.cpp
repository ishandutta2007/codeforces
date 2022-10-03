#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    string S;cin>>S;
    int N=int(S.size());
    
    ll ans=1;
    
    vector<ll> dp(100005,0);
    dp[0]=1;dp[1]=1;dp[2]=2;
    
    for(int i=3;i<=100000;i++){
        dp[i]=dp[i-2]+dp[i-1];
        dp[i]%=mod;
    }
    
    int cnt=0,i=0;
    
    while(i<N){
        if(S[i]=='u'){
            while(i<N&&S[i]=='u'){
                i++;
                cnt++;
            }
            ans*=dp[cnt];
            ans%=mod;
            cnt=0;
        }else if(S[i]=='n'){
            while(i<N&&S[i]=='n'){
                i++;
                cnt++;
            }
            ans*=dp[cnt];
            ans%=mod;
            cnt=0;
        }else if(S[i]=='m'||S[i]=='w'){
            ans=0;
            break;
        }else i++;
    }
    
    cout<<ans<<endl;
    
    
    
}