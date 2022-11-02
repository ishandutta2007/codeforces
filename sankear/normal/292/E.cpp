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
const int SIZE = int(1e7 + 3e6);
const int MAX_SIZE = SIZE - int(1e5);

struct td{
	int val, sz, l, r;
};

int sz;
int a[100100], b[100100];
td d[SIZE];

inline int get_rand(){
	return (rand() << 15) + rand();
}

inline void calc(int v){
	d[v].sz = d[d[v].l].sz + d[d[v].r].sz + 1;
}

int build(int *a, int l, int r){
	if(l > r){
		return 0;
	}
	int mid = (l + r) / 2, res = ++sz;
	d[res].val = a[mid];
	d[res].l = build(a, l, mid - 1);
	d[res].r = build(a, mid + 1, r);
	calc(res);
	return res;
}

void write(int v, int *a){
	if(v == 0){
		return;
	}
	write(d[v].l, a);
	a[sz++] = d[v].val;
	write(d[v].r, a);
}

int get_val(int v, int sz){
	if(d[d[v].l].sz + 1 == sz){
		return d[v].val;
	}
	if(d[d[v].l].sz + 1 < sz){
		return get_val(d[v].r, sz - d[d[v].l].sz - 1);
	}
	return get_val(d[v].l, sz);
}

inline int clone(int v){
	d[++sz] = d[v];
	return sz;
}

void split(int v, int sz, int &l, int &r){
	if(v == 0){
		l = r = 0;
		return;
	}
	v = clone(v);
	if(d[d[v].l].sz + 1 <= sz){
		split(d[v].r, sz - d[d[v].l].sz - 1, d[v].r, r);
		l = v;
	}
	else{
		split(d[v].l, sz, l, d[v].l);
		r = v;
	}
	calc(v);
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

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//cerr << "mem = " << sizeof(d) / 1024 / 1024 << endl;
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}
	sz = 0;
	int cv1 = build(a, 0, n - 1), cv2 = build(b, 0, n - 1);
	for(int i = 0; i < m; i++){
		int t;
		scanf("%d", &t);
		if(t == 1){
			int x, y, k;
			scanf("%d %d %d", &x, &y, &k);
			int p11, p12, p13;
			split(cv1, x + k - 1, p11, p13);
			split(p11, x - 1, p11, p12);
			int p21, p22, p23;
			split(cv2, y + k - 1, p21, p23);
			split(p21, y - 1, p21, p22);
			cv2 = merge(p21, merge(p12, p23));
		}
		else{
			int x;
			scanf("%d", &x);
			printf("%d\n", get_val(cv2, x));
		}
		if(sz > MAX_SIZE){
			sz = 0;
			write(cv1, a);
			sz = 0;
			write(cv2, b);
			sz = 0;
			cv1 = build(a, 0, n - 1);
			cv2 = build(b, 0, n - 1);
		}
	}
	return 0;
}