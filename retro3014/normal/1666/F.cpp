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
 
const int MOD = 998244353;
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_M = 2500;
const int MAX_N = 5000;

int T;
int N;
ll ncr[MAX_N+1][MAX_N+1];
vector<int> vt;
vector<int> vn;

ll dp[MAX_M+1], ndp[MAX_M+1];


void init(){
	ncr[0][0] = 1LL;
	ncr[1][0] = ncr[1][1] = 1LL;
	for(int i=2; i<=MAX_M; i++){
		ncr[i][0] = 1LL;
		ncr[i][i] = 1LL;
		for(int j=1; j<i; j++){
			ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]) % MOD;
		}
	}
}


int main(){
	scanf("%d", &T);
	init();
	while(T--){
		scanf("%d", &N);
		vt.clear();
		vn.clear();
		for(int i=0; i<N; i++){
			int x; scanf("%d", &x);
			vt.pb(x);
		}
		sort(vt.begin(), vt.end());
		while(!vt.empty()){
			int t = vt.back(); vt.pop_back();
			int cnt = 1;
			while(!vt.empty()){
				if(vt.back()==t){
					cnt++;
					vt.pop_back();
				}else{
					break;
				}
			}
			vn.pb(cnt);
		}
		for(int i=0; i<=N/2; i++){
			dp[i] = ndp[i] = 0;
		}
		dp[0] = 1LL;
		int s = 0;
		for(int ii=0; ii<vn.size(); ii++){
			int n = vn[ii];
			for(int e=0; e<=min(s, N/2); e++){
				if(dp[e]==0)	continue;
				int o = s-e;
				int l = e-1-o;
				if(e==0)	l = 0;
				if(l<0)	continue;
				if(e==N/2){
					l++;
				}
				// 1. no even
				if(n <= l){
					ndp[e] = (ndp[e] + (dp[e] * ncr[l][n] % MOD)) % MOD;
				}
				// 2. one even
				if(n-1 <= l){
					ndp[e+1] = (ndp[e+1] + (dp[e] * ncr[l][n-1] % MOD)) % MOD;
				}
			}
			s+=n;
			//cout<<ii<<" "<<n<<endl;
			for(int e=0; e<=min(s, N/2); e++){
				//if(ndp[e]!=0)	cout<<e<<" "<<ndp[e];
				dp[e] = ndp[e];
				ndp[e] = 0LL;
			}
			//cout<<endl;
		}
		printf("%lld\n", dp[N/2]);
	}
	return 0;
}