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

const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 500;

int N, M, B;
ll MOD;
int cnt[MAX_N+1];

ll dp[2][MAX_N+1][MAX_N+1];

int main(){
	scanf("%d%d%d%lld", &N, &M, &B, &MOD);
	for(int i=1; i<=N; i++){
		scanf("%d", &cnt[i]);
	}
	dp[0][0][0] = 1;
	dp[1][0][0] = 1;
	for(int i=1; i<=N; i++){
		for(int j=0; j<M; j++){
			for(int k=0; k<=B; k++){
				if(k+cnt[i]<=B){
					dp[1][j+1][k+cnt[i]] = (dp[1][j+1][k+cnt[i]] + dp[1][j][k]) % MOD;
				}	
			}
		}
	}
	ll ans = 0;
	for(int j=0; j<=B; j++){
		ans = (ans + dp[1][M][j]) % MOD;
	}
	cout<<ans;
	return 0;
}