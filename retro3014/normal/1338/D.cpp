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
const int MAX_N = 100000;

int N;
int dp1[2][2][MAX_N+1]; 
int dp2[2][MAX_N+1];
int dp3[2][MAX_N+1];
int dp4[MAX_N+1];

vector<int> gp[MAX_N+1];
int p[MAX_N+1];
int ans;

void dfs(int x){
	for(int i : gp[x]){
		if(i==p[x])	continue;
		p[i] = x;
		dfs(i);
		ans = max(ans, dp1[0][0][x]+dp2[1][i] + max(0, dp4[x]-2));
		ans = max(ans, dp1[1][0][x]+dp2[0][i] + max(0, dp4[x]-2));
		for(int j=0; j<2; j++){
			if(dp1[j][0][x]<dp2[j][i]){
				dp1[j][1][x] = dp1[j][0][x];
				dp1[j][0][x] = dp2[j][i];
			}else if(dp1[j][1][x]<dp2[j][i]){
				dp1[j][1][x] = dp2[j][i];
			}
		}
	}
	dp2[0][x] = max(dp1[0][0][x], dp1[1][0][x]) + max(0, dp4[x] - 2);
	dp2[0][x] = max(dp2[0][x], dp4[x]-1);
	dp2[1][x] = 1 + dp1[0][0][x];
}

void dfs2(int x){
	ans = max(ans, dp1[0][0][x]+dp3[1][x] + max(0, dp4[x]-2));
	ans = max(ans, dp1[1][0][x]+dp3[0][x] + max(0, dp4[x]-2));
	for(int j=0; j<2; j++){
		if(dp1[j][0][x]<dp3[j][x]){
			dp1[j][1][x] = dp1[j][0][x];
			dp1[j][0][x] = dp3[j][x];
		}else if(dp1[j][1][x]<dp3[j][x]){
			dp1[j][1][x] = dp3[j][x];
		}
	}
	for(int i : gp[x]){
		if(i==p[x])	continue;
		if(dp1[0][0][x]==dp2[0][i]){
			dp3[1][i] = 1 + dp1[0][1][x];
			dp3[0][i] = dp1[0][1][x] + max(0, dp4[x]-2);
		}else{
			dp3[1][i] = 1 + dp1[0][0][x];
			dp3[0][i] = dp1[0][0][x] + max(0, dp4[x]-2);
		}
		if(dp1[1][0][x]==dp2[1][i]){
			dp3[0][i] = max(dp3[0][i], dp1[1][1][x] + max(0, dp4[x]-2));
		}else{
			dp3[0][i] = max(dp3[0][i], dp1[1][0][x] + max(0, dp4[x]-2));
		}
		dfs2(i);
	}
	ans = max(ans, dp1[0][0][x]+dp1[0][1][x]+1);
	ans = max(ans, dp1[1][0][x]+dp1[1][1][x] + max(0, dp4[x]-2));
	ans = max(ans, dp1[1][0][x] + max(0, dp4[x]-1));
	ans = max(ans, dp4[x]);
}

int main(){
	scanf("%d", &N);
	for(int i=1; i<N; i++){
		int a, b; scanf("%d%d", &a, &b);
		gp[a].pb(b); gp[b].pb(a);
	}
	for(int i=1; i<=N; i++){
		dp4[i] = (int)gp[i].size();
	}
	dfs(1);
	dfs2(1);
	// for(int i=1; i<=N; i++){
	// 	cout<<dp2[0][i]<<" "<<dp2[1][i]<<endl;
	// }
	printf("%d", ans);
	return 0;
}