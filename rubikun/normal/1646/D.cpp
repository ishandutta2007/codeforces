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
const int mod=998244353,MAX=300005,INF=1<<30;

vector<int> G[MAX];
pair<int,int> dp[MAX][2];

void add(pair<int,int> &a,pair<int,int> b){
    a.fi+=b.fi;
    a.se+=b.se;
}

void solve(int u,int p){
    dp[u][1]=mp(1,si(G[u]));
    for(int to:G[u]){
        if(to==p) continue;
        solve(to,u);
        if(dp[to][0].fi>dp[to][1].fi||(dp[to][0].fi==dp[to][1].fi&&dp[to][0].se<dp[to][1].se)) add(dp[u][0],dp[to][0]);
        else add(dp[u][0],dp[to][1]);
        add(dp[u][1],dp[to][0]);
    }
}

bool use[MAX];

void resolve(int u,int p,bool f){
    use[u]=f;
    for(int to:G[u]){
        if(to==p) continue;
        if(!f){
            if(dp[to][0].fi>dp[to][1].fi||(dp[to][0].fi==dp[to][1].fi&&dp[to][0].se<dp[to][1].se)) resolve(to,u,false);
            else resolve(to,u,true);
        }else{
            resolve(to,u,false);
        }
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    if(N==2){
        cout<<2<<" "<<2<<"\n";
        cout<<1<<" "<<1<<"\n";
        return 0;
    }
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=0;i<N;i++) dp[i][0]=dp[i][1]=mp(0,0);
    solve(0,-1);
    
    if(dp[0][0].fi>dp[0][1].fi||(dp[0][0].fi==dp[0][1].fi&&dp[0][0].se<dp[0][1].se)){
        resolve(0,-1,0);
    }else{
        resolve(0,-1,1);
    }
    
    int cn=0;ll need=0;
    for(int i=0;i<N;i++){
        if(use[i]){
            cn++;
            need+=si(G[i]);
        }else{
            need++;
        }
    }
    cout<<cn<<" "<<need<<"\n";
    for(int i=0;i<N;i++){
        if(use[i]) cout<<si(G[i])<<" ";
        else cout<<1<<" ";
    }
    cout<<"\n";
}