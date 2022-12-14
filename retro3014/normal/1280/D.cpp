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
const int MAX_N = 3000;

int T;
int N, M;
int C[MAX_N+1];
vector<int> gp[MAX_N+1];
bool vst[MAX_N+1];
pll dp[MAX_N+1][MAX_N+1];
int sz[MAX_N+1], p[MAX_N+1];
pll d[MAX_N+1];

void dfs(int x){
	vst[x] = true;
	sz[x] = 1;
	for(int i : gp[x]){
		if(!vst[i]){
			p[i] = x;
			dfs(i);
			sz[x] += sz[i];
		}
	}
	if(sz[x]==1){
		dp[x][0] = {0, C[x]};
		if(C[x]>0){
			dp[x][1] = {1, 0};
		}else{
			dp[x][1] = {0, 0};
		}
		//cout<<x<<endl;
		//cout<<dp[x][0].second<<endl;
		return;
	}else{
		dp[x][0] = {0, 0};
		for(int i=1; i<=sz[x]; i++){
			dp[x][i] = {0, -INFLL};
		}
		sz[x] = 0;
		for(int i : gp[x]){
			if(p[i]!=x)	continue;
			for(int k=0; k<=sz[x]+sz[i]; k++){
				d[k] = {0, -INFLL};
			}
			for(int k=0; k<=sz[x]; k++){
				for(int j=0; j<=sz[i]; j++){
					if(d[k+j]<(pll){dp[x][k].first+dp[i][j].first, dp[x][k].second+dp[i][j].second}){
						d[k+j]=(pll){dp[x][k].first+dp[i][j].first, dp[x][k].second+dp[i][j].second};
					}
				}
			}
			sz[x]+=sz[i];
			for(int k=0; k<=sz[x]; k++){
				dp[x][k] = d[k];
			}
		}
		for(int i=sz[x]; i>=0; i--){
			dp[x][i] = {dp[x][i].first, dp[x][i].second+C[x]};
			if(dp[x][i].second>0){
				if(dp[x][i+1]<(pll){dp[x][i].first+1, (ll)0}){
					dp[x][i+1] = (pll){dp[x][i].first+1, (ll)0};
				}
			}else{
				if(dp[x][i+1]<(pll){dp[x][i].first, 0}){
					dp[x][i+1] = (pll){dp[x][i].first, 0};
				}
			}
		}
		sz[x]++;
		///cout<<x<<endl;
		//for(int i=0; i<=sz[x]; i++){
		//	cout<<i<<" "<<dp[x][i].first<<" "<<dp[x][i].second<<endl;
		//}
	}
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &M);
		for(int i=1; i<=N; i++){
			scanf("%d", &C[i]);
		}
		for(int i=1; i<=N; i++){
			int x; scanf("%d", &x); C[i] = x - C[i];
		}
		for(int i=1; i<N; i++){
			int a, b; scanf("%d%d", &a, &b);
			gp[a].pb(b); gp[b].pb(a);
		}
		dfs(1);
		if(dp[1][M-1].second>0){
			printf("%lld\n", dp[1][M-1].first+1);
		}else{
			printf("%lld\n", dp[1][M-1].first);
		}
		for(int i=1; i<=N; i++){
			while(!gp[i].empty())	gp[i].pop_back();
			vst[i] = false;
		}
	}
	return 0;
}