#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1005,INF=1<<30;
vector<int> G[MAX];
int used[MAX];
int dis[MAX],par[MAX];

void DFS(int u,int p){
    for(int to:G[u]){
        if(used[to]) continue;
        if(to==p) continue;
        if(dis[to]!=-1) continue;
        
        par[to]=u;
        dis[to]=dis[u]+1;
        DFS(to,u);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> from(N-1),to(N-1);
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
        from[i]=a;
        to[i]=b;
    }
    
    if(N==2){
        cout<<"? 1 2"<<endl;
        int a;cin>>a;
        cout<<"! "<<a<<endl;
        
        return 0;
    }
    int last=0;
    
    int can=N/2;
    
    while(can){
        memset(dis,-1,sizeof(dis));
        memset(par,-1,sizeof(par));
        int u,v,ma=0;
        
        dis[last]=0;
        DFS(last,-1);
        u=last;
        v=last;
        for(int i=0;i<N;i++){
            if(used[i]==0&&ma<dis[i]){
                ma=dis[i];
                v=i;
            }
        }
        memset(dis,-1,sizeof(dis));
        memset(par,-1,sizeof(par));
        dis[v]=0;
        DFS(v,-1);
        
        ma=0;
        for(int i=0;i<N;i++){
            if(used[i]==0&&ma<dis[i]){
                ma=dis[i];
                u=i;
            }
        }
        
        if(ma==0){
            cout<<"! "<<last+1<<endl;
            return 0;
        }
        
        cout<<"? "<<u+1<<" "<<v+1<<endl;
        int c;cin>>c;
        c--;
        
        if(ma==1){
            cout<<"! "<<c+1<<endl;
            return 0;
        }
        
        if(c==u||c==v){
            cout<<"! "<<c+1<<endl;
            return 0;
        }else{
            used[u]=1;
            used[v]=1;
        }
        
        last=c;
        
        can--;
    }
    
    cout<<"! "<<last+1<<endl;
    
}