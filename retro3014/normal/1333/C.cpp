#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
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
const int MAX_N = 200000;

int N;
ll arr[MAX_N+1], sum[MAX_N+1];
map<ll, int> mp;

int main(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%lld", &arr[i]);
		sum[i] = sum[i-1] + arr[i];
	}
	int mx = 0;
	mp[0] = 1;
	ll ans = 0;
	for(int i=1; i<=N; i++){
		mx = max(mx, mp[sum[i]]);
		ans += (ll)(i-mx);
		mp[sum[i]] = i+1;
	}
	printf("%lld", ans);
	return 0;
}