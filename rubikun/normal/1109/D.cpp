#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2000005,INF=1<<30;

ll inv[MAX],fac[MAX],finv[MAX];

void make(){
    
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    
    for(int i=2;i<MAX;i++){
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        fac[i]=fac[i-1]*(ll)i%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
    
}

ll comb(ll a,ll b){
    if(a<b) return 0;
    return fac[a]*(finv[b]*finv[a-b]%mod)%mod;
}

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
    
    make();
    ll N,M,A,B;cin>>N>>M>>A>>B;
    
    ll ans=0;
    
    for(ll i=2;i<=N;i++){
        ll s;
        
        s=fac[N-2];
        s%=mod;
        
        s*=rui(fac[N-i],mod-2);
        s%=mod;
        
        if(i!=N) s*=(i*rui(N,N-i-1))%mod;
        s%=mod;
        
        s*=rui(M,N-i);
        s%=mod;
        
        s*=comb(M-1,i-2);
        s%=mod;
        
        ans+=s;
        ans%=mod;
        
        //cout<<s<<endl;
    }
    
    cout<<ans<<endl;
}