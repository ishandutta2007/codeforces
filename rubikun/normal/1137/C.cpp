#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=5000001,INF=1<<30;
int N,M,D;

int V;
array<int,MAX> cmp;
array<bool,MAX> used;
vector<int> G[MAX],rG[MAX],vs;//vs

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
    vs.clear();
    for(int v=0;v<V;v++){
        if(used[v]==0) DFS(v);
    }
    
    for(int i=0;i<V;i++) used[i]=0;
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
    
    cin>>N>>M>>D;
    vector<pair<int,int>> ed(M);
    
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        for(int j=0;j<D;j++){
            add_edge(a*D+j,b*D+(j+1)%D);
            ed[i]={a,b};
        }
    }
    /*vector<string> S(N);
    for(int i=0;i<N;i++){
        cin>>S[i];
    }*/
    V=N*D;
    int k=scc();
    
    vs.clear();
    for(int i=0;i<k;i++){
        G[i].clear();
        rG[i].clear();
    }
    
    for(int i=0;i<N;i++){
        string S;cin>>S;
        for(int j=0;j<D;j++){
            if(S[j]=='1'){
                if(!(rG[cmp[i*D+j]].size()>=1&&rG[cmp[i*D+j]].back()==i)) rG[cmp[i*D+j]].push_back(i);
            }
        }
    }
    /*for(int i=0;i<k;i++){
        sort(all(rG[i]));
        rG[i].erase(unique(all(rG[i])),rG[i].end());
    }*/
    
    for(int e=0;e<M;e++){
        for(int j=0;j<D;j++){
            if(cmp[(ed[e].first)*D+j]!=cmp[(ed[e].second)*D+(j+1)%D]) G[cmp[(ed[e].first)*D+j]].push_back(cmp[(ed[e].second)*D+(j+1)%D]);
        }
        //cout<<cmp[ed[e].first]<<" "<<cmp[ed[e].second]<<endl;
    }
    
    vector<int> dp(k);
    
    for(int i=k-1;i>=0;i--){
        int maxi=0;
        for(int to:G[i]) maxi=max(maxi,dp[to]);
        dp[i]=rG[i].size()+maxi;
    }
    
    //for(int i=0;i<N*D;i++) cout<<i/D<<" "<<cmp[i]<<endl;
    
    cout<<dp[cmp[0]]<<endl;
    
    //for(int a:vs) cout<<a/D<<" "<<a%D<<endl;
}