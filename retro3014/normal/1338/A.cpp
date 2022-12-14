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
vector<ll> v;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		while(!v.empty())	v.pop_back();
		ll mx;
		ll d = 0;
		for(int i=1; i<=N; i++){
			ll x; scanf("%lld", &x);
			if(i==1){
				mx = x;
			}else{
				d = max(d, mx-x);
				mx = max(x, mx);
			}
			v.pb(x);
		}
		int ans = 1;
		ll t = 1LL;
		if(d==0){
			printf("0\n");
			continue;
		}
		while(1){
			if(d<=2LL*t-1){
				printf("%d\n", ans);
				break;
			}
			ans++;
			t*=2LL;
		}
	}
	return 0;
}