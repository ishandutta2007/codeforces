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
#define N 511111

#define TASK "1"

using namespace std;

int n, m;
vector<int> v[N];
vector<int> vv[N];
int mi[N];
int ans[N];

set<int> have[N];

int d[N];


void dfs(int x, int p, int de) {
	d[x] = de;
	for (int i = 0; i < vv[x].size(); i++) if (vv[x][i] != p) dfs(vv[x][i], x, de+ 1);
	
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			x--;
			v[x].pb(i);
		}
	}
	for (int i = 0; i < n; i++) mi[i] = 0;

	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		vv[x].pb(y);
		vv[y].pb(x);
	}

	dfs(0, 0, 0);
	vector<pair<int, int> > e;
	for (int i = 0; i < m; i++) {
		int rr = 1e9 + 1;
		for (int j = 0; j < v[i].size(); j++) rr = min(rr, d[v[i][j]]);
		e.pb(mp(rr, i));
	}
	sort(e.begin(), e.end());

	int ret = 0;
	for (int i = 0; i < m; i++) {
		int id = e[i].S;

		int t = 0;
		for (int j = 0; j < v[id].size(); j++) {
			int x = v[id][j];

			while (have[x].find(mi[x]) != have[x].end()) mi[x]++;

			t = max(t, mi[x]);
		}
		ans[id] = t;
		ret = max(ret, t);

		for (int j = 0; j < v[id].size(); j++) have[v[id][j]].insert(t);
	}

	cout << ret + 1 << endl;
	for (int i = 0; i < m; i++) cout << ans[i] + 1 << " ";

	return 0;
}