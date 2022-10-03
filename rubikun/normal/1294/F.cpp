#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;
vector<int> G[MAX];
int length[MAX];

void preDFS(int u,int p){
    for(int to:G[u]){
        if(to==p) continue;
        
        preDFS(to,u);
        length[u]=max(length[u],length[to]+1);
    }
}

int ans=0;
int a=-1,b=-1,c=-1,root=-1;

void DFS(int u,int p){
    //cout<<u<<" "<<p<<endl;
    vector<pair<int,int>> le;
    
    for(int to:G[u]) le.push_back({length[to],to});
    sort(all(le));
    reverse(all(le));
    
    int sum=0;
    for(int i=0;i<min(3,int(le.size()));i++) sum+=(le[i].first+1);
    
    //cout<<u<<" "<<sum<<endl;
    if(ans<sum&&le.size()>=3){
        ans=sum;
        a=le[0].second;
        b=le[1].second;
        c=le[2].second;
        root=u;
    }else if(ans<sum&&le.size()==2){
        ans=sum;
        a=le[0].second;
        b=le[1].second;
        c=u;
        root=u;
    }
    
    for(int to:G[u]){
        if(to==p) continue;
        int maeto=length[to],maeu=length[u];
        
        if(le[0].second==to){
            if(le.size()==1){
                length[u]=0;
                length[to]=max(length[to],length[u]+1);
                
                DFS(to,u);
                
                length[u]=maeu;
                length[to]=maeto;
            }else{
                length[u]=le[1].first+1;
                length[to]=max(length[to],length[u]+1);
                
                DFS(to,u);
                
                length[u]=maeu;
                length[to]=maeto;
            }
        }else{
            length[to]=max(length[to],length[u]+1);
            
            DFS(to,u);
            
            length[to]=maeto;
        }
    }
    
    //cout<<u<<" "<<p<<endl;
}

pair<int,int> dis[MAX];

void lastDFS(int u,int p){
    
    for(int to:G[u]){
        if(to==p) continue;
        
        if(dis[u].first==0){
            dis[to]={1,to};
            lastDFS(to,u);
        }else{
            dis[to]={dis[u].first+1,dis[u].second};
            lastDFS(to,u);
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    preDFS(0,-1);
    
    DFS(0,-1);
    
    lastDFS(root,-1);
    
    vector<pair<int,int>> A,B,C;
    
    for(int i=0;i<N;i++){
        if(dis[i].second==a) A.push_back({dis[i].first,i});
        if(dis[i].second==b) B.push_back({dis[i].first,i});
        if(dis[i].second==c) C.push_back({dis[i].first,i});
    }
    
    sort(all(A));
    sort(all(B));
    sort(all(C));
    
    reverse(all(A));
    reverse(all(B));
    reverse(all(C));
    
    if(c==root){
        cout<<ans<<endl;
        cout<<A[0].second+1<<" "<<B[0].second+1<<" "<<c+1<<endl;
    }else{
        cout<<ans<<endl;
        cout<<A[0].second+1<<" "<<B[0].second+1<<" "<<C[0].second+1<<endl;
    }
}