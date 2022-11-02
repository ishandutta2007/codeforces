#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define len(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long lint;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5);
const int steps = 16;

struct tans{
	int ans, ver;
};

int ptr;
bool used[N + 10], good[N + 10];
int num[N + 10], len[N + 10], sz[N + 10], ver[N + 10], h[N + 10], val[N + 10], add[N + 10], prev[N + 10];
pii lst[N + 10];
tans d1[N + 10], d2[N + 10], pref[N + 10], suff[N + 10];
vector <pii> g[N + 10];
int p[steps + 2][N + 10];

inline tans merge(tans a, tans b, int ver){
	if(b.ans > a.ans){
		return b;
	}
	if(b.ans == a.ans){
		a.ver = ver;
	}
	return a;
}

void dfs1(int v, int ch = 0){
	used[v] = true;
	h[v] = ch;
	sz[v] = 1;
	d1[v].ans = -inf;
	if(good[v]){
		d1[v].ans = 0;
		d1[v].ver = v;
	}
	for(int i = 0; i < sz(g[v]); i++){
		if(!used[g[v][i].fs]){
			p[0][g[v][i].fs] = v;
			dfs1(g[v][i].fs, ch + 1);
			sz[v] += sz[g[v][i].fs];
			tans cur = d1[g[v][i].fs];
			cur.ans += g[v][i].sc;
			d1[v] = merge(d1[v], cur, v);
		}
	}
}

void dfs2(int v){
	int sz = 0;
	for(int i = 0; i < sz(g[v]); i++){
		if(p[0][g[v][i].fs] == v){
			lst[sz++] = g[v][i];
		}
	}
	for(int i = 0; i < sz; i++){
		pref[i].ans = -inf;
		if(i > 0){
			pref[i] = pref[i - 1];
		}
		tans cur = d1[lst[i].fs];
		cur.ans += lst[i].sc;
		pref[i] = merge(pref[i], cur, v);
	}
	for(int i = sz - 1; i >= 0; i--){
		suff[i].ans = -inf;
		if(i + 1 < sz){
			suff[i] = suff[i + 1];
		}
		tans cur = d1[lst[i].fs];
		cur.ans += lst[i].sc;
		suff[i] = merge(suff[i], cur, v);
	}
	for(int i = 0; i < sz; i++){
		tans cur = d2[v];
		if(i > 0){
			cur = merge(cur, pref[i - 1], v);
		}
		if(i + 1 < sz){
			cur = merge(cur, suff[i + 1], v);
		}
		cur.ans += lst[i].sc;
		d2[lst[i].fs] = cur;
	}
	for(int i = 0; i < sz(g[v]); i++){
		if(p[0][g[v][i].fs] == v){
			dfs2(g[v][i].fs);
		}
	}
}

inline int get_lca(int a, int b){
	if(h[a] < h[b]){
		swap(a, b);
	}
	for(int i = steps; i >= 0; i--){
		if(p[i][a] != -1 && h[p[i][a]] >= h[b]){
			a = p[i][a];
		}
	}
	if(a == b){
		return a;
	}
	for(int i = steps; i >= 0; i--){
		if(p[i][a] != p[i][b]){
			a = p[i][a];
			b = p[i][b];
		}
	}
	return p[0][a];
}

void dfs3(int v, int pv){
	prev[v] = pv;
	num[v] = ptr;
	ver[ptr++] = v;
	int best = -1;
	for(int i = 0; i < sz(g[v]); i++){
		if(p[0][g[v][i].fs] == v && (best == -1 || sz[g[v][i].fs] > sz[best])){
			best = g[v][i].fs;
		}
	}
	if(best != -1){
		dfs3(best, pv);
	}
	for(int i = 0; i < sz(g[v]); i++){
		if(p[0][g[v][i].fs] == v && g[v][i].fs != best){
			dfs3(g[v][i].fs, g[v][i].fs);
		}
	}
}

inline void update(int l, int r){
	if(l > r){
		return;
	}
	add[l]++;
	add[r + 1]--;
}

inline void add_one(int a, int b){
	int c = get_lca(a, b);
	while(prev[a] != prev[c]){
		update(num[prev[a]], num[a]);
		a = p[0][prev[a]];
	}
	update(num[c], num[a]);
	while(prev[b] != prev[c]){
		update(num[prev[b]], num[b]);
		b = p[0][prev[b]];
	}
	update(num[c] + 1, num[b]);
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int cur;
		scanf("%d", &cur);
		cur--;
		good[cur] = true;
	}
	for(int i = 0; i < n - 1; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--;
		b--;
		g[a].pb(mp(b, c));
		g[b].pb(mp(a, c));
	}
	for(int i = 0; i <= steps; i++){
		for(int j = 0; j < n; j++){
			p[i][j] = -1;
		}
	}
	dfs1(0);
	d2[0].ans = -inf;
	if(good[0]){
		d2[0].ans = 0;
		d2[0].ver = 0;
	}
	dfs2(0);
	for(int i = 1; i <= steps; i++){
		for(int j = 0; j < n; j++){
			if(p[i - 1][j] != -1){
				p[i][j] = p[i - 1][p[i - 1][j]];
			}
		}
	}
	ptr = 0;
	dfs3(0, 0);
	for(int i = 0; i < n; i++){
		if(good[i]){
			tans cur = merge(d1[i], d2[i], i);
			add_one(i, cur.ver);
		}
	}
	int bal = 0;
	for(int i = 0; i < n; i++){
		bal += add[i];
		val[ver[i]] = bal;
	}	
	int ans = -inf, cnt = -1;
	for(int i = 0; i < n; i++){
		if(!good[i]){
			if(val[i] > ans){
				ans = val[i];
				cnt = 1;
			}
			else{
				if(val[i] == ans){
					cnt++;
				}
			}
		}
	}
	printf("%d %d\n", ans, cnt);
	return 0;
}