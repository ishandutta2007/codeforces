#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=5005;
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


int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    make();
    int N;cin>>N;
    
    ll sum=0;
    
    for(int i=1;i<=2*N;i+=2){
        for(int p=0;p<=i;p++){
            int q=i-p;
            if(p>=q||p>N||q>N) continue;
            
            sum+=comb(p+q,q);
            sum+=mod-comb(p+q,q+1);
            
            sum%=mod;
            
        }
    }
    
    cout<<sum<<endl;
}