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
const int MAX_N = 100005;

int N;
vector<int> v;
int dp[2][MAX_N+1];

int ans=0, t=1;

int main(){
	scanf("%d", &N);
	v.pb(0);
	for(int i=0; i<N; i++){
		int x; scanf("%d", &x);
		v.pb(x);
	}
	v.pb(0);
	dp[0][0] = (1<<30)-1;
	for(int i=1; i<=N; i++){
		dp[0][i] = (dp[0][i-1] & (~v[i]));
	}
	dp[1][N+1] = (1<<30)-1;
	for(int i=N; i>=1; i--){
		dp[1][i] = (dp[1][i+1] & (~v[i]));
	}
	for(int i=1; i<=N; i++){
		//cout<<v[i]<<" "<<((dp[0][i-1] & dp[1][i+1]) & v[i])<<endl;
		if(((dp[0][i-1] & dp[1][i+1]) & v[i])>ans){
			ans = ((dp[0][i-1] & dp[1][i+1]) & v[i]);
			t = i;
		}
	}
	printf("%d ", v[t]);
	for(int i=1; i<=N; i++){
		if(i!=t){
			printf("%d ", v[i]);
		}
	}
	return 0;
	return 0;
}