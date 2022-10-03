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
int dp[MAX];
int k;
ll res=0;

void DFS(int u,int p){
    for(int to:G[u]){
        if(to==p) continue;
        DFS(to,u);
        res+=min(dp[to],2*k-dp[to]);
        dp[u]+=dp[to];
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N>>k;
    for(int i=0;i<2*k;i++){
        int a;cin>>a;
        a--;
        dp[a]=1;
    }
    
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    DFS(0,-1);
    
    cout<<res<<endl;
}