#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=200005,INF=1<<25;

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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    make();
    int N,M;cin>>N>>M;
    ll ans=0,sum=0;
    
    for(int j=1;j<=M;j++){
        sum+=comb(j-1,N-2);
        sum%=mod;
    }
    
    for(int i=2;i<=N-1;i++){
        ans+=sum*comb(N-3,i-2);
        ans%=mod;
    }
    
    ans*=(N-2);
    ans%=mod;
    
    cout<<ans<<endl;
}