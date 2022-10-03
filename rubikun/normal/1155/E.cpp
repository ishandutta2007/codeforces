#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000003,MAX=200001,INF=1<<30;

ll rui(ll a,ll b){
    if(b==1) return a%mod;
    else if(b==0) return 1;
    else if(b%2==0) return (rui(a,b/2)*rui(a,b/2))%mod;
    else return (rui(a,b-1)*a)%mod;
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    vector<ll> A(11),ans(11);
    for(int i=0;i<11;i++){
        cout<<"? "<<i<<endl;
        cin>>A[i];
    }
    
    for(int i=0;i<11;i++){
        vector<vector<ll>> dp(12,vector<ll>(11));
        
        dp[0][0]=1;
        for(int j=0;j<11;j++){
            if(i==j){
                for(int k=0;k<11;k++){
                    dp[j+1][k]=dp[j][k];
                }
            }else{
                ll b=i-j;
                b=(mod+abs(b)/b*rui(abs(b),mod-2))%mod;
                for(int k=0;k<10;k++){
                    dp[j+1][k+1]+=dp[j][k]*b;
                    dp[j+1][k]+=dp[j][k]*b*(mod-j);
                    
                    dp[j+1][k+1]%=mod;
                    dp[j+1][k]%=mod;
                }
            }
        }
        
        for(int k=0;k<11;k++){
            ans[k]+=A[i]*dp[11][k];
            ans[k]%=mod;
        }
    }
    
    ll x=-1;
    for(ll i=0;i<mod;i++){
        ll sum=0;
        for(int j=0;j<11;j++){
            sum+=ans[j]*rui(i,j);
            sum%=mod;
        }
        if(sum==0) x=i;
    }
    
    cout<<"! "<<x<<endl;
}