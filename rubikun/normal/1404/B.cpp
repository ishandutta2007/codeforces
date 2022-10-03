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
vector<int> G[MAX];

int dis[MAX][2];

void pre(int u,int p,int k){
    for(int to:G[u]){
        if(to==p) continue;
        dis[to][k]=dis[u][k]+1;
        pre(to,u,k);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N,A,B,da,db;cin>>N>>A>>B>>da>>db;
        A--;B--;
        for(int i=0;i<N;i++){
            G[i].clear();
            dis[i][0]=dis[i][1]=INF;
        }
        
        for(int i=0;i<N-1;i++){
            int a,b;cin>>a>>b;
            a--;b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        if(da*2>=db){
            cout<<"Alice\n";
            continue;
        }
        
        dis[A][0]=0;
        pre(A,-1,0);
        pair<int,int> ma={-1,0},ma2={-1,0};
        for(int i=0;i<N;i++) chmax(ma,{dis[i][0],i});
        dis[ma.second][1]=0;
        pre(ma.second,-1,1);
        for(int i=0;i<N;i++) chmax(ma2,{dis[i][1],i});
        
        if(dis[B][0]<=da||ma2.fi<=da*2){
            cout<<"Alice\n";
        }else{
            cout<<"Bob\n";
        }
        
    }
}