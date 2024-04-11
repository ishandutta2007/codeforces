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

const ll MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 100000;
const int MAX_K = 300;
const int MAX_T = 20;

int N, Q, K, M, R;
vector<int> gp[MAX_N+1];
ll dp[MAX_K+1];
vector<pii> vt;

int up[MAX_N+1][MAX_T+1], lv[MAX_N+1], p[MAX_N+1];
int in[MAX_N+1], out[MAX_N+1], cnt;

void dfs(int x){
	in[x] = ++cnt;
	for(int i=1; i<MAX_T; i++){
		up[x][i] = up[up[x][i-1]][i-1];
	}
	for(int i : gp[x]){
		if(i==p[x])	continue;
		lv[i] = lv[x]+1;
		p[i] = x;
		up[i][0] = x;
		dfs(i);
	}
	out[x] = cnt;
}

int dist(int x, int y){
	int ret = 0;
	for(int i=MAX_T-1; i>=0; i--){
		if(lv[up[x][i]]>=lv[y]){
			x = up[x][i];
			ret+=(1<<i);
		}
		if(lv[up[y][i]]>=lv[x]){
			y = up[y][i];
			ret+=(1<<i);
		}
	}
	if(x==y)	return ret;
	for(int i=MAX_T-1; i>=0; i--){
		if(up[x][i]!=up[y][i]){
			x = up[x][i];
			y = up[y][i];
			ret+=(1<<(i+1));
		}
	}
	return ret+2;
}



struct SEG{
	struct NODE{
		int l, r;
		int sum;
	};
	int SZ;
	vector<NODE> seg;
	void add(){
		seg.pb({-1, -1, 0});
	}
	void Init(int x){
		SZ = x;
		add();
		init(0, 1, SZ);
	}
	void init(int idx, int s, int e){
		if(s==e)	return;
		seg[idx].l = seg.size(); add();
		seg[idx].r = seg.size(); add();
		init(seg[idx].l, s, (s+e)/2);
		init(seg[idx].r, (s+e)/2+1, e);
	}
	void Update(int x, int y, int z){
		update(0, 1, SZ, x, y, z);
	}
	void update(int idx, int s, int e, int x, int y, int z){
		if(x<=s && e<=y){
			seg[idx].sum+=z;
			return;
		}
		if(x>e || y<s)	return;
		update(seg[idx].l, s, (s+e)/2, x, y, z);
		update(seg[idx].r, (s+e)/2+1, e, x, y, z);
	}
	int Get(int x){
		return get(0, 1, SZ, x);
	}
	int get(int idx, int s, int e, int k){
		if(s==e)	return seg[idx].sum;
		if(k<=(s+e)/2){
			return seg[idx].sum+get(seg[idx].l, s, (s+e)/2, k);
		}else{
			return seg[idx].sum+get(seg[idx].r, (s+e)/2+1, e, k);
		}
	}
}Seg;


int upk(int x, int y){
	for(int i=MAX_T-1; i>=0; i--){
		if(lv[up[x][i]]>=y){
			x = up[x][i];
		}
	}
	return x;
}

int main(){
	scanf("%d%d", &N, &Q);
	Seg.Init(N);
	for(int i=1; i<N; i++){
		int a, b; scanf("%d%d", &a, &b);
		gp[a].pb(b); gp[b].pb(a);
	}
	lv[1] = 1;	 dfs(1);
	while(Q--){
		scanf("%d%d%d", &K, &M, &R);
		while(!vt.empty())	vt.pop_back();
		for(int i=1; i<=K; i++){
			int x; scanf("%d", &x);
			vt.pb({dist(x, R), x});
		}
		sort(vt.begin(), vt.end());
		for(int i=0; i<vt.size(); i++){
			int now = vt[i].second;
			int t = Seg.Get(in[now]);
			if(i==0){
				for(int j=1; j<=M; j++)	dp[j] = 0;
				dp[1] = 1LL;
			}else{
				for(int j=M; j>=1; j--){
					if(j<=t)	dp[j] = 0LL;
					else 	dp[j] = (dp[j-1] + (dp[j] * (ll)(j-t) % MOD)) %MOD;
				}
			}
			if(now==R){
				Seg.Update(1, N, 1);
			}
			else if(in[now]<=in[R] && in[R]<=out[now]){
				t = upk(R, lv[now]+1);
				Seg.Update(1, N, 1);
				Seg.Update(in[t], out[t], -1);
			}else{
				Seg.Update(in[now], out[now], 1);
			}
		}
		for(int i=0; i<vt.size(); i++){
			int now = vt[i].second;
			int t;
			if(now==R){
				Seg.Update(1, N, -1);
			}
			else if(in[now]<=in[R] && in[R]<=out[now]){
				t = upk(R, lv[now]+1);
				Seg.Update(1, N, -1);
				Seg.Update(in[t], out[t], 1);
			}else{
				Seg.Update(in[now], out[now], -1);
			}
		}
		ll ans = 0;
		for(int i=1; i<=M; i++){
			ans = (ans + dp[i]) % MOD;
		}
		printf("%lld\n", ans);

	}
	return 0;
}