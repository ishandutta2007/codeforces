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

const ll MOD = 998244353;
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 300000;

int N;
vector<int> gp[MAX_N+1];

int p[MAX_N+1];
ll dp1[MAX_N+1], dp2[MAX_N+1], dp3[MAX_N+1];

void dfs(int x){
	for(int i : gp[x]){
		if(i==p[x])	continue;
		p[i] = x;
		dfs(i);
	}
	dp1[x] = dp2[x] = dp3[x] = 1;
	for(int i : gp[x]){
		if(i==p[x])	continue;
		dp1[x] = (dp1[x] * ((2LL * dp3[i] + dp2[i] + 2LL * dp1[i]) % MOD)) % MOD;
		dp2[x] = (dp2[x] * ((dp1[i] + dp3[i]) % MOD)) % MOD;		
		dp3[x] = (dp3[x] * ((dp1[i]*2LL + dp3[i]) % MOD)) % MOD;
	}
	dp3[x] = (dp3[x] + MOD - dp2[x]) % MOD;


}

int main(){
	scanf("%d", &N);
	for(int i=1; i<N; i++){
		int a, b; scanf("%d%d", &a, &b);
		gp[a].pb(b); gp[b].pb(a);
	}
	dfs(1);
	ll ans = (dp1[1] + dp3[1] + MOD - 1) % MOD;
	printf("%lld", ans);
	return 0;
}