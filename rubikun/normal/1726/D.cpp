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
    
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    int Q;cin>>Q;
    while(Q--){
        int N,M;cin>>N>>M;
        vector<pair<int,int>> E(M);
        for(int i=0;i<M;i++){
            int a,b;cin>>a>>b;a--;b--;
            E[i]=mp(a,b);
        }
        vector<int> id(M);iota(all(id),0);
        
        while(1){
            for(int q=0;q<M;q++){
                int a=rng()%M,b=rng()%M;
                swap(id[a],id[b]);
            }
            UF uf;uf.init(N);
            vector<int> ok;
            vector<pair<int,int>> ng;
            for(int i=0;i<M;i++){
                int a=E[id[i]].fi,b=E[id[i]].se;
                if(a>b) swap(a,b);
                if(uf.check(a,b)){
                    ng.push_back(mp(a,b));
                }else{
                    uf.unite(a,b);
                    ok.push_back(id[i]);
                }
            }
            
            if(si(ng)==3){
                set<int> syu;
                for(int i=0;i<3;i++){
                    syu.insert(ng[i].fi);
                    syu.insert(ng[i].se);
                }
                if(si(syu)==3) continue;
            }
            
            string ans(M,'0');
            for(int a:ok) ans[a]='1';
            cout<<ans<<"\n";
            break;
        }
    }
}