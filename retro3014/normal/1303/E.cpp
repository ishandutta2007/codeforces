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
const int MAX_N = 400;

int TC;
string S, T;
int dp[MAX_N+1][MAX_N+1];

int main(){
	scanf("%d", &TC);
	while(TC--){
		cin>>S>>T;
		bool tf = false;
		int idx = 0;
		for(int i=0; i<S.size(); i++){
			if(idx<T.size() && T[idx]==S[i]){
				idx++;
			}
		}
		if(idx==T.size()){
			printf("YES\n");
			continue;
		}
		for(int t=1; t<T.size(); t++){
			dp[0][0] = t;
			for(int i=1; i<=t; i++){
				dp[0][i] = -INF;
			}
			for(int i=1; i<=S.size(); i++){
				for(int j=0; j<=t; j++){
					dp[i][j] = dp[i-1][j];
					if(S[i-1]==T[j-1]){
						dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
					}
					if(dp[i-1][j]>=t && dp[i-1][j]<T.size()){
						if(S[i-1]==T[dp[i-1][j]])	dp[i][j] = max(dp[i][j], dp[i-1][j]+1);
					}
				}
			}
			for(int i=1; i<=S.size(); i++){
				if(dp[i][t]==T.size()){
					tf = true;
					break;
				}
			}
			if(tf)	break;
		}
		if(!tf){
			printf("NO\n");
		}else{
			printf("YES\n");
		}
	}
	return 0;
}