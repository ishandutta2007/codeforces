#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=100003,INF=1<<30;

ll rui(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    ll N,M,A;cin>>N>>M>>A;
    vector<int> S(M);
    for(int i=0;i<M;i++) cin>>S[i];
    
    ll ans=rui(A,N-2*S[M-1]);
    
    for(int i=0;i<M;i++){
        ll haba;
        if(i==0) haba=S[i];
        else haba=S[i]-S[i-1];
        ans*=((rui(A,2*haba)-rui(A,haba)+mod)%mod*rui(2,mod-2)+rui(A,haba))%mod;
        ans%=mod;
    }
    
    cout<<ans<<endl;
}