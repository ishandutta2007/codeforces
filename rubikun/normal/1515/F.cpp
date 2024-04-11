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
const int mod=1000000007,MAX=300005,INF=1<<30;

ll X;

set<pair<int,int>> G[MAX];

//Union Find

struct UF{
    int n;
    vector<int> par,size;
    vector<ll> sum;
    
    void init(int n_){
        n=n_;
        par.assign(n,-1);
        size.assign(n,1);
        sum.assign(n,0);
        
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int root(int a){
        if(par[a]==a) return a;
        else return par[a]=root(par[a]);
    }
    
    bool check(int a,int b){
        return root(a)==root(b);
    }
    
    void unite(int a,int b,bool f){
        a=root(a);
        b=root(b);
        if(a!=b){
            size[a]+=size[b];
            
            sum[a]+=sum[b];
            sum[a]-=X;
            
            if(!f){
                if(si(G[a])<si(G[b])){
                    for(auto e:G[a]){
                        if(!check(e.fi,b)&&root(e.fi)!=a){
                            G[b].insert(e);
                        }
                    }
                    swap(G[a],G[b]);
                }else{
                    for(auto e:G[b]){
                        if(!check(e.fi,a)&&root(e.fi)!=b){
                            G[a].insert(e);
                        }
                    }
                }
            }
            
            par[b]=a;
        }
    }
};

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    vector<int> ans;
    
    int N,M;cin>>N>>M>>X;
    set<pair<ll,int>> alive;
    vector<pair<int,int>> E(M);
    vector<int> usededge(M);
    
    UF uf;uf.init(N);
    
    for(int i=0;i<N;i++){
        ll a;cin>>a;
        uf.sum[i]=a;
        alive.insert(mp(-a,i));
    }
    
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].insert(mp(b,i));
        G[b].insert(mp(a,i));
        E[i]=mp(a,b);
    }
    
    while(si(alive)&&si(ans)<N-1){
        auto it=alive.begin();
        ll c=-(*it).fi;
        int u=(*it).se;
        if(c>=X){
            for(auto it=G[u].begin();it!=G[u].end();){
                auto to=*it;
                if(!uf.check(u,to.fi)){
                    alive.erase(mp(-uf.sum[uf.root(u)],uf.root(u)));
                    alive.erase(mp(-uf.sum[uf.root(to.fi)],uf.root(to.fi)));
                    
                    uf.unite(u,to.fi,0);
                    ans.push_back(to.se);
                    usededge[to.se]=true;
                    alive.insert(mp(-uf.sum[uf.root(u)],uf.root(u)));
                    
                    //cout<<u<<" "<<to.fi<<endl;
                    break;
                }else{
                    it=G[u].erase(it);
                }
            }
        }else{
            break;
        }
    }
    
    for(int i=0;i<M;i++){
        if(usededge[i]==false&&!uf.check(E[i].fi,E[i].se)){
            ll a=uf.sum[uf.root(E[i].fi)],b=uf.sum[uf.root(E[i].se)];
            if(a+b>=X){
                uf.unite(E[i].fi,E[i].se,1);
                usededge[i]=true;
                ans.push_back(i);
            }
        }
    }
    
    if(si(ans)==N-1){
        cout<<"YES\n";
        for(int i=0;i<N-1;i++) cout<<ans[i]+1<<"\n";
    }else{
        cout<<"NO\n";
    }
}