#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1000003;
const ll INF=1LL<<60;

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

int scc(int V){
    memset(used,0,V);
    vs.clear();
    for(int v=0;v<V;v++){
        if(used[v]==0) DFS(v);
    }
    
    memset(used,0,V);
    int k=0;
    for(int i=vs.size()-1;i>=0;i--){
        if(used[vs[i]]==0) rDFS(vs[i],k++);
    }
    return k;
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q){
        cin>>V;
        //scanf("%d",&V);
        int M;
        cin>>M;
        //scanf("%d",&M);
        for(int i=0;i<V;i++){
            //cmp[i]=0;
            G[i].resize(0);
            rG[i].resize(0);
            //used[i]=0;
        }
        memset(cmp,0,V);
        //memset(used,0,V);
        //vs.resize(0);
        for(int i=0;i<M;i++){
            int a,b;cin>>a>>b;
            //scanf("%d%d",&a,&b);
            a--;b--;
            if(a!=b) add_edge(a,b);
        }
        
        int t=scc(V);
        
        if(t<=1){
            //cout<<"No"<<endl;
            printf("No\n");
        }else{
            vector<int> A,B;
            for(int i=0;i<V;i++){
                if(cmp[i]==0) B.push_back(i+1);
                else A.push_back(i+1);
            }
            //cout<<"Yes"<<endl;
            printf("Yes\n");
            
            printf("%d %d\n",int(A.size()),int(B.size()));
            
            //cout<<A.size()<<" "<<B.size()<<"\n;
            
            for(int i:A) printf("%d ",i);
            //cout<<"\n";
            printf("\n");
            for(int i:B) printf("%d ",i);
            //cout<<"\n";
            printf("\n");
        }
        
        Q--;
    }
}