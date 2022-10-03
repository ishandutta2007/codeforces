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
const ll INF=1LL<<60;

//Union Find

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
    
    int N,M;cin>>N>>M;
    vector<pair<pair<int,int>,ll>> E(M);
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        E[i]=mp(mp(a,b),c);
    }
    
    sort(all(E),[](auto a,auto b){
        return a.se>b.se;
    });
    
    UF uf;uf.init(N);
    
    ll ans=0;
    
    for(auto e:E){
        int a=e.fi.fi,b=e.fi.se,c=e.se;
        if(uf.check(a,b)){
            int k=uf.root(a);
            if(uf.size[k]==uf.edge[k]) continue;
            uf.unite(a,b);
            ans+=c;
        }else{
            int k=uf.root(a),l=uf.root(b);
            if(uf.size[k]==uf.edge[k]&&uf.size[l]==uf.edge[l]) continue;
            uf.unite(a,b);
            ans+=c;
        }
    }
    
    cout<<ans<<endl;
}