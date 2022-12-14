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
int sz[MAX_N+1], D;
int deg[MAX_N+1];
vector<pii> ans;
int p[MAX_N+1];
int num[MAX_N+1];

void dfs(int x){
	deg[x] = (int)gp[x].size();
	for(int i : gp[x]){
		if(i==p[x])	continue;
		p[i] = x;
		dfs(i);
	}
}

int s[MAX_N+1], e[MAX_N+1];

void dfs2(int x){
	ans.pb({x, num[x]});
	s[x] = max(1, num[x]-deg[x]+1);
	e[x] = s[x]+deg[x]-1;
	for(int i : gp[x]){
		if(i==p[x])	continue;
		if(num[x]==e[x]){
			num[x] = s[x]-1;
			ans.pb({x, num[x]});
		}
		num[i] = num[x]+1;
		dfs2(i);
		num[x]++;
		ans.pb({x, num[x]});
	}
	if(x!=1 && num[x]==e[x]){
		num[x] = s[x]-1;
		ans.pb({x, num[x]});
	}
}

int main(){
	scanf("%d", &N);
	for(int i=1; i<N; i++){
		int a, b; scanf("%d%d", &a, &b);
		gp[a].pb(b); gp[b].pb(a);
	}
	dfs(1);
	dfs2(1);
	printf("%d\n", (int)ans.size());
	for(int i=0; i<ans.size(); i++){
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}