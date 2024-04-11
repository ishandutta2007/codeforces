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
const int MAX_N = 300000;

int T;
int N;
ll a[MAX_N+1], b[MAX_N+1];

int main(){
	scanf("%d", &T);
	while(T--){
		ll ans = 0;
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			scanf("%lld%lld", &a[i], &b[i]);
		}
		for(int i=0; i<N; i++){
			ans += max(0LL, a[(i+1)%N]-b[i]);
		}
		ll mn = INFLL;
		for(int i=0; i<N; i++){
			mn = min(mn, min(a[(i+1)%N], b[i]));
		}
		ans += mn;
		printf("%lld\n", ans);
	}
	return 0;
}