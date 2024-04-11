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
const int N = int(5e5);

struct tr{
	bool need;
	int val, new_val, l, r;
};

int ptr, maxv;
bool used[N + 10];
int l[N + 10], r[N + 10];
vi g[N + 10];
tr rmq1[4 * N + 10];
int rmq2[4 * N + 10];

void dfs(int v){
	used[v] = true;
	l[v] = ptr++;
	for(int i = 0; i < sz(g[v]); i++){
		if(!used[g[v][i]]){
			dfs(g[v][i]);
		}
	}
	r[v] = ptr - 1;
}

inline void push(int v){
	if(!rmq1[v].need){
		return;
	}
	rmq1[v].val = rmq1[v].new_val;
	if(v < maxv){
		rmq1[v * 2].need = true;
		rmq1[v * 2].new_val = rmq1[v].new_val;
		rmq1[v * 2 + 1].need = true;
		rmq1[v * 2 + 1].new_val = rmq1[v].new_val;
	}
	rmq1[v].need = false;
}

inline void calc(int v){
	rmq1[v].val = max(rmq1[v * 2].val, rmq1[v * 2 + 1].val);
}

void update(int v, int l, int r, int val){
	push(v);
	if(rmq1[v].l > r || rmq1[v].r < l){
		return;
	}
	if(rmq1[v].l >= l && rmq1[v].r <= r){
		rmq1[v].need = true;
		rmq1[v].new_val = val;
		push(v);
		return;
	}
	update(v * 2, l, r, val);
	update(v * 2 + 1, l, r, val);
	calc(v);
}

inline void update(int a, int b){
	a += maxv;
	rmq2[a] = b;
	while(a > 1){
		a /= 2;
		rmq2[a] = max(rmq2[a * 2], rmq2[a * 2 + 1]);
	}
}

int get(int v, int l, int r){
	push(v);
	if(rmq1[v].l > r || rmq1[v].r < l){
		return -inf;
	}
	if(rmq1[v].l >= l && rmq1[v].r <= r){
		return rmq1[v].val;
	}
	return max(get(v * 2, l, r), get(v * 2 + 1, l, r));
}

inline int get(int l, int r){
	int res = -inf;
	l += maxv;
	r += maxv;
	while(l <= r){
		res = max(res, rmq2[l]);
		l = (l + 1) / 2;
		res = max(res, rmq2[r]);
		r = (r - 1) / 2;
	}
	return res;
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//cerr << "mem = " << (sizeof(rmq1) + sizeof(rmq2)) / 1024 / 1024 << endl;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	ptr = 0;
	dfs(0);
	maxv = 1;
	while(maxv < n){
		maxv *= 2;
	}
	for(int i = 0; i < maxv; i++){
		rmq1[i + maxv].val = -inf;
		rmq1[i + maxv].l = rmq1[i + maxv].r = i;
	}
	for(int i = maxv - 1; i > 0; i--){
		rmq1[i].l = rmq1[i * 2].l;
		rmq1[i].r = rmq1[i * 2 + 1].r;
		calc(i);
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int t, v;
		scanf("%d %d", &t, &v);
		v--;
		if(t == 1){
			update(1, l[v], r[v], i + 1);
			continue;
		}
		if(t == 2){
			update(l[v], i + 1);
			continue;
		}
		int t1 = get(1, l[v], l[v]), t2 = get(l[v], r[v]);
		if(t1 < t2){
			puts("0");
		}
		else{
			puts("1");
		}
	}
	return 0;
}