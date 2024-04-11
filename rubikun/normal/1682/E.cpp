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
const int mod=998244353,MAX=200005,INF=1<<30;

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

vector<pair<int,int>> GG[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<int> P(N);
    for(int i=0;i<N;i++){
        cin>>P[i];P[i]--;
    }
    vector<pair<int,int>> E(M);
    V=M;
    for(int i=0;i<M;i++){
        cin>>E[i].fi>>E[i].se;
        E[i].fi--;E[i].se--;
        GG[E[i].fi].push_back(mp(E[i].se,i));
        GG[E[i].se].push_back(mp(E[i].fi,i));
    }
    
    vector<int> wh(N);
    
    vector<int> used(N);
    for(int i=0;i<N;i++){
        if(used[i]) continue;
        int now=i;
        vector<int> X;
        while(1){
            if(used[now]) break;
            X.push_back(now);
            wh[now]=si(X)-1;
            used[now]=true;
            now=P[now];
        }
        
        for(int j=0;j<si(X);j++){
            vector<pair<int,int>> Y;
            for(auto to:GG[X[j]]){
                int idx=wh[to.fi];
                if(idx<j) idx+=si(X);
                Y.push_back(mp(idx,to.se));
            }
            sort(all(Y));
            for(int k=0;k+1<si(Y);k++){
                add_edge(Y[k].se,Y[k+1].se);
            }
        }
    }
    
    scc();
    
    reverse(all(vs));
    
    for(int a:vs) cout<<a+1<<" ";
    cout<<endl;
}