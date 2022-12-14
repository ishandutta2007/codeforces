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
const int MAX_N = 30;

int T;
ll D, MOD;
ll ans;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%lld%lld", &D, &MOD);
		ans = 0LL;
		ll two = 1LL;
		ll sum = 1LL;
		for(int i=0; i<=MAX_N; i++){
			ll n = max(0LL, min(D-two+1LL, two)) % MOD;
			if(i==0){
				sum = (sum + n) % MOD;
				ans = n;
			}else{
				ll t = (sum * n) % MOD;
				ans = (ans + t) % MOD;
				sum = (sum + t) % MOD;
			}
			two*=2LL;
		}
		printf("%lld\n", ans);
	}	
	return 0;
}