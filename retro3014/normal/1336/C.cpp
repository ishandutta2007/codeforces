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

const ll MOD = 998244353;
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 3000;

string S, T;
int N, M;

ll dp[MAX_N+1], ndp[MAX_N+1];
vector<pll> query[MAX_N+1];

ll two[MAX_N+1];
ll ans;

int main(){
	two[0] = 1LL;
	for(int i=1; i<=MAX_N; i++)		two[i] = (two[i-1]  * 2LL) % MOD;
	cin>>S>>T;
	N = (int)S.size();
	M = (int)T.size();
	for(int i=0; i<M; i++){
		dp[i] = 1LL;
	}
	for(int l=1; l<=M; l++){
		for(int i=0; i<=M-l; i++){
			int j = i+l;
			//cout<<i<<" "<<j<<endl;
			if(i!=0 && S[l-1]==T[i-1]){
				ndp[i-1] = (ndp[i-1] + dp[i]) % MOD;
			}
			if(S[l-1]==T[j-1]){
				if(j==M){
					//cout<<"!"<<i<<" "<<dp[i]<<endl;
					if(l==N && i==0){
						ans = (ans + dp[i]) % MOD;
					}
					query[l].pb({i, dp[i]});
				}else{
					ndp[i] = (ndp[i] + dp[i]) % MOD;
				}
			}
		}
		///cout<<l<<endl;
		for(int i=0; i<=M-l; i++){
			dp[i] = ndp[i];
			//cout<<dp[i]<<" ";
			ndp[i] = 0LL;
		}//cout<<endl;
	}
	for(int i=0; i<=M; i++)	dp[i] = ndp[i] = 0LL;
	dp[0] = 1LL;
	for(int i=N-1; i>=0; i--){
		char c = S[i];
		for(int j=0; j<M; j++){
			if(c==T[j]){
				if(j==M-1){
					//cout<<"%"<<i<<endl;
					ll t = (dp[j] * two[i]) % MOD;
					//cout<<dp[j]<<" "<<two[i]<<endl;
					ans = (ans + t) % MOD;
				}else{
					ndp[j+1] = (ndp[j+1] + dp[j]) % MOD;
				}
			}
		}
		for(int j=0; j<M; j++){
			dp[j] = (ndp[j] + dp[j]) % MOD;
			ndp[j] = 0LL;
		}
		dp[0]++;
		//cout<<"*"<<i<<endl;
		while(!query[i].empty()){
			pll now = query[i].back(); query[i].pop_back();
			//cout<<now.first<<" "<<now.second<<endl;
			//cout<<dp[now.first]<<endl;
			ll add = (dp[now.first] * now.second) % MOD;
			ans = (ans + add) % MOD;
		}
	}
	printf("%lld", ans);
	return 0;
}