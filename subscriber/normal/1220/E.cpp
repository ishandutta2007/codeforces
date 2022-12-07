#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 411111

#define TASK "1"

using namespace std;

int w[N];
vector<int> v[N];
int was[N], good[N];
int n, m;

void dfs(int x, int p) {
	int up = 0;
	good[x] = 0;

	for (int to : v[x]) if (to != p) {
		if (!was[to]) {
			was[to] = 1;
			dfs(to, x);
			if (good[to]) good[x] = 1;
		} else {
			up = 1;
		}
	}
	if (up) good[x] = 1;
}

long long calc(int x, int p) {
	long long ret = 0;
	for (int to : v[x]) if (to != p) ret = max(ret, calc(to, x));
	return ret + w[x];
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> w[i];
	for (int i = 0; i <m; i++) {
		int x, y;
		cin >> x >> y;		
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	int s;
	cin >> s;
	s--;

	was[s] = 1;
	dfs(s, s);
	good[s] = 1;

	long long ans = 0;
	long long best = 0;
	for (int i = 0; i < n; i++) if (good[i]) {
		ans += w[i];
		for (int to : v[i]) if (!good[to]) best = max(best, calc(to, i));
	}
	cout << ans + best << endl;
	return 0;
}