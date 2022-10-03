#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=5003,INF=1<<30;

int V,cmp[MAX];
vector<int> G[MAX],rG[MAX],vs;
bool used[MAX];

void add_edge(int from,int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}

void delete_edge(int from,int to){
    G[from].pop_back();
    rG[to].pop_back();
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
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    cin>>V;
    int M;cin>>M;
    bool ok=true;
    vector<int> ans(M);
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        add_edge(a,b);
        int c=scc();
        if(c==V) ans[i]=1;
        else{
            delete_edge(a,b);
            ok=false;
            ans[i]=2;
        }
    }
    if(ok) cout<<1<<endl;
    else cout<<2<<endl;
    
    for(int i=0;i<M;i++){
        if(i) cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;
}