#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

bool ok=true;
vector<int> G[MAX],color(MAX);

void DFS(int u,int p){
    for(auto to:G[u]){
        if(to==p) continue;
        if(color[to]==4){
            color[to]=5-color[u];
            DFS(to,u);
        }else if(color[u]==color[to]){
            ok=false;
            return;
        }
    }
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,M;cin>>N>>M;
    vector<pair<int,int>> edge(M);
    for(int i=0;i<M;i++){
        int a,b;
        //cin>>a>>b;
        scanf("%d%d",&a,&b);
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
        edge[i]=make_pair(a,b);
    }
    
    for(int i=0;i<N;i++){
        color[i]=1;
    }
    for(int u:G[0]){
        color[u]=4;
    }
    
    for(int i=0;i<N;i++){
        if(color[i]==4){
            color[i]=2;
            DFS(i,-1);
            break;
        }
    }
    
    int a=0,b=0,c=0;
    for(int i=0;i<N;i++){
        if(color[i]==1) a++;
        if(color[i]==2) b++;
        if(color[i]==3) c++;
    }
    
    if(a*b+b*c+c*a!=M||!ok||a+b+c!=N){
        cout<<-1<<endl;
        return 0;
    }
    
    for(int i=0;i<M;i++){
        int d=edge[i].first,e=edge[i].second;
        if(color[d]==color[e]) ok=false;
    }
    
    if(ok&&a&&b&&c){
        for(int i=0;i<N;i++){
            if(i) printf(" ");
            printf("%d",color[i]);
        }
    }else cout<<-1<<endl;
}