#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;
int ans=0;
vector<int> G[MAX],visited(MAX);

void BFS(int u){
    visited[u]=1;
    queue<int> Q;
    Q.push(u);
    while(!Q.empty()){
        int a=Q.front();Q.pop();
        for(int i=0;i<G[a].size();i++){
            int b=G[a][i];
            if(visited[b]) continue;
            ans++;
            Q.push(b);
            visited[b]=1;
        }
    }
}

int main(){
    
    //std::ifstream in("text.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int N,K;cin>>N>>K;
    for(int i=0;i<K;i++){
        int a,b;
        scanf("%d%d",&a,&b);//cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    for(int i=0;i<N;i++){
        if(visited[i]==0) BFS(i);
    }
    
    cout<<K-ans<<endl;
}