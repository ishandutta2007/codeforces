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

vector<int> G[MAX],rG[MAX];
int dis[MAX][2];

int V,cmp[MAX];
vector<int> vs;//vs
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

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    V=N;
    for(int i=0;i<N;i++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int x;cin>>x;
            x--;
            G[i].push_back(x);
            rG[x].push_back(i);
        }
    }
    int s;cin>>s;s--;
    
    for(int i=0;i<N;i++) dis[i][0]=dis[i][1]=INF;
    
    queue<pair<int,int>> Q;
    Q.push(mp(s,0));
    dis[s][0]=0;
    
    while(!Q.empty()){
        auto u=Q.front();Q.pop();
        for(int to:G[u.fi]){
            if(chmin(dis[to][u.se^1],dis[u.fi][u.se]+1)) Q.push(mp(to,u.se^1));
        }
    }
    
    for(int i=0;i<N;i++){
        if(si(G[i])==0&&dis[i][1]<INF){
            vector<int> ans;
            int now=i,f=1;
            while(1){
                ans.push_back(now);
                if(dis[now][f]==0) break;
                for(int from:rG[now]){
                    if(dis[from][f^1]+1==dis[now][f]){
                        now=from;
                        f^=1;
                        break;
                    }
                }
            }
            
            reverse(all(ans));
            
            cout<<"Win"<<endl;
            for(int a:ans) cout<<a+1<<" ";
            cout<<endl;
            
            return 0;
        }
    }
    
    int k=scc();
    
    vector<int> cnt(k);
    
    for(int i=0;i<N;i++) cnt[cmp[i]]++;
    
    for(int i=0;i<N;i++){
        if(min(dis[i][0],dis[i][1])<INF&&cnt[cmp[i]]>1){
            cout<<"Draw"<<endl;
            return 0;
        }
    }
    
    cout<<"Lose"<<endl;
    return 0;
}