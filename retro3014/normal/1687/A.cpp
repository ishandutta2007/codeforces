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
const int MAX_N = 1000;

int T;
ll N, K;
vector<ll> vt;


int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%lld%lld" ,&N, &K);
		vt.clear();
		for(int i=1; i<=N; i++){
			ll x;
			scanf("%lld", &x);
			vt.pb(x);
		}
		if(K<N){
			ll ans = 0;
			ll sum = 0;
			for(int i=0; i<N; i++){
				sum+=vt[i];
				if(i>=K){
					sum-=vt[i-K];
				}
				ans = max(ans, sum);
			}
			ans += K * (K-1) / 2LL;
			printf("%lld\n", ans);
		}else{
			ll ans = 0;
			for(int i=0; i<N; i++){
				ans += (vt[i] + K);
			}
			ans -= N * (N+1) / 2LL;
			printf("%lld\n", ans);
		}
	}
	return 0;
}