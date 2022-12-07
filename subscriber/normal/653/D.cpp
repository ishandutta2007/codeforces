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

int n, m, x;
int a[555], b[555], c[555];

vector<pair<int, int> > v[555];
vector<int> rev[555];

int d[555], u[555];


int q[555], q1, q2;

void ae(int x, int y, int f) {
	v[x].pb(mp(y, f));
	v[y].pb(mp(x, 0));

	rev[x].pb(v[y].size() - 1);
	rev[y].pb(v[x].size() - 1);
}


int go(int x, int o) {
	if (x == n - 1 || o == 0) return o;

	while (u[x] < v[x].size()) {
		int to = v[x][u[x]].F;
		if (d[x] + 1 != d[to]) {
			u[x]++;
			continue;
		}
		int t = go(to, min(o, v[x][u[x]].S));

		if (t == 0) {
			u[x]++;
			continue;
		}
		v[x][u[x]].S -= t;
		v[to][rev[x][u[x]]].S += t;

		return t;
	}
	return 0;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--;
		b[i]--;
	}		

	double l = 0;
	double r = 1e9 + 1;

	for (int it = 0; it < 200; it++) {
		double mid = (l + r) / 2;

		for (int i = 0; i < n; i++) {
			v[i].clear();
			rev[i].clear();
		}
		for (int i = 0; i < m; i++) ae(a[i], b[i], (int)min(1e9, (c[i] / mid)));

		int flow = 0;
		for(;;) {
			for (int i = 0; i < n; i++) d[i] = -1;
			d[0] = 0;
			q1 = q2 = 0;
			q[q1++] = 0;

			while (q1 != q2) {
				int x = q[q2++];
				for (int i = 0; i < v[x].size(); i++) if (v[x][i].S > 0) {
					int to = v[x][i].F;
					if (d[to] != -1) continue;
					d[to] = d[x] + 1;
					q[q1++] = to;
				}
			}
			if (d[n - 1] == -1) break;
			for (int i = 0; i < n; i++) u[i] = 0;
			for(;;) {
				int t = go(0, (int)1e9 + 1);
				flow += t;
				if (t == 0 || flow >= x) break;
			}
			if (flow >= x) break;
		}
		if (flow < x) r = mid; else l = mid;
	}
	l = (l + r) / 2;
	l *= x;

	printf("%.10lf\n", l);

	return 0;
}