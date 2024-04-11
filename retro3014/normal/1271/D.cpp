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
const ll INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 5000;

int N ,M, K;
int A[MAX_N+1], B[MAX_N+1], C[MAX_N+1];
vector<int> gp[MAX_N+1];
int t[MAX_N+1];
ll dp[2][MAX_N+10];
int main(){
	scanf("%d%d%d", &N, &M, &K);
	for(int i=1 ;i<=N; i++){
		scanf("%d%d%d", &A[i], &B[i], &C[i]);
		t[i] = i;
	}
	for(int i=0; i<M; i++){
		int a, b; scanf("%d%d", &a, &b);
		t[b] = max(t[b], a);
	}
	for(int i=1; i<=N; i++){
		gp[t[i]].pb(i);
	}
	for(int i=0; i<=MAX_N; i++){
		dp[0][i] = dp[1][i] = -INF;
	}
	dp[0][K] = 0;
	for(int i=1; i<=N; i++){
		for(int j=0; j<A[i]; j++){
			dp[0][j] = -INF;
		}
		for(int j=MAX_N-B[i]; j>=A[i]; j--){
			dp[1][j+B[i]] = dp[0][j]; 
		}
		for(int k : gp[i]){
			ll cost = (ll)C[k];
			for(int j=1; j<=MAX_N; j++){
				if(dp[1][j]!=-INF)	dp[1][j-1] = max(dp[1][j-1], dp[1][j]+cost);
			}
		}
		for(int j=0; j<=MAX_N; j++){
			dp[0][j] = dp[1][j];
			dp[1][j] = -INF;
		}
	}
	ll ans = -INF;
	for(int j=0; j<=MAX_N; j++){
		ans = max(ans, dp[0][j]);
	}
	printf("%lld", max(ans, -1LL));
	return 0;
}