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
const ll INFLL = 1e12;
const int MAX_N = 300000;

int N;
vector<ll> v;
ll cnt[2];
ll dp[MAX_N+1][3];

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		ll x; scanf("%lld", &x); v.pb(x);
		if(i%2){
			cnt[0]+=(x+1)/2;
			cnt[1]+=x/2;
		}else{
			cnt[0]+=x/2;
			cnt[1]+=(x+1)/2;
		}
	}
	cout<<min(cnt[0], cnt[1]);
	/*

	dp[0][0] = 0;
	dp[0][1] = -INFLL;
	dp[0][2] = -INFLL;
	for(int i=0; i<N; i++){
		ll x; scanf("%lld", &x); v.pb(x);
		if(i!=0){
			dp[i][0] = max(dp[i-1][0] + v[i-1]/2, max(dp[i-1][1] + (v[i-1]-1)/2, dp[i-1][2] + (v[i-1]-2)/2));
			dp[i][1] = max(dp[i-1][0] + (v[i-1]-1)/2 + 1, dp[i-1][2] + 1 + (v[i-1]-2)/2);
			dp[i][2] = max(dp[i-1][0] + (v[i-1]-2)/2 + 1, dp[i-1][1] + 1 + (v[i-1]-2)/2);
			if(v[i]==1){
				dp[i][2] = -INFLL;
			}
			//cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
		}
	}
	dp[N-1][0] += v[N-1]/2;
	dp[N-1][1] += (v[N-1]-1)/2;
	dp[N-2][2] += (v[N-1]-2)/2;
	printf("%lld", max(dp[N-1][0], max(dp[N-1][1], dp[N-1][2])));
	*/
	return 0;
}