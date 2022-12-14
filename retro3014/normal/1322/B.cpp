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
const int MAX_N = 400000;
const ll MAX_K = 30LL;
int N;
ll arr[MAX_N+1];
ll ans;
vector<ll> v;

int main(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%lld", &arr[i]);
	}
	for(ll k=1LL; k<(1LL<<MAX_K); k*=2LL){
		ll cnt = 0;
		while(!v.empty())	v.pop_back();
		for(int j=1; j<=N; j++){
			v.pb(arr[j]%(k*2LL));
		}
		sort(v.begin(), v.end());
		for(ll j : v){
			//cout<<j<<" ";
			int i1 = (lower_bound(v.begin(), v.end(), k-j) - v.begin());
			int i2 = (lower_bound(v.begin(), v.end(), 2LL*k-j) - v.begin());
			cnt += (ll)(i2-i1);
			i1 = (lower_bound(v.begin(), v.end(),  3LL*k-j) - v.begin());
			i2 = (lower_bound(v.begin(), v.end(), 4LL*k-j) - v.begin());
			cnt += (ll)(i2-i1);
			if(j+j>=k && j+j<2LL*k){
				cnt-=1LL;
			}
			if(j+j>=k*3LL && j+j<4LL*k){
				cnt-=1LL;
			}
		}		cnt = (cnt / 2LL) % 2LL;
		if(cnt==1LL){
			ans+=k;
		}
	}
	printf("%lld", ans);
	return 0;
}