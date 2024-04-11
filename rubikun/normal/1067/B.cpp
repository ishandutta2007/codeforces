#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=100005,INF=1<<30;
vector<int> G[MAX];
int dis[MAX],par[MAX];
int K;

int BFS(int s){
    queue<int> Q;
    Q.push(s);
    dis[s]=0;
    
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(int to:G[u]){
            if(dis[to]!=-1) continue;
            
            dis[to]=dis[u]+1;
            par[to]=u;
            Q.push(to);
            
            if(dis[to]==2*K){
                for(int j=0;j<K;j++){
                    to=par[to];
                }
                return to;
            }
        }
    }
    
    return -1;
}

bool DFS(int u,int p,int d){
    
    if(d==K){
        if(G[u].size()!=1) return false;
        return true;
    }else if(d>K) return false;
    
    if(d==0&&G[u].size()<=2) return false;
    if(d>=1&&G[u].size()<=3) return false;
    
    bool res=true;
    for(int to:G[u]){
        if(to==p) continue;
        
        res&=DFS(to,u,d+1);
    }
    
    return res;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N>>K;
    memset(dis,-1,sizeof(dis));
    memset(par,-1,sizeof(par));

    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    int root=-1;
    
    for(int i=0;i<N;i++){
        if(G[i].size()==1){
            root=BFS(i);
            break;
        }
    }
    
    //cout<<root<<endl;
    
    if(root==-1){
        cout<<"No"<<endl;
        return 0;
    }
    
    if(DFS(root,-1,0)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    
    
}