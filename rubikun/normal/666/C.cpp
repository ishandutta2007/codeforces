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
const int mod=1000000007,MAX=200005,INF=1<<28;
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

ll perm(ll a,ll b){
    if(a<b) return 0;
    return fac[a]*finv[a-b]%mod;
}

ll rui[27][MAX];

vector<pair<ll,int>> T[MAX];
ll res[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    make();
    string S;cin>>S;
    
    rui[25][0]=rui[26][0]=1;
    for(int i=1;i<MAX;i++){
        rui[25][i]=rui[25][i-1]*25%mod;
        rui[26][i]=rui[26][i-1]*26%mod;
    }
    int now=si(S);
    int id=0;
    
    while(Q--){
        int t;cin>>t;
        if(t==1){
            cin>>S;
            now=si(S);
        }else{
            ll K;cin>>K;
            K-=now;
            T[now].push_back(mp(K,id));
            id++;
        }
    }
    
    for(int M=0;M<MAX;M++){
        sort(all(T[M]));
        ll ans=0;
        for(int j=0;j<si(T[M]);j++){
            if(j==0){
                ll K=T[M][j].fi;
                for(int i=0;i<=K;i++){
                    ans+=rui[25][i]*comb(i+M-1,i)%mod*rui[26][K-i]%mod;
                    ans%=mod;
                }
                res[T[M][j].se]=ans;
            }else{
                ans*=rui[26][T[M][j].fi-T[M][j-1].fi];
                ans%=mod;
                
                ll K=T[M][j].fi;
                for(int i=T[M][j-1].fi+1;i<=K;i++){
                    ans+=rui[25][i]*comb(i+M-1,i)%mod*rui[26][K-i]%mod;
                    ans%=mod;
                }
                res[T[M][j].se]=ans;
            }
        }
    }
    
    for(int i=0;i<id;i++) cout<<res[i]<<"\n";
}