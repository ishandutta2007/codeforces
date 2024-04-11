#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005;
const ll INF=1LL<<60;
vector<int> G[MAX];

int color[MAX];

void DFS(int u,int p){
    for(int to:G[u]){
        if(to==p) continue;
        if(color[to]>=0) continue;
        
        color[to]=1-color[u];
        DFS(to,u);
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
    memset(color,-1,sizeof(color));
    
    color[0]=0;
    DFS(0,-1);
    
    int leaf=0;
    set<int> SE,co;
    
    for(int i=0;i<N;i++){
        if(G[i].size()==1){
            leaf++;
            SE.insert(G[i][0]);
            co.insert(color[i]);
        }
    }
    
    int ma=N-1-(leaf-int(SE.size()));
    
    if(co.size()==1) cout<<1<<" ";
    else cout<<3<<" ";
    cout<<ma<<endl;
}