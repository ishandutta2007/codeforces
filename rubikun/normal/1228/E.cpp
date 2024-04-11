#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

ll rui(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

ll comb(ll a,ll b){
    ll ans=1;
    for(ll i=a;i>a-b;i--){
        ans=ans*i%mod;
    }
    for(ll i=1;i<=b;i++){
        ans=(ans*rui(i,mod-2))%mod;
    }
    return ans;
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    ll N,K;cin>>N>>K;
    ll ans=0;
    for(ll i=N;i>=1;i--){
        if((N-i)%2==0) ans+=((rui((rui(K,i)+mod-rui(K-1,i))%mod,N))*comb(N,i))%mod*rui(K-1,(N-i)*N);
        else ans+=((mod-rui((rui(K,i)+mod-rui(K-1,i))%mod,N))*comb(N,i))%mod*rui(K-1,(N-i)*N);
        ans%=mod;
    }
    cout<<ans<<endl;
}