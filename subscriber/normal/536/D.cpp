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
vector<pair<int, int> > v[N];
long long dd[N];
int f[N];


int next[2][2200];
int g1[2][2200][2200];
long long g2[2][2200][2200];

int was[2200][2200][2][2];
long long mem[2200][2200][2][2];

int c1[2200];
long long c2[2200];

int p[N];
             	
vector<pair<int, long long> > ps(int s) {
	for (int i = 0; i < n; i++) dd[i] = 1e18, f[i] = 0;
	dd[s] = 0;
	
	vector<pair<int, long long> > ret;

	for(;;) {
		int x = -1;
		long long mi = 1e18;
		for (int i = 0; i < n; i++) if (f[i] == 0 && dd[i] < mi) {
			x = i;
			mi = dd[i];
		}
		if (x == -1) break;
		ret.pb(mp(x, mi));

		f[x] = 1;
		for (int i = 0; i < v[x].size(); i++) {
			long long dist = dd[x] + v[x][i].S;
			if (dist < dd[v[x][i].F]) {
				dd[v[x][i].F] = dist;
			}
		}
	}
	return ret;
}

vector<pair<int, long long> > d[2];

long long solve(int x, int y, int o, int h) {
	if (x == d[o].size() || y == d[1 - o].size()) return 0;

	if (was[x][y][o][h]) return mem[x][y][o][h];

//	if (x == d[o].size()) return solve(y, x, 1 - o, 1);


	int nx = next[o][x];

	int v1 = g1[o][x][y];
	long long v2 = g2[o][x][y];

	int hh = h;
	if (v1 > 0) hh = 0;

	long long ret = solve(nx, y, o, hh) + v2;

	if (hh == 0) {
		ret = max(ret, v2 - solve(y, nx, 1 - o, 1));
	}		

	was[x][y][o][h] = 1;
	mem[x][y][o][h] = ret;

	return ret;
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> m;
	int s, t;
	cin >> s >> t;
	s--;
	t--;
	for (int i = 0; i < n; i++) scanf("%d", &p[i]);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x--;
		y--;
		v[x].pb(mp(y, z));
		v[y].pb(mp(x, z));
	}
	d[0] = ps(s);
	d[1] = ps(t);

/*	for (int o = 0; o < 2; o++) {
		cout << " !" << endl;
		for (int i = 0; i < n; i++) cout << d[o][i].F << " " << d[o][i].S << endl;
	}*/


	for (int o = 0; o < 2; o++) {

		for (int u = 0; u <= n; u++) {
			for (int i = 0; i < n; i++) {
				c1[i] = 0;
				c2[i] = 0;
			}
			for (int i = u; i < n; i++) {
				c1[d[1 - o][i].F] = 1;
				c2[d[1 - o][i].F] = p[d[1 - o][i].F];				
			}
			int v1 = 0;
			long long v2 = 0;
			for (int i = n - 1; i >= 0; i--) {
				if (i + 1 == n || d[o][i].S != d[o][i + 1].S ) {
					next[o][i] = i + 1;
					v1 = 0;
					v2 = 0;
				} else next[o][i] = next[o][i + 1];
				v1 += c1[d[o][i].F];
				v2 += c2[d[o][i].F];
				g1[o][i][u] = v1;
				g2[o][i][u] = v2;
			}

		}

	}

	long long ans = solve(0, 0, 0, 1);
//	cout << ans << endl;

	if (ans > 0) puts("Break a heart"); 
	if (ans < 0) puts("Cry"); 
	if (ans == 0) puts("Flowers");
	return 0;
}