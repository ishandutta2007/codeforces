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
#define M 1000000007
#define N 411111
using namespace std;
typedef pair<int,int> pt;

int n, m;
int a[N], l[N], r[N], d[N], ans[N];
int c[21][N];
pair<pt, int> p[N];
int u[N];
int s[N];
vector<pt> v[N];
int st[21][N];
int lg[N];

void gg(int it) {
	sort(p, p + n + n);
	int e = 0;
	for (int i = 0; i < n + n; i++) {
		if (i == 0 || p[i - 1].F != p[i].F) e++;
		c[it][p[i].S] = e;
	}
}

int lcp(int x, int y) {
	int r = 0;
	for (int i = 18; i >= 0; i--) {
		if (x + pw(i) > n + n) continue;
		if (y + pw(i) > n + n) continue;
		if (c[i][x] != c[i][y]) continue;
		x += pw(i);
		y += pw(i);
		r += pw(i);
	}
	return r;
}

void add(int x) {
	x++;
	while (x <= n) {
		s[x]++;
		x = x + x - (x & (x - 1));	
	}
}

int find(int x) {
	x++;
	if (x > n) x = n;
	int r = 0;
	while (x > 0) {
		r += s[x];
		x &= x - 1;
	}
	return r;
}

int fm(int x, int y) {
	if (x == y) return 1e9;
	y--;
	int w = lg[y - x + 1];
	return min(st[w][x], st[w][y - pw(w) + 1]);

}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n;
	lg[1] = 0;
	for (int i = 2; i <= n + n; i++) lg[i] = lg[i / 2] + 1;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = n - 1; i > 0; i--) a[i] = a[i] - a[i -1];
	for (int i = 0; i < n; i++) a[i + n] = -a[i];
	a[n] = 2e9 + 1;
	for (int i = 0; i < n + n; i++) p[i] = mp(mp(a[i], 0), i);
	gg(0);
	for (int i = 1; pw(i) <= n + n; i++) {
		for (int j = 0; j < n + n; j++) p[j] = mp(mp(c[i - 1][j], c[i - 1][j + pw(i - 1)]), j);
		gg(i);
	}	
	for (int i = 0; i < n + n; i++) if (p[i].S >= n) u[p[i].S - n] = i;
	for (int i = 0; i < n + n - 1; i++) st[0][i] = lcp(p[i].S, p[i + 1].S);
	for (int it = 1; (1 << it) <= n + n; it++) {
		for (int i = 0; i < n + n; i++) st[it][i] = min(st[it - 1][i], st[it - 1][i + pw(it - 1)]);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &l[i], &r[i]);
		d[i] = r[i] - l[i] + 1;
		l[i]--;
		r[i]--;
		if (l[i] == r[i]) {
			ans[i] = n - 1;
			continue;
		}
		int x = u[l[i] + 1];
		int left = x;
		int right = x;
		for (int j = 18; j >= 0; j--) if (right + pw(j) < n + n && fm(x, right + pw(j)) >= r[i] - l[i]) right += pw(j);
		for (int j = 18; j >= 0; j--) if (left - pw(j) >= 0 && fm(left - pw(j), x) >= r[i] - l[i]) left -= pw(j);
		v[right].pb(mp(i, 1));
		if (left >= 0) 
			v[left - 1].pb(mp(i, -1));

	}
	for (int i = 0; i < n + n; i++) {
		if (p[i].S < n) add(p[i].S);
		for (int j = 0; j < v[i].size(); j++) {
//			cout << v[i][j].F << " " << v[i][j].S << endl;
			int L = r[v[i][j].F] - d[v[i][j].F] * 2 + 2;
			int R = r[v[i][j].F] + 1;
			int t = find(n - 1) - find(R) + find(L);
			if (L >= 0) t -= find(0);
			ans[v[i][j].F] += t * v[i][j].S;
		}
	}
	for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
	return 0;
}