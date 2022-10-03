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
const int mod=998244353,MAX=405,INF=1<<29;
int dis[MAX][MAX][2];
bool A[MAX][MAX],B[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i!=j) B[i][j]=true;
        }
        A[i][i]=true;
        B[i][i]=true;
    }
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;a--;b--;
        A[a][b]=A[b][a]=true;
        B[a][b]=B[b][a]=false;
    }
    
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) for(int k=0;k<2;k++) dis[i][j][k]=INF;
    queue<vector<int>> Q;
    dis[0][0][0]=0;
    Q.push({0,0,0});
    
    while(!Q.empty()){
        auto u=Q.front();Q.pop();
        if(u[2]==0){
            for(int i=0;i<N;i++){
                if(A[u[0]][i]&&chmin(dis[i][u[1]][1],dis[u[0]][u[1]][0])) Q.push({i,u[1],1});
            }
        }else{
            for(int i=0;i<N;i++){
                if(u[0]==i&&1<=i&&i<N-1) continue;
                if(B[i][u[1]]&&chmin(dis[u[0]][i][0],dis[u[0]][u[1]][1]+1)) Q.push({u[0],i,0});
            }
        }
    }
    
    if(dis[N-1][N-1][0]==INF) cout<<-1<<"\n";
    else cout<<dis[N-1][N-1][0]<<"\n";
}