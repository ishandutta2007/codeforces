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
vector<pii> gp[MAX_N+1];
ll ans;
ll dp[MAX_N+1][5];
pii p[MAX_N+1];


void dfs(int x){
	for(pii i : gp[x]){
		if(i.first==p[x].first)	continue;
		p[i.first].first = x;
		p[i.first].second = i.second;
		dfs(i.first);
		if(i.second){
			ans += (2 + dp[x][0] + 2 * dp[x][2] + dp[x][3]) * (dp[i.first][2]);
			ans += (1 + dp[x][2]) * (dp[i.first][0] + dp[i.first][3]);
			dp[x][2] += dp[i.first][2];
			dp[x][3] += dp[i.first][0] + dp[i.first][3];
		}else{
			ans += (2 + 2 * dp[x][0] + dp[x][1] + dp[x][2]) * dp[i.first][0];
			ans += (1 + dp[x][0]) * (dp[i.first][1] + dp[i.first][2]);
			dp[x][0] += dp[i.first][0];
			dp[x][1] += dp[i.first][1] + dp[i.first][2];
		}
	}
	if(p[x].second){
		dp[x][2]++;
	}else{
		dp[x][0]++;
	}
}


int main(){
	scanf("%d", &N);
	for(int i=1; i<N; i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		gp[a].pb({b, c});
		gp[b].pb({a, c});
	}
	dfs(1);
	cout<<ans;
	return 0;
}