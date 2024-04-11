#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <cstddef>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <iterator>
#include <queue>
#include <cassert>
#include <ctime>
#include <iomanip>
#include <bitset>
#include <memory.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;


const int N = 100 * 1000 + 5;
int type[N];
int color[N];
int n;

vector<int> g[N];

inline bool read() {
	scanf("%d", &n);
	forn(i, n) 
	    scanf("%d", &type[i]);
	forn(i, n)
	    scanf("%d", &color[i]);
	forn(i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	return true;
}

const int LOGN = 17;

int tin[N], tout[N];
int T;
int ord[2 * N];
int up[N][LOGN];

void dfs(int v, int p) {
	up[v][0] = p;
	
	for (int i = 1; i < LOGN; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];
	
	tin[v] = T++;
	ord[tin[v]] = v;
	for (int to : g[v])
		if (to != p)
			dfs(to, v);
	tout[v] = T++;
	ord[tout[v]] = v;
}

bool parent(int a, int b) {
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
	if (parent(a, b))
		return a;
	if (parent(b, a))
		return b;
	for (int i = LOGN - 1; i >= 0; --i)
		if (!parent(up[a][i], b))
			a = up[a][i];
	return up[a][0];
}

int a[N];
int b[N];

vector<int> st[2 * N];
vector<int> fin[2 * N];

li ans[N];

int val[N];
int cnt[N][2];

void sw(int v, li & ans) {
	ans -= cnt[color[v]][0] * li(cnt[color[v]][1]);
	if (val[v])
		cnt[color[v]][type[v]]--;
	else
		cnt[color[v]][type[v]]++;
	val[v] ^= 1;
	ans += cnt[color[v]][0] * li(cnt[color[v]][1]);
}

void naive(int l, int r, li & ans) {
	for (int i = l; i <= r; ++i)
		sw(ord[i], ans);
}

inline void solve() {	
	
	vector<int> colors;
	forn (i, n)
		colors.push_back(color[i]);
	sort(all(colors));
	colors.resize(unique(all(colors)) - colors.begin());

	forn(i, n)
		color[i] = lower_bound(all(colors), color[i]) - colors.begin();

	dfs(0, 0);
		
	int m = 0;

	cin >> m;	
	forn(i, m) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
		if (tin[a[i]] > tin[b[i]])
			swap(a[i], b[i]);
		if (parent(a[i], b[i]))
			st[tin[a[i]]].push_back(i);
		else
			st[tout[a[i]]].push_back(i);
	}

	const int BLOCK = 400;

	li curans = 0;
	
	
	for (int i = 0; i < T; i += BLOCK) {
		memset(val, 0, sizeof val);
		memset(cnt, 0, sizeof cnt);
		curans = 0;
		for (int j = i; j < i + BLOCK; ++j) {
			for (int idx : st[j])
				if (tin[b[idx]] / BLOCK != i / BLOCK) {
					fin[tin[b[idx]]].push_back(idx);
				} else {
					int l = lca(a[idx], b[idx]);
					if (l != a[idx] && l != b[idx])
						sw(l, curans);
					naive(j, tin[b[idx]], curans);
					ans[idx] = curans;
					if (l != a[idx] && l != b[idx])
						sw(l, curans);
					naive(j, tin[b[idx]], curans);
				}
		}
		for (int j = i + BLOCK; j < T; ++j) {
			sw(ord[j], curans);
			for (int idx : fin[j]) {
				int l = lca(a[idx], b[idx]);
				int lq = tin[a[idx]];
				if (l != a[idx] && l != b[idx])
					sw(l, curans), lq = tout[a[idx]];
				naive(lq, i + BLOCK - 1, curans);
				ans[idx] = curans;
				if (l != a[idx] && l != b[idx])
					sw(l, curans);
				naive(lq, i + BLOCK - 1, curans);
			}
			fin[j].clear();
		}
	}
	forn(i, m)
        printf("%I64d\n", ans[i]);
    
}

int main()
{

#ifdef SU2
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	read();
	solve();
	
#ifdef SU2
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}