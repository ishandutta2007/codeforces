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
const int mod=1000000007,MAX=3005,INF=1<<28;
int D[MAX][MAX];
pair<int,int> dis[MAX][MAX],dis2[MAX][MAX];
int N;

vector<int> G[MAX];

void BFS(){
    for(int u=0;u<N;u++){
        for(int v=0;v<N;v++){
            dis[u][v]=mp(INF,v);
        }
        dis[u][u].fi=0;
        
        queue<int> Q;
        Q.push(u);
        
        while(!Q.empty()){
            int x=Q.front();Q.pop();
            for(int to:G[x]){
                if(chmin(dis[u][to].fi,dis[u][x].fi+1)){
                    Q.push(to);
                }
            }
        }
        
        for(int j=0;j<N;j++){
            if(dis[u][j].fi==INF) dis[u][j].fi=-INF;
            dis2[j][u]=mp(dis[u][j].fi,u);
            D[u][j]=dis[u][j].fi;
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int M;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        if(a==b) continue;
        G[a].push_back(b);
    }
    
    BFS();
    
    for(int u=0;u<N;u++){
        sort(dis[u],dis[u]+N);
        reverse(dis[u],dis[u]+N);
        
        sort(dis2[u],dis2[u]+N);
        reverse(dis2[u],dis2[u]+N);
    }
    
    int ma=-1;
    
    vector<int> ans(4,-1);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) continue;
            
            for(int a=0;a<4;a++){
                for(int b=0;b<4;b++){
                    int d=0;
                    d+=dis2[i][a].fi;
                    d+=D[i][j];
                    d+=dis[j][b].fi;
                    
                    if(i==dis2[i][a].se) continue;
                    if(j==dis2[i][a].se) continue;
                    if(dis[j][b].se==dis2[i][a].se) continue;
                    if(i==dis[j][b].se) continue;
                    if(j==dis[j][b].se) continue;
                    
                    if(chmax(ma,d)){
                        ans[0]=dis2[i][a].se;
                        ans[1]=i;
                        ans[2]=j;
                        ans[3]=dis[j][b].se;
                    }
                    break;
                }
            }
        }
    }
    
    for(int a:ans) cout<<a+1<<" ";
    cout<<endl;
}