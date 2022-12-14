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

map<ll, int> mp;

int T;
int N;
ll B[MAX_N+1];
ll sum[MAX_N+1];
vector<int> v[MAX_N+1];
int dp[MAX_N+1];
vector<ll> vt;

int fidx(ll x){
	int s = 0, e = (int)vt.size()-1, m;
	while(s<e){
		m = (s+e)/2;
		if(vt[m]==x)	return m;
		else	if(vt[m]>x)	e = m-1;
		else s = m+1;
	}
	if(s>e)	return -1;
	if(x==vt[s])	return s;
	return -1;
}

int main(){
	scanf("%d", &T);
	while(T--){
		mp.clear();
		vt.clear();
		scanf("%d", &N);
		for(int i=1; i<=N; i++){
			scanf("%lld", &B[i]);
			sum[i] = sum[i-1] + B[i];
			vt.pb(sum[i]-B[i]);
		}
		sort(vt.begin(), vt.end());
		vt.erase(unique(vt.begin(), vt.end()), vt.end());
		dp[1] = 1;
		v[fidx(sum[1]-B[1])].pb(1);
		int S = 1;
		for(int i=2; i<=N; i++){
			dp[i] = S;
			S = (S + dp[i]) % MOD;
			int idx = fidx(sum[i-1]);
			if(idx!=-1){
				while(!v[idx].empty()){
					int t = v[idx].back(); v[idx].pop_back();
					S = (S + MOD - dp[t]) % MOD;
				}
			}
			v[fidx(sum[i]-B[i])].pb(i);
		}
		int ans = 0;
		for(int i=0; i<vt.size(); i++){
			while(!v[i].empty()){
				int t = v[i].back(); v[i].pop_back();
				ans = (ans + dp[t]) % MOD;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}