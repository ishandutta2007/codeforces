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
#define N 611111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, m;
int x[N], y[N], l[N];
pair<int, int> q[N];

int p[N], sz[N];
int odd;

vector<int> z, z3;
vector<pair<int, int> > z2;

int ans[N];

int u[N];


void unite(int id) {
	int a = x[id];
	while (p[a] != a) a = p[a];
	int b = y[id];
	while (p[b] != b) b = p[b];
	if (a == b) return;

	if (sz[a] < sz[b]) swap(a, b);

	if (sz[a] % 2 == 1&& sz[b] % 2 == 1) {
		z3.pb(2);
		odd -= 2;
	} else {
		z3.pb(0);
	}

	z2.pb(mp(a, sz[a]));
	sz[a] += sz[b];

	z.pb(b);

	p[b] = a;
}

void backup(int ver) {
	while (z.size() > ver) {
		odd += z3.back();
		z3.pop_back();

		sz[z2.back().F] = z2.back().S;
		z2.pop_back();

		p[z.back()] = z.back();
		z.pop_back();
	}
}

void go(int l, int r, int ll, int rr) {
	if (l > r) return;

	if (odd == 0) {
		puts("!");
	}

	int ver = z.size();

	int mid = (l + r) / 2;
	int nmid = -1;

	for (int i = l; i <= mid; i++) if (u[i] < ll) unite(i);
	if (odd == 0) {
		puts("!");
	}

	for (int i = ll; i <= rr; i++) if (q[i].S <= mid) {
		unite(q[i].S);
		if (odd == 0) {
			nmid = i;
			break;
		}		
	}
	backup(ver);

	if (nmid == -1) {
		for (int i = l; i <= mid; i++) ans[i] = -1;
		for (int i = l; i <= mid; i++) if (u[i] < ll) {
			unite(i);
		}

		go(mid + 1, r, ll, rr);

		backup(ver);
		return;
	}
	ans[mid] = q[nmid].F;

	for (int i = ll; i < nmid; i++) if (q[i].S < l) unite(q[i].S);

	go(l, mid - 1, nmid, rr);
	backup(ver);


	for (int i = l; i <= mid; i++) if (u[i] < ll) unite(i);

	go(mid + 1, r, ll, nmid);

	backup(ver);
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &x[i], &y[i], &l[i]);

		q[i] = mp(l[i], i);
	}
	sort(q, q + m);
	for (int i = 0; i < m; i++) {
		u[q[i].S] = i;
	}
	for (int i = 0; i < n; i++) {
		p[i] = i;
		sz[i] = 1;
	}		
	odd = n;

	go(0, m - 1, 0, m - 1);

	for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
	return 0;
}