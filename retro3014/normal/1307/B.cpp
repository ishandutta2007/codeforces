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

int T;
int N;
ll X;
vector<ll> v;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%lld", &N, &X);
		ll ans = INFLL;
		while(!v.empty())	v.pop_back();
		for(int i=0; i<N; i++){
			ll x; scanf("%lld", &x); v.pb(x);
			if(x==X){
				ans = 1LL;
			}else if(x>X){
				ans = min(ans, 2LL);
			}else{
				ans = min(ans, (X+x-1)/x);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}