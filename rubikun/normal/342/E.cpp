#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define si(x) int(x.size())
#define double long double
const int mod=1000000007,MAX=200005,MAX_LOG=20,INF=1<<30;

struct edge{
    int to;
    int length;
};

int N,K,C=-1;
vector<edge> G[MAX];
vector<int> centree[MAX];

bool centroid[MAX];
int subtree_size[MAX];
int centpar[MAX];

int ans;

int compute_subtree_size(int u,int p){
    int c=1;
    for(auto a:G[u]){
        if(a.to==p||centroid[a.to]) continue;
        c+=compute_subtree_size(a.to,u);
    }
    return subtree_size[u]=c;
}

pair<int,int> search_centroid(int u,int p,int t){
    pair<int,int> res={INF,-1};
    int s=1,m=0;
    for(auto a:G[u]){
        if(a.to==p||centroid[a.to]) continue;
        
        res=min(res,search_centroid(a.to,u,t));
        
        m=max(m,subtree_size[a.to]);
        s+=subtree_size[a.to];
    }
    m=max(m,t-s);
    res=min(res,{m,u});
    return res;
}

void solve_subproblem(int u,int p){
    compute_subtree_size(u,-1);
    int s=search_centroid(u,-1,subtree_size[u]).second;
    centroid[s]=1;
    if(C==-1) C=s;
    if(p!=-1){
        centree[p].push_back(s);
        centpar[s]=p;
    }
    
    for(auto a:G[s]){
        if(centroid[a.to]){
            continue;
        }
        solve_subproblem(a.to,s);
    }
    
    centroid[s]=0;
}
int par[MAX_LOG][MAX],depth[MAX];
ll dis[MAX];

void BFS(int u){
    for(int i=0;i<N;i++){
        depth[i]=-1;
        dis[i]=0;
        for(int j=0;j<20;j++){
            par[j][i]=-1;
        }
    }
    queue<int> Q;
    Q.push(u);
    depth[u]=0;
    dis[u]=0;
    while(!Q.empty()){
        int a=Q.front();
        Q.pop();
        for(int i=0;i<G[a].size();i++){
            int b=G[a][i].to;
            ll c=G[a][i].length;
            if(depth[b]==-1){
                depth[b]=depth[a]+1;
                dis[b]=dis[a]+c;
                par[0][b]=a;
                Q.push(b);
            }
        }
    }
    return;
}

void init(){
    for(int k=0;k+1<MAX_LOG;k++){
        for(int i=0;i<N;i++){
            if(par[k][i]<0) par[k+1][i]=-1;
            else par[k+1][i]=par[k][par[k][i]];
        }
    }
}

int lca(int u,int v){
    if(depth[u]>depth[v]) swap(u,v);
    for(int i=0;i<20;i++){
        if(((depth[v]-depth[u])>>i)&1) v=par[i][v];
    }
    if(u==v) return u;
    
    for(int i=19;i>=0;i--){
        if(par[i][u]!=par[i][v]){
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}
//BFS(u)->init()

int mini[MAX];

void update(int u){
    int now=u;
    while(now!=-1){
        int x=lca(u,now);
        int y=dis[u]+dis[now]-2*dis[x];
        chmin(mini[now],y);
        now=centpar[now];
    }
}

int query(int u){
    int res=INF;
    int now=u;
    chmin(res,mini[u]);
    
    while(now!=-1){
        int x=lca(u,now);
        int y=dis[u]+dis[now]-2*dis[x];
        chmin(res,y+mini[now]);
        now=centpar[now];
    }
    
    return res;
}


int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>N>>Q;
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back({b,1});
        G[b].push_back({a,1});
    }
    memset(centpar,-1,sizeof(centpar));
    for(int i=0;i<N;i++) mini[i]=INF;
    
    solve_subproblem(0,-1);
    BFS(C);
    init();
    
    update(0);
    
    while(Q--){
        int k,x;cin>>k>>x;
        x--;
        if(k==1){
            update(x);
        }else{
            cout<<query(x)<<"\n";
        }
    }
}