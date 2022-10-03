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
const int mod=998244353,MAX=400005,INF=1<<30;

int N;
vector<pair<int,ll>> G[MAX];
int siz[MAX];
ll dis[MAX];
vector<int> center;

void findcenter(int u,int p){
    siz[u]=1;
    bool ok=true;
    
    for(pair<int,ll> to:G[u]){
        if(to.first==p) continue;
        findcenter(to.first,u);
        if(siz[to.first]>N/2) ok=false;
        siz[u]+=siz[to.first];
    }
    
    if(N-siz[u]>N/2) ok=false;
    
    if(ok) center.push_back(u);
}

void BFS(int u){
    queue<int> Q;
    Q.push(u);
    
    while(!Q.empty()){
        int a=Q.front();Q.pop();
        for(pair<int,ll> to:G[a]){
            if(to.first==u) continue;
            if(dis[to.first]==0){
                dis[to.first]=dis[a]+to.second;
                Q.push(to.first);
            }
        }
    }
}

bool ans[MAX];

void make(int u,int p){
    siz[u]=1;
    for(auto to:G[u]){
        if(to.fi==p) continue;
        make(to.fi,u);
        siz[u]+=siz[to.fi];
    }
}

void solve(int u,int p,int ma){
    if(N-siz[u]-ma<=N/2) ans[u]=true;
    for(auto to:G[u]){
        if(to.fi==p) continue;
        solve(to.fi,u,ma);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;a--;b--;
        G[a].push_back(mp(b,1));
        G[b].push_back(mp(a,1));
    }
    findcenter(0,-1);
    
    if(si(center)==2){
        for(int i=0;i<N;i++) cout<<1<<" ";
        cout<<"\n";
        return 0;
    }
    
    memset(siz,0,sizeof(siz));
    
    int r=center[0];
    
    make(r,-1);
    
    ans[r]=true;
    
    vector<int> L={-INF};
    
    for(auto to:G[r]){
        L.push_back(siz[to.fi]);
    }
    L.push_back(-INF);
    
    vector<int> R=L;
    
    for(int i=1;i<si(L);i++) chmax(L[i],L[i-1]);
    for(int i=si(R)-2;i>=0;i--) chmax(R[i],R[i+1]);
    
    int t=1;
    for(auto to:G[r]){
        int x=max(L[t-1],R[t+1]);
        solve(to.fi,r,x);
        t++;
    }
    
    for(int i=0;i<N;i++) cout<<ans[i]<<" ";
    cout<<"\n";
}