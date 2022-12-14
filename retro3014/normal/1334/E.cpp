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
const int MAX_N = 300;

ll D;
int Q;

vector<ll> prime;

ll gcd(ll x, ll y){
	return (x==0)?y:gcd(y%x, x);
}

ll multi(ll x, ll y){
	if(y==0)	return 1;
	if(y==1)	return x%MOD;
	ll m = multi(x, y/2);
	if(y%2){
		return (m*m%MOD)*x%MOD;
	}
	return m*m%MOD;
}

ll iv(ll x){
	return multi(x, MOD-2);
}

int inv[MAX_N+1];
int per[MAX_N+1];

int main(){
	scanf("%lld", &D);
	inv[0] = per[0] = inv[1] = per[1] = 1;
	for(int i=2; i<=MAX_N; i++){
		per[i] = (per[i-1] * (ll)i) % MOD;
		inv[i] = iv(per[i]);
	}
	for(ll i=2; i<=D; i++){
		if(i*i>D)	break;
		if(D%i==0){
			prime.pb(i);
			while(D%i==0)	D/=i;
		}
	}	
	if(D!=1LL)	prime.pb(D);
	scanf("%d", &Q);
	for(int i=1; i<=Q; i++){
		ll a, b; 
		ll ans = 1LL;
		scanf("%lld%lld", &a, &b);
		ll g = gcd(a, b);
		ll s1=0, s2=0;
		for(ll p : prime){
			ll c1=0, c2=0, c3=0;
			while(a%p==0){
				a/=p;
				c1++;
			}
			while(b%p==0){
				b/=p;
				c2++;
			}
			while(g%p==0){
				g/=p;
				c3++;
			}
			s1+=(c1-c3);
			s2+=(c2-c3);
			ans = (ans * inv[c1-c3])% MOD;
			ans = (ans * inv[c2-c3])% MOD;
		}
		ans = (ans * per[s1]) % MOD;
		ans = (ans * per[s2]) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}