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
const int MAX_N = 100000;

int N;
vector<int> gp[MAX_N+1];
vector<int> ans;
ll dp[MAX_N+1][2];
int from[MAX_N+1];
int sz[MAX_N+1];

vector<pii> v;
vector<int> num;

void dfs(int x){
	sz[x]++;
	for(int i : gp[x]){
		dfs(i);
		sz[x] += sz[i];
	}
	if(gp[x].size()==0){
		dp[x][0] = 0;
		dp[x][1] = 1;
		//cout<<x<<" "<<dp[x][0]<<" "<<dp[x][1]<<endl;
		return;
	}else{
		int sum = 0, mn = INF, idx;
		for(int i : gp[x]){
			sum += dp[i][1];
		}
		for(int i : gp[x]){
			if(mn > sum - dp[i][1] + dp[i][0]){
				mn = sum - dp[i][1] + dp[i][0];
				idx = i;
			}
		}
		dp[x][1] = sum+1;
		dp[x][0] = mn;
		from[x] = idx;
	}
	//cout<<x<<" "<<dp[x][0]<<" "<<dp[x][1]<<endl;
}

int add(int x){
	num.pb(x);
	int prv = 0, nxt = 0;
	for(int i : gp[x]){
		nxt = add(i);
		for(int k=0; k<prv; k++){
			ans.pb(i);
		}
		prv = nxt;
	}
	return prv + 1;
}

int main(){
	scanf("%d", &N);
	for(int i=1; i<N; i++){
		int p; scanf("%d", &p);
		gp[p].pb(i);
	}
	dfs(0);
	int idx = 0;
	while(1){
		int prv = 0;
		int nxt = 0;
		num.pb(idx);
		for(int i : gp[idx]){
			if(i==from[idx])	continue;
			nxt = add(i);
			for(int j=0; j<prv; j++){
				ans.pb(i);
			}
			prv = nxt;
		}
		if(from[idx]==0)	break;
		idx = from[idx];
		for(int i=0; i<prv; i++){
			ans.pb(idx);
		}
	}



	for(int i=0; i<num.size(); i++){
		printf("%d ", num[i]);
	}
	printf("\n");
	printf("%d\n", ans.size());
	for(int i=0; i<ans.size(); i++){
		printf("%d ", ans[i]);
	}

	return 0;
}