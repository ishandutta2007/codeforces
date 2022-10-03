#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2005,INF=1<<30;
int V,cmp[MAX];
vector<int> G[MAX],rG[MAX],vs;//vs
bool used[MAX];

void add_edge(int from,int to){
    G[from].push_back(to);
    rG[to].push_back(from);
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
    int k=1;
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
    V=N+M;
    vector<string> S(N),T(M);
    for(int i=0;i<N;i++){
        cin>>S[i];
        for(int j=0;j<M;j++){
            if(S[i][j]=='<'){
                add_edge(i,N+j);
            }else if(S[i][j]=='>'){
                add_edge(N+j,i);
            }else{
                add_edge(i,N+j);
                add_edge(N+j,i);
            }
        }
    }
    for(int j=0;j<M;j++){
        for(int i=0;i<N;i++){
            T[j]+=S[i][j];
        }
    }
    scc();
    
    vector<int> id(N+M);
    iota(all(id),0);
    sort(all(id),[&](int a,int b){
        return cmp[a]<cmp[b];
    });
    
    vector<int> ans(N+M);
    ans[id[0]]=1;
    
    for(int i=1;i<N+M;i++){
        int a=id[i-1],b=id[i];
        if(cmp[a]==cmp[b]){
            ans[b]=ans[a];
        }else{
            if(a<N&&b<N){
                if(S[a]==S[b]){
                    ans[b]=ans[a];
                }else{
                    ans[b]=ans[a]+1;
                }
            }else if(a>=N&&b>=N){
                if(T[a-N]==T[b-N]){
                    ans[b]=ans[a];
                }else{
                    ans[b]=ans[a]+1;
                }
            }else ans[b]=ans[a]+1;
        }
    }
    
    bool ok=true;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(S[i][j]=='>'){
                if(ans[i]<=ans[N+j]) ok=false;
            }else if(S[i][j]=='<'){
                if(ans[i]>=ans[N+j]) ok=false;
            }else{
                if(ans[i]!=ans[N+j]) ok=false;
            }
        }
    }
    
    if(ok){
        cout<<"Yes\n";
        for(int i=0;i<N;i++) cout<<ans[i]<<" ";
        cout<<endl;
        for(int i=0;i<M;i++) cout<<ans[N+i]<<" ";
        cout<<endl;
    }else cout<<"No\n";
}