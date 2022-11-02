#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <complex>
#include <queue>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define fs first
#define sc second
#define next _next
#define prev _prev
#define hash _hash
#define link _link
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;
typedef long double ld;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5) + 100;
const int LOG = 17;

struct node {
	int ans, ver, ls, rs, sz, val, h, p, l, r;
};

int ptr, sz, root;
bool used[N];
int num[N], h[N];
int p[LOG][N];
vi g[N];
node d[N];

inline int get_rand(){
	return (rand() << 16) | rand();
}

void dfs(int v, int ch){
	used[v] = true;
	h[v] = ch;
	for(int i = 0; i < sz(g[v]); i++){
		if(!used[g[v][i]]){
			p[0][g[v][i]] = v;
			dfs(g[v][i], ch + 1);
		}
	}
	num[v] = ptr++;
}

inline int get_lca(int a, int b){
	if(h[a] < h[b]){
		swap(a, b);
	}
	for(int i = LOG - 1; i >= 0; i--){
		if(p[i][a] != -1 && h[p[i][a]] >= h[b]){
			a = p[i][a];
		}
	}
	if(a == b){
		return a;
	}
	for(int i = LOG - 1; i >= 0; i--){
		if(p[i][a] != p[i][b]){
			a = p[i][a];
			b = p[i][b];
		}
	}
	return p[0][a];
}

inline void calc(int v){
	d[v].sz = d[d[v].l].sz + d[d[v].r].sz + 1;
	d[v].p = 0;
	d[v].ans = 1;
	d[v].ver = d[v].ls = d[v].rs = v - 1;
	if(d[v].l > 0){
		d[d[v].l].p = v;
		d[v].ls = d[d[v].l].ls;
		d[v].ans += d[d[v].l].ans;
		int lca = get_lca(d[d[v].l].rs, v - 1);
		if(h[lca] < h[d[d[v].l].ver]){
			d[v].ans += h[d[d[v].l].ver] - h[lca];
			d[v].ver = lca;
		}
		else{
			d[v].ver = d[d[v].l].ver;
		}
		d[v].ans += h[v - 1] - h[lca] - 1;
	}
	if(d[v].r > 0){
		d[d[v].r].p = v;
		d[v].rs = d[d[v].r].rs;
		d[v].ans += d[d[v].r].ans;
		int lca = get_lca(v - 1, d[d[v].r].ls);
		if(h[lca] < h[d[v].ver]){
			if(h[lca] < h[d[d[v].r].ver]){
				d[v].ans += h[d[v].ver] - h[lca];
				d[v].ans += h[d[d[v].r].ver] - h[lca] - 1;
				d[v].ver = lca;
			}
			else{
				d[v].ans += h[d[v].ver] - h[lca] - 1;
				d[v].ver = d[d[v].r].ver;
			}
		}
		else{
			if(h[lca] < h[d[d[v].r].ver]){
				d[v].ans += h[d[d[v].r].ver] - h[lca] - 1;
			}
			else{
				if(h[d[v].ver] < h[d[d[v].r].ver]){
					d[v].ans -= h[lca] - h[d[d[v].r].ver] + 1;
				}
				else{
					d[v].ans -= h[lca] - h[d[v].ver] + 1;
					d[v].ver = d[d[v].r].ver;
				}
			}
		}
	}
}

void split(int v, int val, int &l, int &r){
	if(v == 0){
		l = r = 0;
		return;
	}
	if(d[v].val < val){
		split(d[v].r, val, d[v].r, r);
		l = v;
	}
	else{
		split(d[v].l, val, l, d[v].l);
		r = v;
	}
	calc(v);
}

void split_sz(int v, int sz, int &l, int &r){
	if(v == 0){
		l = r = 0;
		return;
	}
	if(d[d[v].l].sz + 1 <= sz){
		split_sz(d[v].r, sz - d[d[v].l].sz - 1, d[v].r, r);
		l = v;
	}
	else{
		split_sz(d[v].l, sz, l, d[v].l);
		r = v;
	}
	calc(v);
}

int merge(int l, int r){
	if(l == 0){
		return r;
	}
	if(r == 0){
		return l;
	}
	int res;
	if(d[l].h > d[r].h){
		d[l].r = merge(d[l].r, r);
		res = l;
	}
	else{
		d[r].l = merge(l, d[r].l);
		res = r;
	}
	calc(res);
	return res;
}

inline void add(int v){
	d[v + 1].val = num[v];
	d[v + 1].h = get_rand();
	d[v + 1].ans = 1;
	d[v + 1].ver = d[v + 1].ls = d[v + 1].rs = v;
	d[v + 1].sz = 1;
	int l, r;
	split(root, num[v], l, r);
	root = merge(l, merge(v + 1, r));
}

inline int get_num(int v){
	int res = d[d[v].l].sz + 1;
	while(d[v].p > 0){
		int pv = d[v].p;
		if(d[pv].r == v){
			res += d[d[pv].l].sz + 1;
		}
		v = pv;
	}
	return res;
}

inline void del(int v){
	int num = get_num(v + 1);
	int l, r, tmp;
	split_sz(root, num, l, r);
	split_sz(l, num - 1, l, tmp);
	root = merge(l, r);
}

void dfs2(int v, int lev){
	if(v == 0){
		return;
	}
	dfs2(d[v].l, lev + 1);
	for(int i = 0; i < lev; i++){
		cerr << " ";
	}
	cerr << v << " " << d[v].ans << " " << d[v].ver << endl;
	dfs2(d[v].r, lev + 1);
}

inline void debug(){
	cerr << "tree" << endl;
	dfs2(root, 0);
	cerr << endl;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n - 1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	for(int i = 0; i < LOG; i++){
		for(int j = 0; j < n; j++){
			p[i][j] = -1;
		}
	}
	ptr = 0;
	dfs(0, 0);
	for(int i = 1; i < LOG; i++){
		for(int j = 0; j < n; j++){
			if(p[i - 1][j] != -1){
				p[i][j] = p[i - 1][p[i - 1][j]];
			}
		}
	}
	int ans = 1;
	sz = root = 0;
	add(0);
	for(int i = 0; i + ans < n; i++){
		while(i + ans < n){
			add(i + ans);
			if(d[root].ans <= k){
				ans++;
			}
			else{
				del(i + ans);
				break;
			}
		}
		del(i);
		if(i + ans < n){
			add(i + ans);
		}
	}
	printf("%d\n", ans);
	return 0;
}