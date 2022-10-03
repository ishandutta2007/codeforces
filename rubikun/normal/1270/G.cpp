#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2000105,INF=1<<30;
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
 
int scc(int si){
    memset(used,0,si+2);
    vs.clear();
    for(int v=0;v<V;v++){
        if(used[v]==0) DFS(v);
    }
    
    memset(used,0,si+2);
    int k=0;
    for(int i=vs.size()-1;i>=0;i--){
        if(used[vs[i]]==0) rDFS(vs[i],k++);
    }
    return k;
}
 
vector<int> ans;
 
int main(){
 
    int T;cin>>T;
    while(T--){
        int N;
        scanf("%d",&N);
        V=2*N;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            int a;
            scanf("%d",&a);
            A[i]=i-a;
        }
        for(int i=0;i<V;i++){
            G[i].clear();
            rG[i].clear();
        }
        vs.clear();
        ans.clear();
        memset(cmp,0,4*V+4);
        
        for(int i=0;i<N;i++){
            add_edge(i,i+N);
        }
        for(int i=0;i<N;i++){
            add_edge(i+N,A[i]);
        }
        
        scc(V);
        int point=-1;
        
        for(int i=0;i<N;i++){
            if(cmp[i]==cmp[i+N]){
                point=cmp[i];
                break;
            }
        }
        for(int i=0;i<N;i++){
            if(cmp[i]==cmp[i+N]&&cmp[i]==point){
                ans.push_back(i+1);
            }
        }
        
        printf("%d\n",int(ans.size()));
        for(int a:ans){
            printf("%d ",a);
        }
        printf("\n");
    }
}