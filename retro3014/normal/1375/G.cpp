#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define test 1
#define TEST if(test)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 200000;

int N;
vector<int> gp[MAX_N+1];

int lv[MAX_N+1];
int dp[2][MAX_N+1];
int p[MAX_N+1];
int up[2][MAX_N+1];

ll ans=INFLL;

void dfs(int x){
	for(int i : gp[x]){
		if(i==p[x])	continue;
		p[i] = x;
		lv[i] = lv[x]+1;
		dfs(i);
		dp[0][x]+=dp[1][i];
		dp[1][x]+=dp[0][i]+1;
	}
	
}

void dfs2(int x){
	for(int i : gp[x]){
		if(i==p[x])	continue;
		up[0][i] = up[1][x]+dp[1][x]-1-dp[0][i];
		up[1][i] = up[0][x]+dp[0][x]-dp[1][i]+1;
		dfs2(i);
	}
}

int main(){
	scanf("%d", &N);
	for(int i=1; i<N; i++){
		int a, b; scanf("%d%d", &a, &b);
		gp[a].pb(b); gp[b].pb(a);
	}
	dfs(1);
	dfs2(1);
	for(int i=1; i<=N; i++){
		//cout<<i<<" "<<dp[0][i]<<" "<<up[0][i]<<endl;
		ans = min(ans, (ll)dp[0][i]+(ll)up[0][i]);
	}
	cout<<ans;
	return 0;
}