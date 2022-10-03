#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000009,MAX=200005,INF=1<<30;

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
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,A,B,K;cin>>N>>A>>B>>K;
    ll revA=rui(A,mod-2),revB=rui(B,mod-2);
    
    string S;cin>>S;
    
    ll sum=0,now=rui(A,N);
    
    for(int i=0;i<K;i++){
        if(S[i]=='+') sum+=now;
        else sum+=mod-now%mod;
        sum%=mod;
        
        now*=revA;
        now%=mod;
        now*=B;
        now%=mod;
    }
    
    ll ans=0,L=(N+1)/K,r=rui((B*revA%mod),K);
    
    if(A==B||rui(r,L)==1){
        ans+=L*sum;
        ans%=mod;
    }else{
        ans+=sum*((mod+rui(r,L)-1)%mod)%mod*rui((mod+r-1)%mod,mod-2)%mod;
        ans%=mod;
    }
    
    cout<<ans<<endl;
}