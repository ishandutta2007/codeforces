#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=205,INF=1<<28;

vector<int> G[MAX];

int dis[MAX][MAX];
int ans=INF;

void BFS(int u){
    dis[u][u]=0;
    queue<pair<int,int>> Q;
    Q.push({u,-1});
    
    while(!Q.empty()){
        int a=Q.front().first,p=Q.front().second;Q.pop();
        for(int to:G[a]){
            if(to==p) continue;
            if(dis[u][to]==INF){
                dis[u][to]=dis[u][a]+1;
                Q.push({to,a});
            }else{
                ans=min(ans,dis[u][a]+dis[u][to]+1);
                //cout<<dis[u][a]<<" "<<dis[u][to]<<endl;
            }
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    vector<int> cnt(63);
    
    for(int i=0;i<63;i++){
        for(int j=0;j<N;j++){
            if(A[j]&(1LL<<i)) cnt[i]++;
        }
    }
    
    for(int i=0;i<63;i++){
        if(cnt[i]>=3){
            cout<<3<<endl;
            return 0;
        }
    }
    
    for(int j=0;j<N;j++){
        for(int i=0;i<63;i++){
            if(A[j]&(1LL<<i)){
                if(cnt[i]==1) A[j]^=(1LL<<i);
            }
        }
    }
    
    vector<ll> B;
    for(int i=0;i<N;i++){
        if(A[i]!=0) B.push_back(A[i]);
    }
    N=B.size();
    
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(B[i]&B[j]){
                G[i].push_back(j);
                G[j].push_back(i);
                
                //cout<<i<<" "<<j<<endl;
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dis[i][j]=INF;
        }
    }
    
    for(int i=0;i<N;i++){
        BFS(i);
    }
    
    if(ans==INF) cout<<-1<<endl;
    else cout<<ans<<endl;
    
    
}