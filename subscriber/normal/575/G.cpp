#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
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
typedef pair<int,int> pt;

int n, m;
vector<pair<int, int > > v[N];

pair<int, int> go[N];
int d[N];
int pr[N], ch[N];
int id[N];
int ww[N];

int Q[N];
int q1, q2;

int dd[N];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		v[x].pb(mp(y, z));
		v[y].pb(mp(x, z));
	}
	for (int i = 0; i < n; i++) ww[i] = -1;
	dd[n - 1] = 0;
	Q[q1++] = n - 1;
	ww[n - 1] = n - 1;
	while (q1 != q2) {
		int x = Q[q2++];
		for (int i = 0; i < v[x].size(); i++) if (v[x][i].S == 0) {
			int to = v[x][i].F;
			if (ww[to] == -1) {
				dd[to] = dd[x] + 1;
				ww[to] = x;
				Q[q1++] = to;
			}			
		}
	}

	for (int i = 0; i < n; i++) d[i] = -1, go[i] = mp(1e9, 1e9);
	vector<int> q;
	q.pb(0);
	d[0] = 0;

	int gg = -1;

	if (ww[0] != -1) gg = 0;
	
	while (gg == -1) {
		vector<int> qq;
		for (int i = 0; i < q.size(); i++) {
			int x = q[i];

			for (int j = 0; j < v[x].size(); j++) {
				int to = v[x][j].F;
				if (d[to] == -1) {
					pair<int, int> tt = mp(v[x][j].S, id[x]);
					if (tt < go[to]) {
						go[to] = tt;
						pr[to] = x;
						ch[to] = v[x][j].S;
					}
				}
			}
		}
		for (int i = 0; i < q.size(); i++) {
			int x = q[i];

			for (int j = 0; j < v[x].size(); j++) {
				int to = v[x][j].F;
				if (d[to] == -1) {
					d[to] = d[x] + 1;
					qq.pb(to);
				}
			}
		}
		vector<pair<pair<int, int>, int> > p;
		for (int i = 0; i < qq.size(); i++) p.pb(mp(go[qq[i]], qq[i]));
		sort(p.begin(), p.end());
		int e = 0;
		for (int i = 0; i < p.size(); i++) {
			if (i > 0 && p[i].F != p[i - 1].F) e++;
			id[p[i].S] = e;
		}
		q = qq;

		for (int i = 0; i < q.size(); i++) if (ww[q[i]] != -1) {
			if (gg == -1 || id[q[i]] < id[gg] || (id[q[i]] == id[gg] && dd[q[i]] < dd[gg])) gg = q[i];
		}

	}
	vector<int> C, X;

	int y = gg;
	while (y != n - 1) {
		y = ww[y];
		X.pb(y);
	}
	reverse(X.begin(), X.end());


	int x = gg;
	while (x != 0) {
		X.pb(x);
		C.pb(ch[x]);
		x = pr[x];
	}
	X.pb(x);
	reverse(X.begin(), X.end());

	if (C.size() == 0) C.pb(0);
	for (int i = 0; i < C.size(); i++) printf("%d", C[i]);
	puts("");
	cout << X.size() << endl;
	for (int i = 0; i < X.size(); i++) {
		printf("%d", X[i]);
		if (i + 1 == X.size()) puts(""); else putchar(' ');
	}
	
	return 0;
}