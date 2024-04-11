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
const int mod=1000000007,MAX=200005,INF=1<<30;

struct edge{
    int a;
    int b;
    int c;
};

//Union Find

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
    
    void unite(int b,int a){
        if(root(a)!=root(b)){
            size[root(a)]+=size[root(b)];
            par[root(b)]=root(a);
        }
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
};

int cnte[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    int X=0;
    vector<edge> E(M);
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        if(a>b) swap(a,b);
        E[i]={a,b,c};
        X^=c;
    }
    
    sort(all(E),[](auto a,auto b){
        return a.b<b.b;
    });
    
    UF uf;uf.init(N);
    
    set<int> alive;
    
    int j=0;
    for(int i=0;i<N;i++){
        vector<int> hiku,kesu;
        while(j<si(E)&&E[j].b==i){
            cnte[uf.root(E[j].a)]++;
            hiku.push_back(uf.root(E[j].a));
            j++;
        }
        
        for(int r:alive){
            if(cnte[r]<uf.size[r]){
                kesu.push_back(r);
                uf.unite(r,i);
            }
        }
        
        for(int a:hiku) cnte[a]=0;
        
        for(int a:kesu){
            alive.erase(a);
        }
        alive.insert(i);
        
        //cout<<i<<" ";
        //for(int a:alive) cout<<a<<" ";
        //cout<<endl;
    }
    
    ll rem=ll(N)*(N-1)/2-M;
    
    sort(all(E),[](auto a,auto b){
        return a.c<b.c;
    });
    
    UF uf2;uf2.init(N);
    UF uf3;uf3.init(N);
    
    ll ans=0;
    int mi=INF;
    
    for(auto e:E){
        int a=uf.root(e.a),b=uf.root(e.b);
        if(!uf2.check(a,b)){
            ans+=e.c;
            uf2.unite(a,b);
            uf3.unite(e.a,e.b);
        }
    }
    
    for(auto e:E){
        if(!uf3.check(e.a,e.b)){
            chmin(mi,e.c);
        }
    }
    
    chmin(mi,X);
    
    if(rem==N-si(alive)){
        ans+=mi;
    }
    
    cout<<ans<<endl;
}