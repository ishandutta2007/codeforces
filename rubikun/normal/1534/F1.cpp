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
const int mod=1000000007,MAX=400005,INF=1<<30;

int V,cmp[MAX];
vector<int> G[MAX],rG[MAX],vs;//vs
bool used[MAX];

void add_edge(int from,int to){
    //cout<<from<<" "<<to<<endl;
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
    
    int H,W;cin>>H>>W;
    V=H*W;
    
    vector<string> S(H);
    vector<set<int>> SE(W);
    
    for(int i=0;i<H;i++) cin>>S[i];
    
    for(int j=0;j<W;j++){
        for(int i=0;i<H;i++){
            if(S[i][j]=='#') SE[j].insert(i);
        }
    }
    
    int ans=0;
    
    for(int j=0;j<W;j++){
        for(int i=0;i<H;i++){
            if(S[i][j]=='.'){
                ans--;
                continue;
            }
            if(i&&S[i-1][j]=='#') add_edge(i*W+j,(i-1)*W+j);
            auto it=SE[j].upper_bound(i);
            if(it!=SE[j].end()){
                add_edge(i*W+j,(*it)*W+j);
            }
            
            if(j){
                auto it=SE[j-1].lower_bound(i);
                if(it!=SE[j-1].end()) add_edge(i*W+j,(*it)*W+j-1);
            }
            if(j+1<W){
                auto it=SE[j+1].lower_bound(i);
                if(it!=SE[j+1].end()) add_edge(i*W+j,(*it)*W+j+1);
            }
        }
    }
    
    int k=scc();
    vector<int> indeg(k);
    
    for(int i=0;i<H*W;i++){
        for(int to:G[i]){
            if(cmp[i]==cmp[to]) continue;
            indeg[cmp[to]]++;
        }
    }
    
    for(int i=0;i<k;i++) if(indeg[i]==0) ans++;
    
    cout<<ans<<endl;
}