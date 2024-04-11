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

const int MOD = 998244353;
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 50;

vector<pll> vt;
int N;
vector<ll> v;
map<ll, int> mp;

ll multi(ll x, ll y){
	if(y==1)	return x%MOD;
	if(y==0)	return 1;
	ll m = multi(x, y/2);
	if(y%2){
		return (m*m%MOD)*x%MOD;
	}
	return m*m%MOD;
}


ll inv[MAX_N*2+1];

ll dp[MAX_N*2+1][MAX_N+1], ndp[MAX_N*2+1][MAX_N+1];
ll num[MAX_N*2+1];
int M;

ll IV = 1LL;

int main(){
	scanf("%d", &N);
	inv[1] = 1;
	for(int i=2; i<=MAX_N*2; i++){
		inv[i] = multi(i, MOD-2);
	}
	for(int i=1; i<=N; i++){
		ll a, b;
		scanf("%lld%lld", &a, &b);
		vt.pb({a, b});
		IV = (IV * multi(b-a+1LL, MOD-2)) % MOD;
		v.pb(a); v.pb(b+1);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i=0; i<v.size(); i++){
		mp[v[i]] = i+1;
		//cout<<v[i]<<" ";
		if(i!=v.size()-1)	num[i+1] = v[i+1]-v[i];
	}//cout<<endl;
	M = v.size();
	for(int i=0; i<vt.size(); i++){
		//cout<<vt[i].first<<" "<<vt[i].second<<endl;
		vt[i].first = mp[vt[i].first];
		vt[i].second = mp[vt[i].second+1]-1;
		//cout<<vt[i].first<<" "<<vt[i].second<<endl;
	}
	dp[M][1] = 1LL;
	for(int i=0; i<vt.size(); i++){
		for(int j=vt[i].first; j<=vt[i].second; j++){
			for(int k=j; k<=M; k++){
				for(int t=1; t<MAX_N; t++){
					if(dp[k][t]!=0){
						if(j==k){
							ndp[j][t] = (ndp[j][t] + dp[k][t]) % MOD;
							ndp[j][t+1] = (ndp[j][t+1] + ((dp[k][t] * (num[j]-(ll)t) % MOD) * inv[t+1] % MOD)) % MOD;
						}else{
							ndp[j][1] = (ndp[j][1] + (dp[k][t] * num[j] % MOD))% MOD;
						}
					}
				}
			}
		}
		for(int j=0; j<=M; j++){
			for(int t=1; t<=MAX_N; t++){
				dp[j][t] = ndp[j][t];
				// if(dp[j][t]!=0){
				// 	cout<<i<<" "<<j<<" "<<t<<" "<<dp[j][t]<<endl;
				// }
				ndp[j][t] = 0LL;
			}
		}
	}
	ll ans = 0;
	for(int i=1; i<=M; i++){
		for(int j=0; j<=MAX_N; j++){
			ans = (ans + dp[i][j]) % MOD;
		}
	}
	ans = (ans * IV) % MOD;
	cout<<ans;
	return 0;
}