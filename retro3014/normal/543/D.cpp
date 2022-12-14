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
int p[MAX_N+1];
ll dp[MAX_N+1];
ll dp2[MAX_N+1];
ll ans[MAX_N+1];

ll multi(ll x, ll y){
	if(y==1)	return x%MOD;
	if(y==0)	return 1;
	ll m = multi(x, y/2);
	if(y%2){
		return (((m*m)%MOD)*x)%MOD;
	}
	return (m*m)%MOD;
}

ll inv(ll x){
	return multi(x, MOD-2);
}

void dfs1(int x){
	dp[x] = 1;
	for(int i : gp[x]){
		dfs1(i);
		dp[x] = (dp[x] * dp2[i]) % MOD;
	}
	dp2[x] = (dp[x]+1) % MOD;
}

void dfs2(int x, ll y){
	ans[x] = y;
	int cnt = 0;
	for(int i : gp[x]){
		if(dp2[i]==0){
			cnt++;
		}
		else	ans[x] = (ans[x] * dp2[i]) % MOD;
	}
	for(int i : gp[x]){
		ll t;
		if(dp2[i]==0){
			if(cnt==1){
				t = ans[x];
			}else{
				t = 0;
			}
		}
		else{
			if(cnt>0){
				t = 0;
			}
			else t = (ans[x] * inv(dp2[i]))%MOD;
		}
		dfs2(i, (t+1)%MOD);
	}
	if(cnt>0)	ans[x] = 0;
}

int main(){
	scanf("%d", &N);
	for(int i=2; i<=N; i++){
		int a; scanf("%d", &a);
		gp[a].pb(i); p[i] = a;
	}
	dfs1(1);
	dfs2(1, 1);
	for(int i=1; i<=N; i++){
		printf("%lld ", ans[i]);
	}
	return 0;
}