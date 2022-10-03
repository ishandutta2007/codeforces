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

const int mod=1000000007,MAX=5005,INF=1<<30;


vector<int> G[MAX];
int siz[MAX];
int bit[MAX];
int a,b,c,d;
int A,B,C,D;

void DFS(int u,int p){
    for(int to:G[u]){
        if(to==p) continue;
        
        DFS(to,u);
        siz[u]+=siz[to];
        bit[u]|=bit[to];
    }
    
    if(si(G[u])==1) siz[u]=1;
    
    if(u==a) bit[u]=1;
    if(u==b) bit[u]=2;
    if(u==c) bit[u]=4;
    if(u==d) bit[u]=8;
}

bool dp[MAX][MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    cin>>a>>b>>c>>d;
    a--;b--;c--;d--;
    for(int i=1;i<N;i++){
        int x;cin>>x;
        x--;
        G[x].push_back(i);
        G[i].push_back(x);
    }
    
    DFS(0,-1);
    
    vector<int> S;
    
    for(int to:G[0]){
        if(bit[to]==0) S.push_back(siz[to]);
        else{
            if(bit[to]==1) A=siz[to];
            if(bit[to]==2) B=siz[to];
            if(bit[to]==4) C=siz[to];
            if(bit[to]==8) D=siz[to];
        }
    }
    
    int X=siz[0];
    
    if(X&1){
        cout<<"NO"<<endl;
        return 0;
    }
    
    dp[0][0]=1;
    
    for(int i=0;i<si(S);i++){
        for(int j=0;j<=N;j++){
            if(dp[i][j]==0) continue;
            
            dp[i+1][j]=1;
            dp[i+1][j+S[i]]=1;
        }
    }
    
    int l=max(0,X/2-1-(A+B-2)),r=X/2-1;
    
    bool ok=false;
    
    for(int j=0;j<=N;j++){
        if(dp[si(S)][j]&&j+C>=l&&j+C<=r) ok=true;
        if(dp[si(S)][j]&&j+D>=l&&j+D<=r) ok=true;
    }
    
    if(A>=X/2||B>=X/2||C>=X/2||D>=X/2) ok=false;
    
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    //cout<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
}