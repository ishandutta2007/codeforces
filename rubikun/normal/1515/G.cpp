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

//

int V,cmp[MAX];
vector<int> G[MAX],rG[MAX],vs;//vs
bool used[MAX];

void add_edge(int from,int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}

void add_clause(int i,bool f,int j,bool g){
    add_edge(2*i+(!f),2*j+g);
    add_edge(2*j+(!g),2*i+f);
}

void DFS(int v){
    used[v]=1;
    for(int i=0;i<G[v].size();i++){
        if(used[G[v][i]]==0) DFS(G[v][i]);
    }
    vs.push_back(v);
}

void rDFS(int v,int k){
    used[v]=1;
    cmp[v]=k;
    for(int i=0;i<rG[v].size();i++){
        if(used[rG[v][i]]==0) rDFS(rG[v][i],k);
    }
}

int scc(){
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=0;v<V;v++){
        if(used[v]==0) DFS(v);
    }
    
    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1;i>=0;i--){
        if(used[vs[i]]==0) rDFS(vs[i],k++);
    }
    return k;
}

vector<pair<int,ll>> G2[MAX];

ll g=0;

bool seen[MAX];
ll dis[MAX];

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

void DFS2(int u){
    for(auto to:G2[u]){
        if(seen[to.fi]){
            ll x=dis[u]+to.se,y=dis[to.fi];
            ll d=x-y;
            g=gcd(g,d);
        }else{
            seen[to.fi]=true;
            dis[to.fi]=dis[u]+to.se;
            DFS2(to.fi);
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<pair<pair<int,int>,int>> E(M);
    
    V=N;
    
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        add_edge(a,b);
        E[i]=mp(mp(a,b),c);
    }
    
    int K=scc();
    
    for(int i=0;i<M;i++){
        if(cmp[E[i].fi.fi]==cmp[E[i].fi.se]){
            G2[E[i].fi.fi].push_back(mp(E[i].fi.se,E[i].se));
        }
    }
    
    vector<ll> syuu(K);
    
    for(int i=0;i<N;i++){
        if(seen[i]) continue;
        seen[i]=true;
        g=0;
        DFS2(i);
        
        syuu[cmp[i]]=g;
    }
    
    int Q;cin>>Q;
    while(Q--){
        int v,s,t;cin>>v>>s>>t;
        v--;
        ll x=syuu[cmp[v]];
        ll y=gcd(gcd(s,t),x);
        s/=y;
        t/=y;
        x/=y;
        
        if(s==0){
            cout<<"YES\n";
        }else{
            if(gcd(x,t)==1){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }
}