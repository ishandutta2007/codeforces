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
const int mod=1000000007,MAX=200005,INF=1<<29;

int N,ans=INF;
vector<int> G[MAX];
int dis[MAX][2],dis2[MAX];
vector<int> diameter;

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

vector<int> dp[MAX];
bool f=true;

void DFS(int u,int p,int ro){
    for(int to:G[u]){
        if(to==p) continue;
        DFS(to,u,ro);
        if(si(dp[to])==1) dp[u].push_back(dp[to][0]+1);
    }
    sort(all(dp[u]));
    dp[u].erase(unique(all(dp[u])),dp[u].end());
    if(si(dp[u])==0){
        dp[u].push_back(0);
    }else{
        if(u==ro){
            if(si(dp[u])>=3) f=false;
        }else{
            if(si(dp[u])>=2) f=false;
        }
    }
}

void solve(int ro){
    f=true;
    for(int i=0;i<N;i++) dp[i].clear();
    DFS(ro,-1,ro);
    if(f){
        int x;
        if(si(dp[ro])==2) x=dp[ro][0]+dp[ro][1];
        else x=dp[ro][0];
        while(x%2==0) x/=2;
        chmin(ans,x);
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
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=0;i<N;i++){
        dis[i][0]=dis[i][1]=INF;
    }
    dis[0][0]=0;
    pre(0,-1,0);
    pair<int,int> ma={0,0},ma2={0,0};
    for(int i=0;i<N;i++) chmax(ma,{dis[i][0],i});
    dis[ma.second][1]=0;
    pre(ma.second,-1,1);
    for(int i=0;i<N;i++) chmax(ma2,{dis[i][1],i});
    bool flag=false;
    make(ma.se,-1,ma2.se,flag);
    
    if(si(diameter)==N){
        int ans=N-1;
        while(ans%2==0) ans/=2;
        cout<<ans<<endl;
        return 0;
    }
    
    if(si(diameter)&1){
        solve(diameter[si(diameter)/2]);
    }else{
        solve(diameter[si(diameter)/2-1]);
        solve(diameter[si(diameter)/2]);
    }
    
    if(ans==INF) ans=-1;
    cout<<ans<<endl;
}