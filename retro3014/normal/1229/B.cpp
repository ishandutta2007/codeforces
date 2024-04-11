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

const ll MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 100000;
const int MAX_K = 20;

int N;
ll cost[MAX_N+1];
vector<int> gp[MAX_N+1];
ll ans = 0;

int up[MAX_N+1][MAX_K+1];
ll num[MAX_N+1][MAX_K+1];

ll gcd(ll x, ll y){
	return (y==0 ? x : gcd(y, x%y));
}
int idx;

void dfs(int x){
	for(int j=1; j<MAX_K; j++){
		up[x][j] = up[up[x][j-1]][j-1];
		num[x][j] = gcd(num[x][j-1], num[up[x][j-1]][j-1]);
	}
	ll now = cost[x];
	idx = x;
	while(1){
		ll cnt = 1;
		for(int j=MAX_K-1; j>=0; j--){
			if(up[idx][j]!=0){
				if(now==0){
					if(num[idx][j]==0){
						cnt += (1<<j);
						idx = up[idx][j];
					}
				}
				else if(num[idx][j] % now == 0){
					cnt += (1<<j);
					idx = up[idx][j];
				}
			}
		}
		//cout<<idx<<" "<<now<<" "<<cnt<<endl;
		ans = (ans + (((now % MOD) * cnt) % MOD)) % MOD;
		if(idx==1)	break;
		idx = up[idx][0];
		now = gcd(now, cost[idx]);
	}


	for(int i : gp[x]){
		if(i==up[x][0])	continue;
		up[i][0] = x;
		num[i][0] = gcd(cost[i], cost[x]);
		dfs(i);
	}
}

int main(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%lld", &cost[i]);
	}
	for(int i=1; i<N; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		gp[a].pb(b); gp[b].pb(a);
	}
	dfs(1);
	cout<<ans;
	return 0;
}