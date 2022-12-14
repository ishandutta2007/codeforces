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
const int MAX_N = 20;
const int MAX_K = (1<<20);

int N, M;
string str[MAX_N+1];
ll cost[MAX_N+1][MAX_N+1];
ll dp[MAX_K+1];

vector<int> v[30];

int main(){
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++){
		cin>>str[i];
	}
	for(int i=1; i<(1<<N); i++)	dp[i] = INF;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%lld", &cost[i][j]);
		}
	}
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			v[str[j][i]-'a'].pb(j);
			int chk = (1<<j);
			for(int t=0; t<(1<<N); t++){
				dp[(t|chk)] = min(dp[t]+cost[j][i], dp[(t|chk)]);
			}
		}
		for(int j=0; j<='z'-'a'; j++){
			if(v[j].empty())	continue;
			ll sum = 0, mx = 0;
			int chk = 0;
			//cout<<i<<" "<<j<<endl;
			for(int k : v[j]){
				//cout<<k<<" ";
				chk += (1<<k);
				sum += cost[k][i];
				mx = max(cost[k][i], mx);
			}
			sum-=mx;
			//cout<<endl<<sum<<endl;
			for(int t=0; t<(1<<N); t++){
				dp[(t|chk)] = min(dp[t]+sum, dp[(t|chk)]);
			}
			while(!v[j].empty())	v[j].pop_back();
		}
	}
	cout<<dp[(1<<N)-1];
	return 0;
}