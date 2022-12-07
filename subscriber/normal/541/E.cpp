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
#define N 411111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, m;
vector<int> v[N];
int was[N], comp[N];

int d[N], la[N];
int q[N];
int q1, q2;

int be[N];

int bad;
int x[N], y[N];

void go(int x) {

	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i];
		if (was[to] == 0) {
			was[to] = was[x] ^ 3;
			go(to);
		} else {
			if (was[to] == was[x]) bad = 1;
		}
	}
}

void col(int x, int o) {
	if (comp[x] != -1) return;
	comp[x] = o;
	for (int i = 0; i < v[x].size(); i++) col(v[x][i], o);
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x[i], &y[i]);
		x[i]--;
		y[i]--;
		v[x[i]].pb(y[i]);
		v[y[i]].pb(x[i]);
	}
	bad = 0;
	for (int i = 0; i < n; i++) if (was[i] == 0) {
		was[i] = 1;
		go(i);
	}
	for (int i = 0; i < n; i++) comp[i] = -1;
	int comps = 0;
	for (int i = 0; i < n; i++) if (comp[i] == -1) {
		col(i, comps);
		comps++;
	}

	if (bad) {
		puts("-1");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		q1 = q2 = 0;
		d[i] = 0;
		la[i] = i + 1;

		int h = 0;
		q[q1++] = i;
		while (q1 != q2) {
			int x = q[q2++];
			for (int ii = 0; ii < v[x].size(); ii++) {
				int to = v[x][ii];
				if (la[to] != i + 1) {
					la[to] = i + 1;
					d[to] = d[x] + 1;
					h = max(h, d[to]);
					q[q1++] = to;
				}
			}
		}
		be[comp[i]] = max(be[comp[i]], h);
	}
	int ans = 0;
	for (int i = 0; i < comps; i++) ans += be[i];
	cout << ans << endl;
	return 0;
}