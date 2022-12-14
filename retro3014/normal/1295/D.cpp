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
const int MAX_N = 1;

ll x, y;
int T;

ll gcd(ll a, ll b){
	return (a==0)?b:gcd(b%a, a);
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%lld%lld", &x, &y);
		ll g = gcd(x, y);
		ll ans = 1LL;
		y /= g;
		for(ll i = 2; i * i <= y; i++){
			if(y%i==0){
				ans*=(i-1LL); y/=i;
				while(y%i==0){
					ans*=i;
					y/=i;
				}
			}
		}
		if(y!=1){
			ans*=(y-1LL);
		}
		printf("%lld\n", ans);
	}
	return 0;
}