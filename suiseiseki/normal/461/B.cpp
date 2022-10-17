#include <bits/stdc++.h>
using namespace std;
#define Maxn 100000
#define Mod 1000000007
#define ll long long
vector<int> G[Maxn+5];
int n,cor[Maxn+5];
ll dp[Maxn+5][2];
void dfs(int u){
    if(cor[u]){
    	dp[u][1]=1;
	}
    else{
    	dp[u][0]=1;
	}
    for(auto v:G[u]){
        dfs(v);
        dp[u][1]=(dp[u][1]*(dp[v][0]+dp[v][1])%Mod+dp[u][0]*dp[v][1]%Mod)%Mod;
        dp[u][0]=dp[u][0]*(dp[v][0]+dp[v][1])%Mod;
    }
}
void read_and_parse(){
    scanf("%d",&n);
    for(int i=2,fa;i<=n;i++){
        scanf("%d",&fa);
		fa++;
        G[fa].push_back(i);
    }
    for(int i=1;i<=n;i++)scanf("%d",&cor[i]);
}
void solve(){
    dfs(1);
    cout<<dp[1][1]<<endl;
}
int main(){
    read_and_parse();
    solve();
    return 0;
}