#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;
int N;
vector<int> G[MAX],size(MAX,0);
ll sum=0,ans=0;

int DFS1(int u,int p){
    int x=1;
    for(int i=0;i<G[u].size();i++){
        int a=G[u][i];
        if(a==p) continue;
        x+=DFS1(a,u);
    }
    return size[u]=x;
}

void DFS2(int u,int p){
    for(int i=0;i<G[u].size();i++){
        int a=G[u][i];
        if(a==p) continue;
        int b=size[u],c=size[a];
        size[u]=b-c;
        size[a]=b;
        sum+=b-2*c;
        ans=max(ans,sum);
        DFS2(a,u);
        size[u]=b;
        size[a]=c;
        sum-=b-2*c;
    }
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    DFS1(0,-1);
    for(int i=0;i<N;i++){
        sum+=size[i];
        ans+=size[i];
    }
    
    DFS2(0,-1);
    
    cout<<ans<<endl;
    
    
}