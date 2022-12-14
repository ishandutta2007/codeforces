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

const ll MOD = 1000000007;
const ll INF = 1e7;
const ll INFLL = 1e18;
const int MAX_N = 1;

int T, N;
ll P;
vector<ll> vt;

ll multi(ll x, ll y){
	if(y==0)	return 1LL;
	if(y==1LL)	return x%MOD;
	ll m = multi(x, y/2);
	if(y%2){
		return (m*m%MOD)*x%MOD;
	}return (m*m)%MOD;
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%lld", &N, &P);
		for(int i=1; i<=N; i++){
			ll x; scanf("%lld", &x);
			vt.pb(x);
		}
		ll ans = 0LL;
		sort(vt.begin(), vt.end());
		ll diff = 0LL;
		ll prv = 0LL;
		while(!vt.empty()){
			ll n = vt.back();
			ll x = multi(P, vt.back()); vt.pop_back();
			if(prv!=n){
				ll t = prv-n;
				while(diff!=0 && P!=1LL && t--){
					if(INF/P<=diff){
						diff = INF;
						break;
					}else{
						diff *= P;
					}
				}
			}
			prv = n;
			if(diff==0LL){
				ans=(ans+x)%MOD;
				diff++;
			}else{
				ans = (ans +MOD-x)%MOD;
				diff--;
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}