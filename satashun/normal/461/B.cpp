#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

#define pb push_back
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)

const ll MOD = 1000000007LL;

int n;
int x[100010];
vector<int> g[100010];
ll dp[100010][2];

void dfs(int v){
    bool f = true;
    for(int to : g[v]){
	dfs(to);
	if(f){
	    if(x[v] == 1){
		dp[v][0] = 0;
		dp[v][1] = (dp[to][0] + dp[to][1]) % MOD;
	    }else{
		dp[v][0] = (dp[to][0] + dp[to][1]) % MOD;
		dp[v][1] = dp[to][1];
	    }

	    f = false;
	}else{

	    ll a = 0, b = 0;
	    if(x[v] == 0){
		rep(i, 2) a = (a + (dp[v][0] * dp[to][i])) % MOD;
		rep(i, 2) rep(j, 2) if(i + j) b = (b + (dp[v][i] * dp[to][j])) % MOD;

		dp[v][0] = a;
		dp[v][1] = b;
	    }else{
		rep(i, 2)  a = (a + (dp[v][1] * dp[to][i])) % MOD;	    
		dp[v][1] = a;	    
	    }
	}
    }


    if(g[v].size() == 0){
	dp[v][1] = x[v];
	dp[v][0] = !x[v];
    }
}

int main(){
    scanf("%d", &n);

    rep(i, n - 1){
	int p;
	scanf("%d", &p);
	g[p].pb(i + 1);
    }

    rep(i, n) scanf("%d", &x[i]);
    dfs(0);
    printf("%I64d\n", dp[0][1]);
    
    return 0;
}