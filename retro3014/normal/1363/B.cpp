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

int T, N;
string str;
int ans;
int dp[MAX_N+1];

int main(){
	scanf("%d", &T);
	while(T--){
		cin>>str;
		N = str.size();
		dp[0] = (str[0]=='0');
		for(int i=1; i<N; i++){
			dp[i] = dp[i-1] + (str[i]=='0');
		}
		ans = min(dp[N-1], N-dp[N-1]);
		int s = dp[N-1];
		for(int i=0; i<N-1; i++){
			ans = min(ans, dp[i] + N-s-(i+1-dp[i]));
			ans = min(ans, i+1-dp[i]+s-dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}