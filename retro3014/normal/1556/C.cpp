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
const int MAX_N = 1000;

int N;
vector<ll> v;

int main(){	
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		int x; scanf("%d", &x);
		v.pb((ll)x);
	}
	ll ans = 0;
	for(int i=0; i<N; i+=2){
		ll sum = 1LL;
		ll mx = (ll)v[i]-1LL;
		for(int j=i+1; j<N; j+=2){
			ll l = 1LL, r = v[j];
			l = max(l, sum);
			r = min(r, sum+mx);
			if(r>=l)	ans+=(r-l+1);
			sum-=v[j];
			if(sum<0){
				if(sum+mx<0){
					break;
				}
				mx+=sum;
				sum = 0;
			}
			if(j+1<N){
				sum+=v[j+1];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}