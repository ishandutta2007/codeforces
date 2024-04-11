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
const int MAX_N = 300000;

vector<pii> gp[MAX_N+1];
int N, T;

ll ans1=0, ans2=0;
int sz1[MAX_N+1], sz2[MAX_N+1], sz[MAX_N+1];
pii p[MAX_N+1];
bool vst[MAX_N+1];
void dfs(int x){
	sz1[x] = sz2[x] = sz[x] = 1;
	vst[x] = true;
	for(pii i : gp[x]){
		if(!vst[i.first]){
			p[i.first] = {x, i.second};
			dfs(i.first);
			sz1[x] += sz1[i.first];
			sz2[x] += sz2[i.first];
			sz[x] += sz[i.first];
		}
	}
	sz1[x] = (sz1[x] % 2);
	sz2[x] = min(sz2[x], N-sz[x]);
	ans1 += (ll)sz1[x] * (ll)p[x].second;
	ans2 += (ll)sz2[x] * (ll)p[x].second;
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		N*=2;
		for(int i=1; i<N; i++){
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			gp[a].pb({b, c}); gp[b].pb({a, c});
		}
		dfs(1);
		printf("%lld %lld\n", ans1, ans2);
		ans1 = ans2 = 0;
		for(int i=1; i<=N; i++){
			while(!gp[i].empty())	gp[i].pop_back();
			vst[i] = false;
			sz1[i] = sz2[i] = sz[i] = 0;
		}
	}
	return 0;
}