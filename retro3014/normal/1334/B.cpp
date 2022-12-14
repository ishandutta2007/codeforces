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
ll C;
vector<ll> vt;

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%lld", &N, &C);
		while(!vt.empty())	vt.pop_back();
		for(int i=1; i<=N; i++){
			ll x; scanf("%lld", &x);
			vt.pb(x);
		}
		sort(vt.begin(), vt.end());
		int ans = 0;
		ll sum = 0;
		while(!vt.empty()){
			ans++;
			sum+=vt.back(); vt.pop_back();
			if(sum<C*(ll)ans){
				ans--;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}