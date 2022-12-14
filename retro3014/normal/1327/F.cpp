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

const int MOD = 998244353;
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 500000;
const int MAX_K = 30;

int N, K, M;
struct S{
	int x, y, z;
};

ll ans = 1;
vector<S> vt[MAX_K+1];
bool chk[MAX_N+1];
int cnt[MAX_N+1];
ll dp[MAX_N+1], sum[MAX_N+1];
vector<int> gp[MAX_N+1];

int main(){
	scanf("%d%d%d", &N, &K, &M);
	for(int i=1; i<=M; i++){
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		for(int j=0; j<K; j++){
			vt[j].pb({a, b, c%2});
			c/=2;
		}
	}
	for(int k=0; k<K; k++){
		for(int i=1; i<=N; i++)	cnt[i] = 0;
		for(S now : vt[k]){
			if(now.z==1){
				cnt[now.x]++;
				if(now.y!=N)	cnt[now.y+1]--;
			}else{
				gp[now.y].pb(now.x);
			}
		}
		int mn = 0;
		dp[0] = 1;
		sum[0] = 1;
		for(int i=1; i<=N; i++){
			cnt[i]+=cnt[i-1];
			if(cnt[i]!=0){
				chk[i] = true;
			}else{
				chk[i] = false;
			}
			if(chk[i]){
				dp[i] = 0;
			}else{
				dp[i] = (sum[i-1]-((mn==0)?0:sum[mn-1]) + MOD) % MOD;
			}
			sum[i] = (sum[i-1]+dp[i]) % MOD;
			while(!gp[i].empty()){
				mn = max(gp[i].back(), mn); gp[i].pop_back();
			}
		}
		ll n = (sum[N]-((mn==0)?0:sum[mn-1]) + MOD) % MOD;
		ans = (ans * n) % MOD;
	}
	printf("%lld", ans);
	return 0;
}