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

set<pair<int, int> > ed;

vector<int> v[N];
int mark[N], q[N], d[N];
int q1, q2;
int ans[N];
int n, m;

int cont(int x, int y) {
	if (x == y) return 1;
	return ed.find(mp(x, y)) != ed.end();
}

void check(vector<int> a) {
	for (int i = 0; i < a.size(); i++) for (int j = 0; j < i; j++) if (!cont(a[i], a[j])) {
		cout << "NO\n" << endl;
		exit(0);
	}
}
void check(vector<int> a, vector<int> b) {
	for (int i = 0; i < a.size(); i++) for (int j = 0; j < b.size(); j++) if (!cont(a[i], b[j])) {
		cout << "NO\n" << endl;
		exit(0);
	}
}


void go(vector<int> a, int o, int vv) {
	o += vv;
	for (int i = 0; i < a.size(); i++) ans[a[i]] = o;
	set<int> w;
	for (int i = 0; i <a.size(); i++) {
		int x = a[i];
		for (int j = 0; j < v[x].size(); j++) if (!mark[v[x][j]]) w.insert(v[x][j]);
	}
	if (w.size() == 0) return;
	vector<int> ww;
	for (auto it = w.begin(); it != w.end(); it++) ww.pb(*it);

	check(a, ww);

	for (int i = 0; i <ww.size(); i++) mark[ww[i]] = 1;
	check(ww);
	go(ww, o, vv);
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
		ed.insert(mp(x, y));
		ed.insert(mp(y, x));
	}
	if (m == n * 1ll * (n - 1) / 2) {
		cout << "YES\n";
		for (int i = 0; i < n;i++) cout << 1 << " ";
		return 0;
	}
	int st = -1;
	for (int i = 0; i < n; i++) if (v[i].size() != n - 1) st = i;
	for (int i = 0; i < n; i++) d[i] = -1;
	d[st] = st;

	q[q1++] = st;
	while (q1 != q2) {
		int x = q[q2++];
		for (int i = 0; i < v[x].size(); i++) {
			int to = v[x][i];
			if (d[to] != -1) continue;
			d[to] = x;
			q[q1++] = to;
		}
	}
	int a, b, c;
	for (int i = 0; i < n;i++) if (d[i] != st && d[d[i]] == st) {
		a = st;
		b = d[i];
		c = i;
		break;
	}

	vector<int> aa, bb, cc;

	mark[b] = 1;
	bb.pb(b);

	for (int i = 0; i < v[b].size(); i++) {
		int q = v[b][i];
		mark[q] = 1;
		if (cont(q, a)) {
			if (cont(q, c)) {
				bb.pb(q);
			} else aa.pb(q);
		} else cc.pb(q);
	}
	check(aa);
	check(bb);
	check(cc);

	check(bb, aa);
	check(bb, cc);

	for (int i = 0; i < bb.size(); i++) ans[bb[i]] = 1000000;

	go(aa, 1000000, 1);
	go(cc, 1000000, -1);

	cout << "YES\n";
	for (int i = 0; i < n; i++) cout << ans[i] << " ";



	return 0;
}