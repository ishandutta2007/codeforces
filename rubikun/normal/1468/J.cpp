#include "bits/stdc++.h"
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a,const T &b) { if(a<b) { a=b;return true;} return false;}
template<class T>bool chmin(T &a,const T &b) { if(b<a) { a=b;return true;} return false;}
#define mp make_pair
#define fi first
#define se second
#define si(x) int(x.size())
#define all(x) (x).begin(),(x).end()
const ll INF=1LL<<60;

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

struct edge{
    int a;
    int b;
    ll cost;
};

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;
        ll K;cin>>N>>M>>K;
        ll ans=INF;
        
        vector<edge> A,B;
        
        for(int i=0;i<M;i++){
            int a,b,c;cin>>a>>b>>c;
            a--;b--;
            if(c<K) A.push_back({a,b,c});
            else B.push_back({a,b,c});
        }
        
        UF uf;
        uf.init(N);
        
        sort(all(A),[](auto a,auto b){
            return a.cost>b.cost;
        });
        
        sort(all(B),[](auto a,auto b){
            return a.cost<b.cost;
        });
        
        for(auto e:A){
            uf.unite(e.a,e.b);
        }
        
        if(uf.size[uf.root(0)]==N){
            chmin(ans,K-A[0].cost);
            if(si(B)) chmin(ans,B[0].cost-K);
        }else{
            ll sum=0;
            for(auto e:B){
                if(!uf.check(e.a,e.b)){
                    uf.unite(e.a,e.b);
                    sum+=e.cost-K;
                }
            }
            ans=sum;
        }
        
        cout<<ans<<"\n";
    }
}