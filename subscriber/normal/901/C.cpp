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

int p[N];
vector<int> v[N];
int n, m;
int x[N], y[N], d[N];
int no[N];
int h[N];

int pa[20][N], mii[20][N], maa[20][N];

int get(int x) {
	if (p[x] == x) return x;
	return p[x] = get(p[x]);
}

void go(int x, int pr, int dd) {
	pa[0][x] = pr;

	d[x] = dd;
	for (int to : v[x]) if (to != pr) {
		go(to, x, dd + 1);	
	}
} 

int MI, MA;
int lca(int a, int b) {
	if (d[b] > d[a]) swap(a, b);
	for (int i = 19; i >= 0; i--) if (d[pa[i][a]] >= d[b]) {
		MI = min(MI, mii[i][a]);
		MA = max(MA, maa[i][a]);
		a = pa[i][a];
	}
	if (a == b) return a;
	for (int i = 19; i >= 0; i--) if (pa[i][a] != pa[i][b]) {
		MI = min(MI, mii[i][a]);
		MA = max(MA, maa[i][a]);
		MI = min(MI, mii[i][b]);
		MA = max(MA, maa[i][b]);
		a = pa[i][a];
		b = pa[i][b];
	}
	return pa[0][a];
}

long long hh[N], ans[N];
pair<pair<int, int> , pair<int, int> > q[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i];
		x[i]--;
		y[i]--;
	}
	for (int i = 0; i < n; i++) p[i] = i;
	for (int i = 0; i < m; i++) {
		if (get(x[i]) == get(y[i])) {
			no[i] = 1;
			continue;
		}
		v[x[i]].pb(y[i]);
		v[y[i]].pb(x[i]);
		p[get(x[i])] = get(y[i]);
	}
	for (int i = 0; i < n; i++) if (d[i] == 0) {
		go(i, i, 1);
	}
	for (int i = 0; i < n; i++) mii[0][i] = maa[0][i] = i;

	for (int i = 1; i < 20; i++) for (int j = 0; j < n; j++) {
		mii[i][j] = min(mii[i - 1][j], mii[i - 1][pa[i - 1][j]]);
		maa[i][j] = max(maa[i - 1][j], maa[i - 1][pa[i - 1][j]]);
		pa[i][j] = pa[i - 1][pa[i - 1][j]];
	}

	for (int i = 0; i < m; i++) if (no[i]) {
		int a = x[i];
		int b = y[i];
		int mi = min(a, b);
		int ma = max(a, b);

		while (d[a] > d[b]) {
			a = pa[0][a];
			mi = min(mi, a);
			ma = max(ma, a);
		}
		swap(a, b);
		while (d[a] > d[b]) {
			a = pa[0][a];
			mi = min(mi, a);
			ma = max(ma, a);
		}
		while (a != b) {
			a = pa[0][a];
			b = pa[0][b];
			mi = min(mi, a);
			ma = max(ma, a);
			mi = min(mi, b);
			ma = max(ma, b);
		}
		mi = min(mi, a);
		ma = max(ma, a);
	        h[mi] = max(h[mi], n - ma);
	}
	for (int i = n - 1; i > 0; i--) h[i - 1] = max(h[i - 1], h[i]);
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		int bad = n - r - 1;
		q[i] = mp(mp(bad, i), mp(l, r));
	}
	sort(q, q + Q);

	for (int i = 0; i < n; i++) hh[i + 1] = hh[i] + h[i];
	int u = 0;

	for (int i = Q - 1; i >= 0; i--) {
		int bad = q[i].F.F;
		int l = q[i].S.F;
		int r = q[i].S.S;
		while (u < n && h[u] > bad) u++;


		long long bd = 0;

		if (u > r) {
			bd += hh[r + 1] - hh[l];
		} else if (u <= l) {
			bd += (r - l + 1) * 1ll * bad;
		} else {
			bd += hh[u] - hh[l];
			bd += (r - u + 1) * 1ll * bad;
		}
		int len = r - l + 1;

		long long all = (n - l + n - r) * 1ll * len / 2;
		ans[q[i].F.S] = all - bd;
	}
	for (int i = 0; i < Q; i++) cout << ans[i] << endl;

	return 0;
}