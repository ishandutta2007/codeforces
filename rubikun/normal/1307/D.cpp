#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200005,INF=1<<30;
vector<int> G[MAX];
int dis[2][MAX];
int N;
void BFS(){
    for(int i=0;i<N;i++){
        dis[0][i]=INF;
        dis[1][i]=INF;
    }
    
    dis[0][0]=0;
    dis[1][N-1]=0;
    
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(int to:G[u]){
            if(dis[0][to]==INF){
                dis[0][to]=dis[0][u]+1;
                Q.push(to);
            }
        }
    }
    
    Q.push(N-1);
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(int to:G[u]){
            if(dis[1][to]==INF){
                dis[1][to]=dis[1][u]+1;
                Q.push(to);
            }
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int M,K;cin>>N>>M>>K;
    vector<int> S(K);
    for(int i=0;i<K;i++){
        cin>>S[i];
        S[i]--;
    }
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    BFS();
    
    int ans=0;
    
    sort(all(S),[&](int a,int b){
        return dis[0][a]>dis[0][b];
    });
    
    priority_queue<int> PQ;
    PQ.push(dis[1][S[0]]);
    
    for(int i=1;i<K;i++){
        int a=S[i];
        int b=PQ.top();
        ans=max(ans,min(dis[0][N-1],dis[0][a]+1+b));
        PQ.push(dis[1][a]);
    }
    
    cout<<ans<<endl;
}