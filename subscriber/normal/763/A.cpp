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
#define N 211111

#define TASK "1"

using namespace std;

int n;
int c[N], cnt[N], pr[N], ok[N], sz[N];
vector<int> v[N];

void dfs(int x, int p) {
	ok[x] = 1;
	sz[x] = 1;
	pr[x] = p;
	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i];
		if (to == p) continue;
		dfs(to, x);
		if (!ok[to]) ok[x] = 0;
		if (c[to] != c[x]) ok[x] = 0;
		sz[x] += sz[to];
	}
}

void out(int x) {
	cout << "YES\n";
	cout << x << endl;
	exit(0);
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	for (int i = 0; i < n; i++) cin >> c[i];

	for (int i = 0; i < n; i++) cnt[c[i]]++;
	dfs(0, 0);

	for (int i = 0; i < n; i++) {
		int bad = 0;
		for (int j = 0; j < v[i].size(); j++) {
			int to = v[i][j];
			if (to != pr[i]) {
				if (!ok[to]) bad = 1;
			}
		}
			if (!bad && i != 0) {
				int col = c[pr[i]];
				int need = n - sz[i];

				int all = cnt[col];
				for (int j = 0; j < v[i].size(); j++) {
					int to = v[i][j];
					if (to != pr[i] && c[to] == col) all -= sz[to];
				}
				if (c[i] == col) all--;
				if (all != need) bad = 1;
			}
		if (!bad) out(i + 1);
	}
	cout << "NO\n";


	return 0;
}