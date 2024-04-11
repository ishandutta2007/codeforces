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

vector<int> G[MAX];

ll dp[MAX][2];

void solve(int u,int p){
    vector<pair<int,int>> S;
    for(int to:G[u]){
        if(to==p) continue;
        
        solve(to,u);
        
        S.push_back(mp(dp[to][0]+1,dp[to][1]));
    }
    
    vector<ll> red;
    for(auto a:S){
        dp[u][0]+=a.fi;
        dp[u][1]+=a.fi;
        red.push_back(a.fi-a.se);
    }
    sort(all(red));
    reverse(all(red));
    for(int i=0;i<min(2,si(red));i++){
        dp[u][0]-=max(0LL,red[i]);
    }
    for(int i=0;i<min(1,si(red));i++){
        dp[u][1]-=max(0LL,red[i]);
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    ll x,y;cin>>x>>y;
    
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    if(x>=y){
        bool f=true;
        for(int i=0;i<N;i++){
            f&=(si(G[i])<N-1);
        }
        if(f){
            cout<<y*(N-1)<<"\n";
        }else{
            cout<<y*(N-2)+x<<"\n";
        }
        return 0;
    }
    
    solve(0,-1);
    
    cout<<y*min(dp[0][0],dp[0][1])+x*(N-1-min(dp[0][0],dp[0][1]))<<endl;
    
}