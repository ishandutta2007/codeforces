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
const int MAX_N = 200000;

int N, K;
vector<int> gp[MAX_N+1];
int sz[MAX_N+1];
int lv[MAX_N+1];
vector<int> vt;
ll ans;
int p[MAX_N+1];

void dfs(int x){
	for(int i : gp[x]){
		if(i==p[x])	continue;
		p[i] = x;
		lv[i] = lv[x]+1;
		dfs(i);
		sz[x]+=sz[i];
	}
	vt.pb({lv[x]-1 - sz[x]});
	sz[x]++;
}


int main(){
	scanf("%d%d", &N, &K);
	for(int i=1; i<N; i++){
		int a, b; scanf("%d%d", &a, &b);
		gp[a].pb(b); gp[b].pb(a);
	}
	lv[1] = 1;
	dfs(1);
	sort(vt.begin(), vt.end());
	while(K--){
		ans+=(ll)vt.back();
		vt.pop_back();
	}
	printf("%lld", ans);
	return 0;
}