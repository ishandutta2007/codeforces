#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const ll mod=1000000007,MAX=200001,INF=1<<30;
vector<int> S[MAX],T[MAX];//S0T1
ll cnt0[MAX],cnt1[MAX],visited[MAX],ans=0;

void DFS(int u,int p){
    visited[u]=1;
    for(int i=0;i<S[u].size();i++){
        int a=S[u][i];
        if(a==p) continue;
        if(!visited[a]) DFS(a,u);
        cnt0[u]+=cnt0[a]+cnt1[a]+1;
    }
    for(int i=0;i<T[u].size();i++){
        int a=T[u][i];
        if(a==p) continue;
        if(!visited[a]) DFS(a,u);
        cnt1[u]+=cnt1[a]+1;
    }
}

void DFS2(int u,int p){
    for(int i=0;i<S[u].size();i++){
        int a=S[u][i];
        if(a==p) continue;
        cnt0[a]=cnt0[u]+cnt1[u]-cnt1[a];
        DFS2(a,u);
    }
    for(int i=0;i<T[u].size();i++){
        int a=T[u][i];
        if(a==p) continue;
        cnt1[a]=cnt1[u];
        DFS2(a,u);
    }
    ans+=cnt0[u]+cnt1[u];
    //cout<<u<<" "<<ans<<endl;
}



int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N;cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        if(c==0){
            S[a].push_back(b);
            S[b].push_back(a);
        }else{
            T[a].push_back(b);
            T[b].push_back(a);
        }
    }
    
    DFS(0,-1);
    DFS2(0,-1);
    cout<<ans<<endl;
    
    
}