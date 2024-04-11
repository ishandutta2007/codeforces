#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=100005,INF=1<<30;
vector<int> G[MAX],kind[105];
int dis[MAX][105];
int N,M,K,S;

void BFS(){
    for(int k=0;k<K;k++){
        for(int i=0;i<N;i++) dis[i][k]=INF;
        queue<int> Q;
        for(int a:kind[k]){
            Q.push(a);
            dis[a][k]=0;
        }
        
        while(!Q.empty()){
            int u=Q.front();Q.pop();
            for(int to:G[u]){
                if(chmin(dis[to][k],dis[u][k]+1)){
                    Q.push(to);
                }
            }
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>M>>K>>S;
    
    for(int i=0;i<N;i++){
        int a;cin>>a;
        a--;
        kind[a].push_back(i);
    }
    
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    BFS();
    
    for(int i=0;i<N;i++){
        sort(dis[i],dis[i]+K);
        ll res=0;
        for(int j=0;j<S;j++) res+=dis[i][j];
        cout<<res<<" ";
    }
    cout<<endl;
}