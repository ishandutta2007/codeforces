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
const int MAX_N = 3000;
const int MAX_K = 15;
int N;
vector<int> gp[MAX_N+1];
int lv[MAX_N+1], up[MAX_N+1][MAX_K+1], p[MAX_N+1];
ll dp[MAX_N+1][MAX_N+1];
ll sz[MAX_N+1];

void dfs(int x){
	sz[x] = 1LL;
	up[x][0] = p[x];
	for(int i=1; i<MAX_K; i++){
		up[x][i] = up[up[x][i-1]][i-1];
	}
	for(int i : gp[x]){
		if(i==p[x])	continue;
		lv[i] = lv[x]+1;
		p[i] = x;
		dfs(i);
		sz[x]+=sz[i];
	}
}

int dist(int x, int y){
	int ret = 0;
	for(int i=MAX_K-1; i>=0; i--){
		if(lv[up[x][i]]>=lv[y]){
			ret+=(1<<i);
			x = up[x][i];
		}
		if(lv[up[y][i]]>=lv[x]){
			ret+=(1<<i);
			y = up[y][i];
		}
	}
	if(x==y)	return ret;
	for(int i=MAX_K-1; i>=0; i--){
		if(up[x][i]!=up[y][i]){
			x = up[x][i];
			y = up[y][i];
			ret+=(1<<(i+1));
		}
	}
	return ret+2;
}

struct S{
	int d, x, y;
	bool operator <(const S &a)const{
		return d<a.d;
	}
};

vector<S> v;

int lca(int x, int y){
	for(int i=MAX_K-1; i>=0; i--){
		if(lv[up[x][i]]>=lv[y]){
			x = up[x][i];
		}
		if(lv[up[y][i]]>=lv[x]){
			y = up[y][i];
		}
	}
	if(x==y)	return x;
	for(int i=MAX_K-1; i>=0; i--){
		if(up[x][i]!=up[y][i]){
			x = up[x][i];
			y = up[y][i];
		}
	}
	return up[x][0];
}

int upk(int x, int y){
	for(int i=MAX_K-1; i>=0; i--){
		if(y>=(1<<i)){
			y-=(1<<i);
			x = up[x][i];
		}
	}
	return x;
}

ll ans;

int main(){
	scanf("%d", &N);
	for(int i=1; i<N; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		gp[a].pb(b); gp[b].pb(a);
	}
	lv[1] = 1; dfs(1);
	for(int i=1; i<=N; i++){
		for(int j=i+1; j<=N; j++){
			v.pb({dist(i, j), i, j});
		}
	}
	sort(v.begin(), v.end());
	for(S now : v){
		if(now.d==1){
			if(p[now.x]==now.y){
				dp[now.x][now.y] = sz[now.x] * ((ll)N - sz[now.x]);
			}else{
				dp[now.x][now.y] = sz[now.y] * ((ll)N - sz[now.y]);
			}
		}else{
			int l = lca(now.x, now.y), l2;
			if(l==now.x){
				l2 = upk(now.y, now.d-1);
				dp[now.x][now.y] = max(dp[now.x][p[now.y]], dp[l2][now.y]) + sz[now.y]*((ll)N-sz[l2]);
			}else if(l==now.y){
				l2 = upk(now.x, now.d-1);
				dp[now.x][now.y] = max(dp[now.y][p[now.x]], dp[l2][now.x]) + sz[now.x]*((ll)N-sz[l2]);
			}else{
				dp[now.x][now.y] = max(dp[now.x][p[now.y]], dp[p[now.x]][now.y]) + sz[now.x]*sz[now.y];
			}
		}
		dp[now.y][now.x] = dp[now.x][now.y];
		ans = max(ans, dp[now.x][now.y]);
		//cout<<now.x<<" "<<now.y<<" "<<dp[now.x][now.y]<<endl;
	}
	cout<<ans;
	return 0;
}