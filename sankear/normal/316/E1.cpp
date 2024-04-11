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
const int N = int(2e5);
const int MOD = int(1e9);

struct matrix{
	int n, m;
	int a[4][4];	
};

inline void norm(int &a){
	while(a >= MOD){
		a -= MOD;
	}
}

matrix operator + (const matrix &a, const matrix &b){
	matrix c;
	c.n = a.n;
	c.m = b.m;
	for(int i = 0; i < c.n; i++){
		for(int j = 0; j < c.m; j++){
			c.a[i][j] = a.a[i][j] + b.a[i][j];
			norm(c.a[i][j]);
		}
	}
	return c;
}

matrix operator * (const matrix &a, const matrix &b){
	matrix c;
	c.n = a.n;
	c.m = b.m;
	for(int i = 0; i < c.n; i++){
		for(int j = 0; j < c.m; j++){
			c.a[i][j] = 0;
			for(int z = 0; z < a.m; z++){
				c.a[i][j] = (c.a[i][j] + ll(a.a[i][z]) * b.a[z][j]) % MOD;
			}
		}
	}
	return c;
}

struct tr{
	int l, r, add;
	matrix sum;
};

struct tres{
	int sz;
	matrix sum;
};

int maxv;
int a[N + 100];
matrix A[2 * N + 100], B[2 * N + 100];
tr rmq[4 * N + 100];

inline void push(int v){
	if(rmq[v].add == 0){
		return;
	}
	matrix add;
	add.n = 2;
	add.m = 1;
	add.a[0][0] = rmq[v].add;
	add.a[1][0] = 0;
	rmq[v].sum = rmq[v].sum + B[rmq[v].r - rmq[v].l] * add;
	if(v < maxv){
		rmq[v * 2].add += rmq[v].add;
		norm(rmq[v * 2].add);
		rmq[v * 2 + 1].add += rmq[v].add;
		norm(rmq[v * 2 + 1].add);
	}
	rmq[v].add = 0;
}
	
inline void calc(int v){
	rmq[v].sum = rmq[v * 2].sum + A[rmq[v * 2].r - rmq[v * 2].l + 1] * rmq[v * 2 + 1].sum;
}

void set_value(int v, int pos, int val){
	push(v);
	if(rmq[v].l > pos || rmq[v].r < pos){
		return;
	}
	if(v >= maxv){
		rmq[v].sum.a[0][0] = val;
		rmq[v].sum.a[1][0] = 0;
		return;
	}
	set_value(v * 2, pos, val);
	set_value(v * 2 + 1, pos, val);
	calc(v);
}

void update(int v, int l, int r, int add){
	push(v);
	if(rmq[v].l > r || rmq[v].r < l){
		return;
	}
	if(rmq[v].l >= l && rmq[v].r <= r){
		rmq[v].add += add;
		norm(rmq[v].add);
		push(v);
		return;
	}
	update(v * 2, l, r, add);
	update(v * 2 + 1, l, r, add);
	calc(v);
}

inline tres merge(tres a, tres b){
	tres c;
	c.sz = a.sz + b.sz;
	c.sum = a.sum + A[a.sz] * b.sum;
	return c;
}

tres get(int v, int l, int r){
	push(v);
	if(rmq[v].l > r || rmq[v].r < l){
		tres res;
		res.sz = 0;
		res.sum.n = 2;
		res.sum.m = 1;
		res.sum.a[0][0] = res.sum.a[1][0] = 0;
		return res;
	}
	if(rmq[v].l >= l && rmq[v].r <= r){
		tres res;
		res.sz = rmq[v].r - rmq[v].l + 1;
		res.sum = rmq[v].sum;
		return res;
	}
	tres res = merge(get(v * 2, l, r), get(v * 2 + 1, l, r));
	return res;
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//cerr << "mem = " << (sizeof(a) + sizeof(A) + sizeof(rmq)) / 1024 / 1024 << endl;
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	maxv = 1;
	while(maxv < n){
		maxv *= 2;
	}
	for(int i = 0; i < maxv; i++){
		rmq[i + maxv].l = rmq[i + maxv].r = i;
	}
	for(int i = maxv - 1; i > 0; i--){
		rmq[i].l = rmq[i * 2].l;
		rmq[i].r = rmq[i * 2 + 1].r;
	}
	for(int i = 0; i < n; i++){
		rmq[i + maxv].sum.n = 2;
		rmq[i + maxv].sum.m = 1;
		rmq[i + maxv].sum.a[0][0] = a[i];
		rmq[i + maxv].sum.a[1][0] = 0;
	}
	for(int i = n; i < maxv; i++){
		rmq[i + maxv].sum.n = 2;
		rmq[i + maxv].sum.m = 1;
		rmq[i + maxv].sum.a[0][0] = rmq[i + maxv].sum.a[1][0] = 0;
	}
	// A[0]
	A[0].n = A[0].m = 2;
	A[0].a[0][0] = A[0].a[1][1] = 1;
	A[0].a[0][1] = A[0].a[1][0] = 0;
	// A[1]
	A[1].n = A[1].m = 2;
	A[1].a[0][0] = A[1].a[0][1] = A[1].a[1][0] = 1;
	A[1].a[1][1] = 0;
	for(int i = 2; i <= maxv; i++){
		A[i] = A[i - 1] * A[1];
	}
	B[0] = A[0];
	for(int i = 1; i <= maxv; i++){
		B[i] = B[i - 1] + A[i];
	}
	for(int i = maxv - 1; i > 0; i--){
		calc(i);
	}
	for(int i = 0; i < m; i++){
		int t;
		scanf("%d", &t);
		if(t == 1){
			int x, v;
			scanf("%d %d", &x, &v);
			x--;
			set_value(1, x, v);
			continue;
		}
		if(t == 2){
			int l, r;
			scanf("%d %d", &l, &r);
			l--;
			r--;
			tres res = get(1, l, r);
			printf("%d\n", res.sum.a[0][0]);
			continue;
		}
		int l, r, d;
		scanf("%d %d %d", &l, &r, &d);
		l--;
		r--;
		update(1, l, r, d);
	}
	return 0;
}