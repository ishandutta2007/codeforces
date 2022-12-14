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
const int MAX_N = 1;

ll N;
ll ans = 0;

ll multi(ll x, ll y){
	if(y==0)	return 1LL;
	if(y==1)	return x%MOD;
	ll m = multi(x, y/2);
	if(y%2)	return (m*m%MOD)*x%MOD;
	return (m*m)%MOD;
}

int main(){
	scanf("%lld", &N);
	for(ll k=1; k<=N; k++){
		ans = 0LL;
		if(k<=N-2){
			ll add = (N-k-1) % MOD;
			add = (add * 810LL) % MOD;
			add = (add * multi(10, N-k-2)) % MOD;
			ans = (ans + add) % MOD;
		}
		if(k!=N){
			ll add = (180LL * multi(10LL, N-k-1)) % MOD;
			ans = (ans + add) % MOD;
		}else{
			ans = 10;
		}
		printf("%lld ", ans);

	}
	return 0;
}