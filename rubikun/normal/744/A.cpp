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
const int mod=998244353,MAX=300005,INF=1<<30;

struct UF{
    int n;
    vector<int> par,size,edge;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        edge.assign(n,0);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    void unite(int a,int b){
        edge[root(a)]++;
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            edge[root(a)]+=edge[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,K;cin>>N>>M>>K;
    vector<int> S(K);
    for(int i=0;i<K;i++){
        int x;cin>>x;x--;
        S[i]=x;
    }
    UF uf;uf.init(N);
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;a--;b--;
        uf.unite(a,b);
    }
    vector<int> sz(K);
    int rem=N;
    for(int i=0;i<K;i++){
        sz[i]=uf.size[uf.root(S[i])];
        rem-=sz[i];
    }
    sort(all(sz));
    sz.back()+=rem;
    ll ans=-M;
    
    for(ll x:sz){
        ans+=x*(x-1)/2;
    }
    
    cout<<ans<<endl;
}