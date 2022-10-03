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
const int mod=998244353,MAX=200005,INF=1<<30;

int sz[MAX],A[MAX];
bool f[MAX];
int dp[MAX];

vector<int> G[MAX];

int mid,N,K;

void make(int u,int p){
    sz[u]=1;
    for(int to:G[u]){
        if(to==p) continue;
        make(to,u);
        sz[u]+=sz[to];
    }
}

bool ok=false;

void pre(int u,int p){
    int X=0,Y=0;
    for(int to:G[u]){
        if(to==p) continue;
        pre(to,u);
        if(sz[to]==dp[to]) X+=dp[to];
        else chmax(Y,dp[to]);
    }
    if(f[u]){
        dp[u]=1+X+Y;
    }else{
        dp[u]=0;
    }
}

void solve(int u,int p){
    int X=0,Y=0,Z=0;
    for(int to:G[u]){
        if(sz[to]==dp[to]) X+=dp[to];
        else{
            if(Y<dp[to]){
                Z=Y;
                Y=dp[to];
            }else if(Z<dp[to]){
                Z=dp[to];
            }
        }
    }
    if(f[u]){
        dp[u]=1+X+Y;
    }else{
        dp[u]=0;
    }
    
    if(dp[u]>=K) ok=true;
    
    for(int to:G[u]){
        if(to==p) continue;
        
        int sav=dp[u];
        int a=sz[u],b=sz[to];
        
        if(f[u]){
            if(sz[to]==dp[to]){
                dp[u]-=dp[to];
            }else{
                if(Y==dp[to]){
                    dp[u]-=Y;
                    dp[u]+=Z;
                }
            }
        }
        sz[u]-=sz[to];
        sz[to]=N;
        
        solve(to,u);
        
        dp[u]=sav;
        sz[u]=a;
        sz[to]=b;
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    make(0,-1);
    
    int left=0,right=1000001;
    while(right-left>1){
        mid=(left+right)/2;
        for(int i=0;i<N;i++){
            if(A[i]>=mid) f[i]=true;
            else f[i]=false;
            dp[i]=0;
        }
        ok=false;
        pre(0,-1);
        solve(0,-1);
        
        if(ok) left=mid;
        else right=mid;
    }
    
    cout<<left<<endl;
}