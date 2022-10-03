#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=300005,INF=1<<30;
vector<int> G[MAX];
int size[MAX],type[MAX],num[MAX];

void DFS(int u,int p){
    if(G[u].size()==1){
        size[u]=1;
        num[u]=1;
        return;
    }
    if(type[u]==0) num[u]=1;
    else num[u]=INF;
    
    for(int to:G[u]){
        if(to==p) continue;
        DFS(to,u);
        
        size[u]+=size[to];
        
        if(type[u]==0) num[u]+=num[to]-1;
        else num[u]=min(num[u],size[to]-num[to]);
    }
    
    if(type[u]==1) num[u]=size[u]-num[u];
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    for(int i=0;i<N;i++) cin>>type[i];
    for(int i=1;i<N;i++){
        int a;cin>>a;
        a--;
        G[i].push_back(a);
        G[a].push_back(i);
    }
    
    DFS(0,-1);
    
    cout<<num[0]<<endl;
    
}