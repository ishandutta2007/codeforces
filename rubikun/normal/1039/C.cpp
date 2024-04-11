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
const int mod=1000000007,MAX=200005;
const ll INF=1000000000000000000LL;

struct UF{
    int n;
    vector<int> par,size;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

struct dat{
    ll ha;
    int l;
    int r;
};

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
    
    int N,M,K;cin>>N>>M>>K;
    vector<ll> X(N);
    for(int i=0;i<N;i++) cin>>X[i];
    vector<dat> S(M);
    set<ll> SE;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        if(a>b) swap(a,b);
        S[i]={X[a]^X[b],a,b};
        SE.insert(X[a]^X[b]);
    }
    
    sort(all(S),[](auto a,auto b){
        return a.ha<b.ha;
    });
    
    ll ans=0;
    
    ans+=(rui(2,K)+mod-si(SE))*rui(2,N)%mod;
    
    int id=0;
    
    UF uf;
    uf.init(N);
    
    while(id<M){
        int idto=id;
        int cnt=N;
        
        while(idto<M&&S[id].ha==S[idto].ha){
            if(!uf.check(S[idto].l,S[idto].r)){
                uf.unite(S[idto].l,S[idto].r);
                cnt--;
            }
            idto++;
        }
        
        ans+=rui(2,cnt);
        ans%=mod;
        
        while(id<idto){
            uf.par[S[id].l]=S[id].l;
            uf.par[S[id].r]=S[id].r;
            
            id++;
        }
    }
    
    cout<<ans<<endl;
    
}