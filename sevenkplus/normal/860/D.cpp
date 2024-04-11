#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<int, PII> PI3;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 200010
#define INF 1000000007

int n, m;
set<int> A[N];
int d[N];
set<PII> q;
int a[N], L;
vector<PI3> S;
int fa[N];

void ff1(int x) {
	for (set<int>::iterator i = A[x].begin(); i != A[x].end(); i ++)
		if (d[*i] == INF) {
			fa[*i] = x;
			d[*i] = d[x]+1;
			ff1(*i);
		}
}

void add(int x, int y, int z) {
	S.pb(mp(x, mp(y, z)));
	A[x].erase(y);
	A[x].erase(z);
	A[y].erase(x);
	A[z].erase(x);
}

void gg(int x) {
	set<int> e; // extra
	for (set<int>::iterator i = A[x].begin(); i != A[x].end();) {
		set<int>::iterator i1 = i;
		i1++;
		if (fa[*i] == x) gg(*i);
		i = i1;
	}
	for (set<int>::iterator i = A[x].begin(); i != A[x].end(); i ++)
		if (d[*i] > d[x]) e.insert(*i);
	while (e.size() >= 2) {
		int y = *e.begin();
		e.erase(y);
		int z = *e.begin();
		e.erase(z);
		add(x, y, z);
	}
	if (!e.empty() && fa[x] != -1) {
		int y = *e.begin();
		int z = fa[x];
		add(x, y, z);
	}
}

void ff(int x0) {
	d[x0] = 0;
	fa[x0] = -1;
	ff1(x0);
	gg(x0);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i ++) d[i] = INF;
	for (int i = 0; i < m; i ++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		A[x].insert(y);
		A[y].insert(x);
	}
	for (int i = 0; i < n; i ++)
		if (d[i] == INF) ff(i);
	printf ("%d\n", (int) S.size());
	for (int i = 0; i < (int) S.size(); i ++)
		printf ("%d %d %d\n", S[i].se.fi+1, S[i].fi+1, S[i].se.se+1);
	return 0;
}