#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=400005,INF=1<<30;

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
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    
    vector<ll> to;
    
    if(N<=4){
        for(int i=0;i<N;i++) to.push_back(A[i]);
    }
    
    int M=(N-1)/4;
    
    ll cnt=0;
    
    if(N>=5){
        for(int i=0;i+M*4<N;i++){
            ll sum=0;
            for(int j=0;j<=M*2;j++){
                sum+=A[i+2*j]*comb(M*2,j)%mod;
                sum%=mod;
            }
            to.push_back(sum);
        }
    }
    
    if(si(to)==1) cout<<to[0]<<endl;
    if(si(to)==2) cout<<(to[0]+to[1])%mod<<endl;
    if(si(to)==3) cout<<(to[0]+2*to[1]+mod-to[2])%mod<<endl;
    if(si(to)==4) cout<<(to[0]-to[1]+to[2]-to[3]+2*mod)%mod<<endl;
}