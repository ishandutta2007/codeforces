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
const int MAX_N = 2000;
const int MAX_K = 12;
int N, M;
int L[MAX_N+1];
ll S[MAX_N+1];
ll C[MAX_N*2+1];
ll dp[MAX_N*2+1][(1<<MAX_K)+1];
ll mx[MAX_N*2+1];

vector<pair<pii, ll> > vt;

int main(){
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++){
		scanf("%d", &L[i]);
	}
	for(int i=1; i<=N; i++){
		scanf("%lld", &S[i]);
	}
	for(int i=1; i<=N+M; i++){
		scanf("%lld", &C[i]);
	}
	for(int i=1; i<=N+M; i++){
		for(int j=0; j<(1<<MAX_K); j++){
			dp[i][j] = -INFLL;
		}
		mx[i] = -INFLL;
	}
	dp[1][0] = 0;
	mx[1] = 0;
	for(int i=N; i>=1; i--){
		for(int l=max(1, L[i]-MAX_K+1); l<=L[i]; l++){
			for(int j=0; j<(1<<MAX_K); j++){
				if(dp[l][j]==-INFLL)	continue;
				int nj = (j>>(L[i]-l));
				int t = 0;
				ll n = dp[l][j]+C[L[i]]-S[i];
				while(((1<<t)&nj)!=0){
					t++;
					n+=C[L[i]+t];
				}
				vt.pb({{L[i], nj+1}, n});
			}
		}
		for(int l=1; l<=L[i]-MAX_K; l++){
			if(mx[l]!=-INFLL){
				vt.pb({{L[i], 1}, mx[l]+C[L[i]]-S[i]});
			}
		}
		while(!vt.empty()){
			dp[vt.back().first.first][vt.back().first.second] = max(dp[vt.back().first.first][vt.back().first.second], vt.back().second);
			mx[vt.back().first.first] = max(mx[vt.back().first.first], vt.back().second);
			vt.pop_back();
		}
	}
	ll ans = 0;
	for(int i=1; i<=N+M; i++){
		ans = max(ans, mx[i]);
	}
	printf("%lld", ans);
	return 0;
}