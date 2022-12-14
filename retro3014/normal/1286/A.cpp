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
const int INF = 2e3;
const ll INFLL = 1e18;
const int MAX_N = 100;

int N;
int odd, even;
vector<int> vt;
int com[2][MAX_N+1];
int ans;
vector<int> v;

int dp[2][MAX_N+1][MAX_N+1], ndp[2][MAX_N+1][MAX_N+1];

int main(){
	scanf("%d", &N);
	odd = (N+1)/2; even = N/2;
	for(int i=1; i<=N; i++){
		int x; scanf("%d", &x);
		vt.pb(x);
		if(x!=0){
			if(x%2)	odd--;
			else	even--;
		}
	}
	for(int i=0; i<=N; i++){
		for(int j=0; j<=N; j++){
			dp[0][i][j] = dp[1][i][j] = ndp[0][i][j] = ndp[1][i][j] = INF;
		}
	}
	if(vt[0]==0){
		dp[0][0][1] = 0;
		dp[1][1][0] = 0;
	}else{
		dp[vt[0]%2][0][0] = 0;
	}
	for(int i=1; i<N; i++){
		if(vt[i]==0){
			for(int j=0; j<=N; j++){
				for(int  k=0; k<=N; k++){
					if(k<N)	ndp[0][j][k+1] = min(ndp[0][j][k+1], min(dp[0][j][k], dp[1][j][k]+1));
					if(j<N) ndp[1][j+1][k] = min(ndp[1][j+1][k], min(dp[0][j][k]+1, dp[1][j][k])); 
				}
			}
			for(int j=0; j<=N; j++){
				for(int k=0; k<=N; k++){
					dp[0][j][k] = ndp[0][j][k];
					dp[1][j][k] = ndp[1][j][k];
					ndp[0][j][k] = INF;
					ndp[1][j][k] = INF;
				}
			}
		}else{
			for(int j=0; j<=N; j++){
				for(int k=0; k<=N; k++){
					dp[vt[i]%2][j][k] = min(dp[vt[i]%2][j][k], dp[(vt[i]+1)%2][j][k]+1);
					dp[(vt[i]+1)%2][j][k] = INF;
				}
			}
		}
	}
	cout<<min(dp[0][odd][even], dp[1][odd][even]);
	return 0;
}