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
const int mod=998244353,MAX=3005,INF=1<<29;

vector<int> G[MAX];

int dis[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    for(int s=0;s<N;s++){
        for(int i=0;i<N;i++) dis[s][i]=INF;
        queue<int> Q;Q.push(s);dis[s][s]=0;
        while(!Q.empty()){
            int u=Q.front();Q.pop();
            for(int to:G[u]){
                if(chmin(dis[s][to],dis[s][u]+1)) Q.push(to);
            }
        }
    }
    
    int x1,y1,z1,x2,y2,z2;cin>>x1>>y1>>z1>>x2>>y2>>z2;
    x1--;y1--;x2--;y2--;
    
    if(dis[x1][y1]>z1||dis[x2][y2]>z2){
        cout<<-1<<endl;
        return 0;
    }
    
    int ans=dis[x1][y1]+dis[x2][y2];
    
    for(int a=0;a<N;a++){
        for(int b=0;b<N;b++){
            int k=dis[a][b];
            int X=min(dis[x1][a]+dis[b][y1]+k,dis[x1][b]+dis[a][y1]+k);
            int Y=min(dis[x2][a]+dis[b][y2]+k,dis[x2][b]+dis[a][y2]+k);
            if(X<=z1&&Y<=z2){
                chmin(ans,X+Y-k);
            }
        }
    }
    
    cout<<M-ans<<endl;
}