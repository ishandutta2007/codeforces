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
#define N 311111

#define TASK "1"

using namespace std;

vector<int> v[N], ch[N];
vector<pair<int, int> > z[N];
int n, m;

int d[N];


void dfs(int x, int pr, int de) {
	d[x] = de;
	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i];
		if (to != pr) {
			dfs(to, x, de + 1);
			ch[x].pb(to);
		}
	}
}


long long dp[N];

set<pair<long long, int > > Q[N];
long long ad[N];
int bad = 0;

void calc(int x) {
	if (ch[x].size() == 0) {
		ad[x] = 0;
		for (int i = 0; i < z[x].size(); i++) Q[x].insert(mp(z[x][i].S, z[x][i].F));
		while (Q[x].size() > 0 && (*Q[x].begin()).S >= d[x]) Q[x].erase(Q[x].begin());
		if (Q[x].size() == 0) {
			bad = 1;
			dp[x] = 0;
		} else {
			dp[x] = ad[x] + (*Q[x].begin()).F;
		}
		return;
	}
	for (int i = 0; i < ch[x].size(); i++) calc(ch[x][i]);
	long long sum = 0;
	for (int i = 0; i < ch[x].size(); i++) {
		sum += dp[ch[x][i]];
	}
	int la = -1;
	for (int i = 0; i < ch[x].size(); i++) {
		ad[ch[x][i]] += sum - dp[ch[x][i]];
		if (la == -1 || Q[ch[x][i]].size() > Q[la].size()) la = ch[x][i];
	}

	for (int i = 0; i < ch[x].size(); i++) if (ch[x][i] != la) {
		int u = ch[x][i];
		for (auto it = Q[u].begin(); it != Q[u].end(); ++it) {
			long long cost = (*it).F + ad[u] - ad[la];
			Q[la].insert(mp(cost, (*it).S));
		}
	}
	for (int i = 0; i < z[x].size(); i++) {
		long long cost = z[x][i].S + sum - ad[la];
		Q[la].insert(mp(cost, z[x][i].F));
	}
	swap(Q[la], Q[x]);
	ad[x] = ad[la];
	while (Q[x].size() > 0 && (*Q[x].begin()).S >= d[x]) Q[x].erase(Q[x].begin());
	if (Q[x].size() == 0) {
		bad = 1;
		dp[x] = 0;
	} else {
		dp[x] = ad[x] + (*Q[x].begin()).F;
	}
}


int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(0, 0, 0);
	for (int i = 0; i < m; i++) {
		int x, y, co;
		scanf("%d%d%d", &x, &y, &co);
		x--;
		y--;
		if (d[x] < d[y]) swap(x, y);

		z[x].pb(mp(d[y], co));
	}

	long long ans = 0;
	for (int i = 0; i < v[0].size(); i++) {
		calc(v[0][i]);
		ans += dp[v[0][i]];
	}
	if (bad) {
		cout << -1 << endl;
		return 0;
	}
	cout << ans << endl;

	return 0;
}