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
const int mod=1000000007,MAX=105,INF=1<<30;
vector<pair<int,int>> G[MAX];
bool seen[MAX][MAX][27][2],dp[MAX][MAX][27][2];

bool solve(int u,int v,int c,int f){
    if(seen[u][v][c][f]) return dp[u][v][c][f];
    
    seen[u][v][c][f]=true;
    
    bool win=false;
    
    if(!f){
        for(auto e:G[u]){
            if(e.se<c) continue;
            win|=!(solve(e.fi,v,e.se,f^1));
        }
    }else{
        for(auto e:G[v]){
            if(e.se<c) continue;
            win|=!(solve(u,e.fi,e.se,f^1));
        }
    }
    
    return dp[u][v][c][f]=win;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;char c;cin>>a>>b>>c;
        a--;b--;
        int d=int(c-'a');
        G[a].push_back(mp(b,d));
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<26;k++){
                solve(i,j,k,0);
                solve(i,j,k,1);
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(dp[i][j][0][0]) cout<<'A';
            else cout<<'B';
        }
        cout<<"\n";
    }
}