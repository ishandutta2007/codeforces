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
const int MAX_N = 1;

ll N, M, L, R;

ll multi(ll x, ll y){
	if(y==0)	return 1LL;
	if(y==1)	return x%MOD;
	ll m = multi(x, y/2);
	if(y%2){
		return (m*m)%MOD*x%MOD;
	}return (m*m)%MOD;
}

ll inv(ll x){
	return multi(x, MOD-2);
}

ll ans;

int main(){
	scanf("%lld%lld%lld%lld", &N, &M, &L, &R);	
	if((N*M)%2==1){
		ans = multi(R-L+1, N*M);
	}else{
		ll o, e;
		if(L%2==R%2){
			ll n = (R-L+1)/2;
			ll r = (R-L+1);
			if(r==0){
				ans = 1LL;
			}else if(r==1){
				ans = (N*M) % MOD;
			}else{
				ans = inv(r-1);
				ans = (ans * ((multi(r, N*M)+MOD-1) % MOD)) % MOD;
			}
			ans = (ans * n) % MOD;
			ans = (ans + 1) % MOD;
		}else{
			ans = multi(R-L+1, N*M-1);
			ans = (ans * ((R-L+1)/2)) % MOD;
		}
	}
	printf("%lld", ans);
	return 0;
}