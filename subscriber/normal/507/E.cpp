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
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, m;
vector<pair<int , int> > v[N];
vector<int> id[N];

pair<int, int> d[N];
int f[N];

int pr[N], pr2[N];

int x[N], y[N], z[N];

int on[N];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &x[i], &y[i], &z[i]);
		x[i]--;
		y[i]--;
		z[i] = 1 - z[i];

		v[x[i]].pb(mp(y[i], z[i]));
		v[y[i]].pb(mp(x[i], z[i]));

		id[x[i]].pb(i);
		id[y[i]].pb(i);
	}

	for (int i = 0; i < n; i++) d[i] = mp((int)1e9, (int) 1e9);
	d[0] = mp(0, 0);
	priority_queue<pair<pt, int> > Q;
	Q.push(mp(mp(0,0), 0));

	for(;;) {
		while (Q.size() > 0 && f[Q.top().S]) Q.pop();
		if (Q.size() == 0) break;
		int x = Q.top().S;
		f[x] = 1;
		for (int i = 0; i < v[x].size(); i++) {
			int to = v[x][i].F;
			int d1 = d[x].F + 1;
			int d2 = d[x].S;
			if (v[x][i].S) d2++; else d2--;
			if (mp(d1,d2) < d[to]) {
				d[to] = mp(d1, d2);
				pr[to] = x;

				pr2[to] = id[x][i];

				Q.push(mp(mp(-d1, -d2), to));
			}
		}
	}
	int g = n - 1;
	while (g > 0) {
//		ans.pb(mp(mp(g, pr[g]), pr2[g]));
		on[pr2[g]] = 1;
		g = pr[g];
	}
	vector<int> ans;
	for (int i = 0; i < m; i++) if (on[i] == z[i]) ans.pb(i);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d %d\n", x[ans[i]] + 1, y[ans[i]] + 1, z[ans[i]]); 
	}

	return 0;
}