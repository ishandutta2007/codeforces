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
const int mod=998244353,MAX=605;
const ll INF=1LL<<60;
ll dis[MAX][MAX],jouken[MAX][MAX],ans[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<pair<pair<int,int>,int>> E(M);
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) dis[i][j]=INF;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) jouken[i][j]=ans[i][j]=-INF;
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        dis[a][b]=c;
        dis[b][a]=c;
        E[i]=mp(mp(a,b),c);
    }
    
    for(int i=0;i<N;i++) dis[i][i]=jouken[i][i]=ans[i][i]=0;
    
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                chmin(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    
    int Q;cin>>Q;
    while(Q--){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        for(int x=0;x<N;x++){
            chmax(jouken[x][b],c-dis[a][x]);
            chmax(jouken[x][a],c-dis[b][x]);
        }
    }
    
    for(int a=0;a<N;a++){
        for(int b=0;b<N;b++){
            ll c=jouken[a][b];
            if(c<=0) continue;
            for(int x=0;x<N;x++){
                chmax(ans[x][b],c-dis[a][x]);
                chmax(ans[x][a],c-dis[b][x]);
            }
        }
    }
    
    int res=0;
    
    for(auto e:E){
        if(ans[e.fi.fi][e.fi.se]>=e.se) res++;
    }
    
    cout<<res<<endl;
}