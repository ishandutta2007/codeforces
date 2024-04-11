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
const int mod=1000000007,MAX=505,INF=1<<30;

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
    int from;
    int to;
    int id;
    int cost;
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M,Q;cin>>N>>M>>Q;
    vector<edge> S(M);
    for(int i=0;i<M;i++){
        cin>>S[i].from>>S[i].to>>S[i].cost;
        S[i].from--;
        S[i].to--;
        S[i].id=i;
    }
    sort(all(S),[](auto a,auto b){
        return a.cost>b.cost;
    });
    
    while(Q--){
        int l,r;cin>>l>>r;
        l--;r--;
        
        UF uf;
        uf.init(2*N);
        
        bool ok=true;
        
        for(int i=0;i<M;i++){
            if(S[i].id<l||r<S[i].id) continue;
            uf.unite(S[i].from,N+S[i].to);
            uf.unite(N+S[i].from,S[i].to);
            
            if(uf.check(S[i].from,N+S[i].from)){
                cout<<S[i].cost<<"\n";
                ok=false;
                break;
            }
        }
        
        if(ok) cout<<-1<<"\n";
    }
}