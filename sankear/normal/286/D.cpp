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
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

struct tp{
	int l, r, t;
};

struct td{
	int val, h, sz, p, l, r;
	ll sum;
};

tp p[200200];
pii q[200200];
int x[200200];
ll ans[200200];
vi add[200200], del[200200];
multiset <int> s;
td d[200200];

bool operator < (const tp &a, const tp &b){
	return a.t - a.l < b.t - b.l;
}

inline int get_rand(){
	return (rand() << 16) + rand();
}

inline void calc(int v){
	d[v].sz = d[d[v].l].sz + d[d[v].r].sz + 1;
	d[v].sum = d[d[v].l].sum + d[d[v].r].sum - d[v].val;
	d[v].p = 0;
	if(d[v].l > 0){
		d[d[v].l].p = v;
	}
	if(d[v].r > 0){
		d[d[v].r].p = v;
	}
}

void split(int v, int val, int &l, int &r){
	if(v == 0){
		l = r = 0;
		return;
	}
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

inline int get_sz(int v){
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

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	int k = 0;
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &p[i].l, &p[i].r, &p[i].t);
		x[k++] = p[i].l;
		x[k++] = p[i].r;
	}
	sort(x, x + k);
	k = unique(x, x + k) - x;
	for(int i = 0; i < m; i++){
		add[lower_bound(x, x + k, p[i].l) - x].pb(p[i].t);
		del[lower_bound(x, x + k, p[i].r) - x].pb(p[i].t);
	}
	m = 0;
	for(int i = 0; i < k; i++){
		if(sz(s) > 0){
			p[m].l = x[i - 1];
			p[m].r = x[i];
			p[m++].t = *(s.begin());
		}
		for(int j = 0; j < sz(del[i]); j++){
			s.erase(s.find(del[i][j]));
		}
		for(int j = 0; j < sz(add[i]); j++){
			s.insert(add[i][j]);
		}
	}
	sort(p, p + m);
	for(int i = 0; i < n; i++){
		scanf("%d", &q[i].fs);
		q[i].sc = i;
	}
	sort(q, q + n);
	int cv = 0;
	for(int i = 0; i < m; i++){
		d[i + 1].h = get_rand();
		d[i + 1].val = p[i].t - p[i].r;
		d[i + 1].sum = -d[i + 1].val;
		d[i + 1].sz = 1;
		int l, r;
		split(cv, d[i + 1].val, l, r);
		cv = merge(l, merge(i + 1, r));
	}
	int ptr = 0;
	ll sum = 0;
	for(int i = 0; i < n; i++){
		while(ptr < m && p[ptr].t - p[ptr].l <= q[i].fs){
			int num = get_sz(ptr + 1), p1, p2, p3;
			split_sz(cv, num, p1, p3);
			split_sz(p1, num - 1, p1, p2);
			cv = merge(p1, p3);
			sum += p[ptr].r - p[ptr].l;
			ptr++;
		}
		int l, r;
		split(cv, q[i].fs, l, r);
		ans[q[i].sc] = sum + d[l].sum + ll(q[i].fs) * d[l].sz;
		cv = merge(l, r);
	}
	for(int i = 0; i < n; i++){
		printf(LLD"\n", ans[i]);
	}
	return 0;
}