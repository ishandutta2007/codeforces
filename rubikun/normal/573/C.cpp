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
int N;
vector<int> G[MAX],G2[MAX];

int dis[MAX][3],dis2[MAX];
vector<int> diameter;
bool no[MAX];

void BFS(){
    queue<int> Q;
    for(int i=0;i<N;i++){
        if(si(G2[i])==1){
            Q.push(i);
        }
    }
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        if(no[u]) continue;
        no[u]=1;
        
        for(int to:G2[u]){
            if(si(G2[to])<=2) Q.push(to);
        }
    }
}

void pre(int u,int p,int k){
    for(int to:G[u]){
        if(to==p) continue;
        dis[to][k]=dis[u][k]+1;
        pre(to,u,k);
    }
}

void make(int u,int p,int goal,bool &flag){
    if(u==goal){
        diameter.push_back(u);
        flag=true;
        return;
    }
    for(int to:G[u]){
        if(to==p) continue;
        make(to,u,goal,flag);
        if(flag){
            diameter.push_back(u);
            return;
        }
    }
}

void BFS2(){
    queue<int> Q;
    for(int a:diameter){
        dis[a][2]=0;
        Q.push(a);
    }
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(int to:G[u]){
            if(chmin(dis[to][2],dis[u][2]+1)){
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
    
    cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G2[a].push_back(b);
        G2[b].push_back(a);
    }
    bool ok=true;
    
    for(int i=0;i<N;i++){
        if(si(G2[i])>=3) ok=false;
    }
    
    if(ok){
        cout<<"Yes\n";
        return 0;
    }
    ok=true;
    
    BFS();
    
    for(int i=0;i<N;i++){
        for(int a:G2[i]){
            if(no[i]==0&&no[a]==0){
                G[i].push_back(a);
            }
        }
    }
    
    for(int i=0;i<N;i++){
        dis[i][0]=dis[i][1]=dis[i][2]=INF;
    }
    int s=-1;
    for(int i=0;i<N;i++){
        if(!no[i]){
            s=i;
            break;
        }
    }
    dis[s][0]=0;
    pre(s,-1,0);
    pair<int,int> ma={0,0},ma2={0,0};
    for(int i=0;i<N;i++) if(dis[i][0]!=INF) chmax(ma,{dis[i][0],i});
    dis[ma.second][1]=0;
    pre(ma.second,-1,1);
    for(int i=0;i<N;i++) if(dis[i][1]!=INF) chmax(ma2,{dis[i][1],i});
    bool flag=false;
    make(ma.se,-1,ma2.se,flag);
    
    BFS2();
    set<int> ro;
    for(int i=0;i<N;i++){
        if(si(G2[i])==3&&dis[i][2]>=2) ok=false;
        if(si(G2[i])>=4){
            if(dis[i][2]>=2) ok=false;
            if(dis[i][2]==1){
                ro.insert(i);
            }
        }
    }
    
    if(si(diameter)==1){
        cout<<"Yes\n";
        return 0;
    }
    
    if(si(ro)>=3) ok=false;
    else{
        if(si(G2[diameter[0]])==3) for(int to:G2[diameter[1]]) if(ro.count(to)) ro.erase(to);
        if(si(G2[diameter.back()])==3) for(int to:G2[diameter[si(diameter)-2]]) if(ro.count(to)) ro.erase(to);
        
        if(si(ro)) ok=false;
    }
    
    if(ok) cout<<"Yes\n";
    else cout<<"No\n";
}