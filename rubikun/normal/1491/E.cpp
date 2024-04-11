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
const int mod=1000000007,MAX=200005,INF=1<<30;
vector<pair<int,int>> G[MAX];
bool alive[MAX];
int fib[MAX];
int idx[MAX];

int dp[MAX];

pair<int,int> cut;
pair<int,int> target;

void DFS(int u,int p,int e){
    dp[u]=1;
    for(auto to:G[u]){
        if(to.fi==p) continue;
        if(alive[to.se]==0) continue;
        
        DFS(to.fi,u,to.se);
        
        dp[u]+=dp[to.fi];
    }
    if(dp[u]==target.fi&&cut.fi==-1){
        cut=mp(u,p);
        if(e>=0) alive[e]=0;
    }
    if(dp[u]==target.se&&cut.fi==-1){
        cut=mp(p,u);
        if(e>=0) alive[e]=0;
    }
}

void solve(int use,int sz){
    
    if(sz==1) return;
    
    target=mp(fib[idx[sz]-2],fib[idx[sz]-1]);
    
    cut=mp(-1,-1);
    DFS(use,-1,-1);
    
    if(cut.fi==-1&&cut.se==-1){
        cout<<"NO"<<endl;
        exit(0);
    }
    
    int a=cut.fi,b=cut.se;
    
    solve(a,fib[idx[sz]-2]);
    solve(b,fib[idx[sz]-1]);
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    
    fib[0]=fib[1]=1;
    idx[1]=1;
    
    for(int i=2;i<100;i++){
        fib[i]=fib[i-1]+fib[i-2];
        
        if(fib[i]>N) break;
        
        idx[fib[i]]=i;
    }
    
    if(idx[N]==0){
        cout<<"NO"<<endl;
        return 0;
    }
    
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(mp(b,i));
        G[b].push_back(mp(a,i));
        
        alive[i]=1;
    }
    
    solve(0,N);
    
    cout<<"YES"<<endl;
}