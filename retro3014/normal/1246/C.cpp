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
#define test 0
#define TEST if(test)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 2010;

int N, M;
ll dp[MAX_N+1][MAX_N+1][2];
ll sum[MAX_N+1][MAX_N+1][2];
string str[MAX_N+1];
int cnt[MAX_N+1][MAX_N+1][2];



int main(){
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++){
		cin>>str[i];
		for(int j=0; j<M; j++){
			if(str[i][j]=='R'){
				cnt[i][j][0] = cnt[i][j][1] = 1;
			}
		}
	}
	for(int i=N-1; i>=0; i--){
		for(int j=M-1; j>=0; j--){
			cnt[i][j][0] += cnt[i+1][j][0];
			cnt[i][j][1] += cnt[i][j+1][1];
		}
	}
	for(int i=N-1; i>=0; i--){
		for(int j=M-1; j>=0; j--){
			if(i==N-1 && j==M-1){
				dp[i][j][0] = dp[i][j][1] = 1;
			}else if(i==N-1){
				if(cnt[i][j+1][1]==0){
					dp[i][j][1] = 1;
				}
			}else if(j==M-1){
				if(cnt[i+1][j][0]==0){
					dp[i][j][0] = 1;
				}
			}else{
				int t = cnt[i+1][j][0];
				TEST cout<<t<<" ";
				dp[i][j][0] = (sum[i+1][j][0] - sum[N-t][j][0] + MOD) % MOD;
				TEST cout<<t<<" ";
				t = cnt[i][j+1][1];
				dp[i][j][1] = (sum[i][j+1][1] - sum[i][M-t][1] + MOD) % MOD;
			}
			sum[i][j][0] = dp[i][j][1];
			if(i!=N-1)	sum[i][j][0] += sum[i+1][j][0];
			sum[i][j][1] = dp[i][j][0];
			if(j!=M-1)	sum[i][j][1] += sum[i][j+1][1];
			TEST cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<" "<<sum[i][j][0]<<" "<<sum[i][j][1]<<" "<<cnt[i][j][0]<<" "<<cnt[i][j][1]<<endl;
		}
	}
	if(N==1 && M==1){
		if(str[0][0]=='R'){
			printf("0");
		}else{
			printf("1");
		}
		return 0;
	}
	cout<<(dp[0][0][0] + dp[0][0][1]) % MOD;
	return 0;
}