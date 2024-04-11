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

struct tp {
	int l, r, v, num;
};

bool operator < (const tp &a, const tp &b){
	return a.v < b.v;
}

struct tr {
	int l, r, add;
	pii val;
};

int maxv;
tp p[N];
int res[N];
vi lst[N];
vector <pii> add[N], del[N];
tr rmq[4 * N];

inline void push(int v){
	rmq[v].val.fs += rmq[v].add;
	if(v < maxv){
		rmq[v * 2].add += rmq[v].add;
		rmq[v * 2 + 1].add += rmq[v].add;
	}
	rmq[v].add = 0;
}

inline void calc(int v){
	rmq[v].val = max(rmq[v * 2].val, rmq[v * 2 + 1].val);
}

void update(int v, int l, int r, int add){
	push(v);
	if(rmq[v].l > r || rmq[v].r < l || l > r){
		return;
	}
	if(rmq[v].l >= l && rmq[v].r <= r){
		rmq[v].add += add;
		push(v);
		return;
	}
	update(v * 2, l, r, add);
	update(v * 2 + 1, l, r, add);
	calc(v);
}

void set_val(int v, int p, int val){
	push(v);
	if(rmq[v].l > p || rmq[v].r < p){
		return;
	}
	if(v >= maxv){
		rmq[v].val.fs = val;
		return;
	}
	set_val(v * 2, p, val);
	set_val(v * 2 + 1, p, val);
	calc(v);
}

pii get(int v, int l, int r){
	push(v);
	if(rmq[v].l > r || rmq[v].r < l){
		return mp(-inf, -1);
	}
	if(rmq[v].l >= l && rmq[v].r <= r){
		return rmq[v].val;
	}
	return max(get(v * 2, l, r), get(v * 2 + 1, l, r));
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &p[i].l, &p[i].v, &p[i].r);
		p[i].num = i;
	}
	sort(p, p + n);
	maxv = 1;
	while(maxv < n){
		maxv *= 2;
	}
	for(int i = 0; i < maxv; i++){
		rmq[i + maxv].l = rmq[i + maxv].r = i;
		rmq[i + maxv].val = mp(0, i);
	}
	for(int i = maxv - 1; i > 0; i--){
		rmq[i].l = rmq[i * 2].l;
		rmq[i].r = rmq[i * 2 + 1].r;
		calc(i);
	}
	for(int i = 0; i < n; i++){
		int g = i, l = 0, r = i - 1;
		while(l <= r){
			int mid = (l + r) / 2;
			if(p[mid].v >= p[i].l){
				g = mid;
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		if(g > 0){
			lst[g - 1].pb(i);
		}
	}
	for(int i = 0; i < n; i++){
		int gl = i, l = 0, r = i - 1;
		while(l <= r){
			int mid = (l + r) / 2;
			if(p[mid].v >= p[i].l){
				gl = mid;
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		int gr = i;
		l = i + 1;
		r = n - 1;
		while(l <= r){
			int mid = (l + r) / 2;
			if(p[mid].v <= p[i].r){
				gr = mid;
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
		}
		add[i].pb(mp(i, gr));
		del[gl].pb(mp(i, gr));
	}
	int ans = 0, gl = -1, gr = -1;
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < sz(lst[i]); j++){
			set_val(1, lst[i][j], -inf);
		}
		for(int j = 0; j < sz(add[i]); j++){
			update(1, add[i][j].fs, add[i][j].sc, 1);
		}
		int g = i, l = i + 1, r = n - 1;
		while(l <= r){
			int mid = (l + r) / 2;
			if(p[mid].v <= p[i].r){
				g = mid;
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
		}
		pii cur = get(1, i, g);
		if(cur.fs > ans){
			ans = cur.fs;
			gl = i;
			gr = cur.sc;
		}
		for(int j = 0; j < sz(del[i]); j++){
			update(1, del[i][j].fs, del[i][j].sc, -1);
		}
	}
	int sz = 0;
	for(int i = gl; i <= gr; i++){
		if(p[i].l <= p[gl].v && p[i].r >= p[gr].v){
			res[sz++] = p[i].num;
		}
	}
	printf("%d\n", sz);
	for(int i = 0; i < sz; i++){
		printf("%d ", res[i] + 1);
	}
	puts("");
	return 0;
}