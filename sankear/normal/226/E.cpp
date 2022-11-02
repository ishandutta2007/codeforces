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
#include <queue>
#include <deque>
#include <stack>
#include <complex>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef LOCAL
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;
 
const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5) + 100;
const int SIZE = int(1e7) + int(5e6);
const int steps = 16;

struct node{
	int val, sz, l, r;
};

struct query{
	int t, a, b, k, y;
};

int sz;
int cv[N], val[N], h[N];
vi v[N];
node d[SIZE];
int p[steps + 1][N];
query q[N];

inline int clone(int v){
	int ptr = ++sz;
	d[ptr] = d[v];
	return ptr;
}

inline void calc(int v){
	d[v].sz = d[d[v].l].sz + d[d[v].r].sz + 1;
}

void split(int v, int val, int &l, int &r){
	if(v == 0){
		l = r = 0;
		return;
	}
	v = clone(v);
	if(d[v].val <= val){
		split(d[v].r, val, d[v].r, r);
		l = v;
	}
	else{
		split(d[v].l, val, l, d[v].l);
		r = v;
	}
	calc(v);
}

inline int get_rand(){
	return (rand() << 15) + rand();
}

inline bool can(int l, int r){
	return get_rand() % (d[l].sz + d[r].sz) < d[l].sz;
}

int merge(int l, int r){
	if(l == 0){
		return r;
	}
	if(r == 0){
		return l;
	}
	int res;
	if(can(l, r)){
		l = clone(l);
		d[l].r = merge(d[l].r, r);
		res = l;
	}
	else{
		r = clone(r);
		d[r].l = merge(l, d[r].l);
		res = r;
	}
	calc(res);
	return res;
}

void dfs(int a, int b, int c){
	h[a] = c;
	if(val[a] == 0){
		cv[a] = b;
	}
	else{
		int ptr = ++sz;
		d[ptr].val = val[a];
		d[ptr].sz = 1;
		int l, r;
		split(b, val[a], l, r);
		cv[a] = merge(l, merge(ptr, r));
	}
	for(int i = 0; i < sz(v[a]); i++){
		p[0][v[a][i]] = a;
		dfs(v[a][i], cv[a], c + 1);
	}
}

inline int lca(int a, int b){
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

int get(int v, int val){
	if(v == 0){
		return 0;
	}
	if(d[v].val <= val){
		return d[d[v].l].sz + 1 + get(d[v].r, val);
	}
	return get(d[v].l, val);
}

inline int go(int a, int b){
	for(int i = steps; i >= 0; i--){
		if(b >= (1 << i)){
			a = p[i][a];
			b -= (1 << i);
		}
	}
	return a;
}

inline int get(int a, int b, int l, int r){
	if(a == -1){
		return 0;
	}
	int res = get(cv[a], r) - get(cv[a], l - 1);
	if(b != -1){
		res -= get(cv[b], r) - get(cv[b], l - 1);
	}
	return res;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int root = -1;
	for(int i = 0; i < n; i++){
		int cur;
		scanf("%d", &cur);
		cur--;
		if(cur == -1){
			root = i;
		}
		else{
			v[cur].pb(i);
		}
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &q[i].t, &q[i].a);
		q[i].a--;
		if(q[i].t == 1){
			val[q[i].a] = i + 1;
		}
		if(q[i].t == 2){
			scanf("%d %d %d", &q[i].b, &q[i].k, &q[i].y);
			q[i].b--;
		}
	}
	for(int i = 0; i <= steps; i++){
		for(int j = 0; j < n; j++){
			p[i][j] = -1;
		}
	}
	dfs(root, 0, 0);
	for(int i = 1; i <= steps; i++){
		for(int j = 0; j < n; j++){
			if(p[i - 1][j] != -1){
				p[i][j] = p[i - 1][p[i - 1][j]];
			}
		}
	}
	for(int i = 0; i < m; i++){
		if(q[i].t == 1){
			continue;
		}
		int a = q[i].a, b = q[i].b, c = lca(a, b), k = q[i].k, y = q[i].y;
		int res = -1, l = 1, r = h[a] + h[b] - 2 * h[c] - 1;
		while(l <= r){
			int mid = (l + r) / 2, sum = 0, ver = -1;
			if(mid > h[a] - h[c]){
				int need = mid - (h[a] - h[c]);
				ver = go(b, h[b] - h[c] - need);
				sum = h[a] - h[c] - get(p[0][a], p[0][c], y + 1, i + 1);
				sum += h[ver] - h[c] - get(ver, c, y + 1, i + 1);
			}
			else{
				ver = go(a, mid);
				sum = h[a] - h[ver] - get(p[0][a], p[0][ver], y + 1, i + 1);
			}
			if(sum >= k){
				res = ver;
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		if(res != -1){
			res++;
		}
		printf("%d\n", res);
	}
	return 0;
}