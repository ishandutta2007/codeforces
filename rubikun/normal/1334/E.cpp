//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx2")  //Enable AVX
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=32000005,MAX2=105,INF=1<<30;
vector<int> prime;//i
bool is_prime[MAX+1];

void sieve(int n){
    for(int i=0;i<=n;i++){
        is_prime[i]=true;
    }
    
    is_prime[0]=is_prime[1]=false;
    
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            prime.push_back(i);
            for(int j=2*i;j<=n;j+=i){
                is_prime[j] = false;
            }
        }
    }
}

ll inv[MAX2],fac[MAX2],finv[MAX2];

void make(){
    
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    
    for(int i=2;i<MAX2;i++){
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        fac[i]=fac[i-1]*(ll)i%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
    
}

ll comb(ll a,ll b){
    if(a<b) return 0;
    return fac[a]*(finv[b]*finv[a-b]%mod)%mod;
}

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    make();
    sieve(MAX-2);
    ll N,M;cin>>N;
    M=N;
    int Q;cin>>Q;
    vector<ll> use,yaku;
    map<ll,ll> MA;
    
    for(ll p:prime){
        if(M%p==0){
            use.push_back(p);
            while(M%p==0) M/=p;
        }
    }
    if(M>1) use.push_back(M);
    
    M=N;
    
    for(ll i=1;i*i<=N;i++){
        if(N%i==0){
            yaku.push_back(i);
            if(i*i!=N) yaku.push_back(N/i);
        }
    }
    
    for(ll a:yaku){
        ll b=a;
        int su=0;
        vector<int> cnt;
        for(ll p:use){
            if(a%p==0){
                int c=0;
                while(a%p==0){
                    c++;
                    a/=p;
                }
                cnt.push_back(c);
                su+=c;
            }
        }
        
        ll an=1;
        for(int d:cnt){
            an*=comb(su,d);
            an%=mod;
            su-=d;
        }
        
        MA[b]=an;
    }
    
    while(Q--){
        ll a,b;cin>>a>>b;
        if(a>b) swap(a,b);
        
        ll g=gcd(a,b);
        a/=g;
        b/=g;
        
        cout<<MA[a]*MA[b]%mod<<"\n";
    }
}