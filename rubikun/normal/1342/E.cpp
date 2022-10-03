#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
const int mod=998244353,MAX=400005;
const ll INF=1LL<<59;

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
    ll N,K;cin>>N>>K;
    if(K>N-1){
        cout<<0<<endl;
        return 0;
    }
    if(K==0){
        cout<<fac[N]<<endl;
        return 0;
    }
    
    ll M=N-K;
    ll ans=2;
    ans*=comb(N,M);
    ans%=mod;
    
    ll sum=0;
    
    for(ll i=0;i<=M;i++){
        if((M-i)%2==0) sum+=comb(M,i)*rui(i,N);
        else sum+=mod-(comb(M,i)*rui(i,N))%mod;
        sum%=mod;
    }
    
    ans*=sum;
    ans%=mod;
    
    cout<<ans<<endl;
}