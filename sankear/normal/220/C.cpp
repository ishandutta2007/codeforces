#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <complex>
#include <queue>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define next _next
#define prev _prev
#define rank _rank
#define sz(s) int((s).size())
#define fs first
#define sc second

typedef long long ll;
typedef unsigned long long ull;
typedef complex <double> tc;
typedef pair <int, int> pii;
typedef vector <int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

struct td{
	int val, add, minval, maxval, h, sz, p, l, r;
};

int p[100100], a[100100], b[100100];
td d[100100];

inline int get_rand(){
	return (rand() << 15) + rand();
}

inline void push(int v){
	if(v == 0){
		return;
	}
	d[v].val += d[v].add;
	d[v].minval += d[v].add;
	d[v].maxval += d[v].add;
	if(d[v].l > 0){
		d[d[v].l].add += d[v].add;
	}
	if(d[v].r > 0){
		d[d[v].r].add += d[v].add;
	}
	d[v].add = 0;
}

inline void calc(int v){
	d[v].sz = d[d[v].l].sz + d[d[v].r].sz + 1;
	d[v].p = 0;
	d[v].minval = d[v].maxval = d[v].val;
	if(d[v].l > 0){
		push(d[v].l);
		d[d[v].l].p = v;
		d[v].minval = min(d[v].minval, d[d[v].l].minval);
		d[v].maxval = max(d[v].maxval, d[d[v].l].maxval);
	}
	if(d[v].r > 0){
		push(d[v].r);
		d[d[v].r].p = v;
		d[v].minval = min(d[v].minval, d[d[v].r].minval);
		d[v].maxval = max(d[v].maxval, d[d[v].r].maxval);
	}
}

void split(int v, int val, int &l, int &r){
	push(v);
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
	push(v);
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
	push(l);
	push(r);
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

inline pii get(int v){
	int sz = d[d[v].l].sz + 1;
	while(d[v].p > 0){
		int pv = d[v].p;
		if(d[pv].r == v){
			sz += d[d[pv].l].sz + 1;
		}
		v = pv;
	}
	return mp(v, sz);
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int cur;
		scanf("%d", &cur);
		cur--;
		a[cur] = i;
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &p[i]);
		p[i]--;
		b[p[i]] = i;
	}
	int root1 = 0, root2 = 0;
	d[0].minval = inf;
	d[0].maxval = -inf;
	for(int i = 0; i < n; i++){
		d[i + 1].val = d[i + 1].maxval = d[i + 1].minval = b[i] - a[i];
		d[i + 1].sz = 1;
		d[i + 1].h = get_rand();
		int l, r;
		if(b[i] - a[i] >= 0){
			split(root1, b[i] - a[i], l, r);
			root1 = merge(l, merge(i + 1, r));
		}
		else{
			split(root2, b[i] - a[i], l, r);
			root2 = merge(l, merge(i + 1, r));
		}
	}
	for(int i = 0; i < n; i++){
		push(root1);
		push(root2);
		printf("%d\n", min(d[root1].minval, -d[root2].maxval));
		int l, r;
		split(root1, 0, l, r);
		if(r > 0){
			d[r].add += -1;
			push(r);
		}
		root1 = r;
		if(l > 0){
			d[l].add += -1;
			push(l);
		}
		if(root2 > 0){
			d[root2].add += -1;
			push(root2);
		}
		root2 = merge(root2, l);
		pii cur = get(p[i] + 1);
		int p1, p2, p3;
		split_sz(cur.fs, cur.sc, p1, p3);
		split_sz(p1, cur.sc - 1, p1, p2);
		if(cur.fs == root1){
			root1 = merge(p1, p3);
		}
		else{
			root2 = merge(p1, p3);
		}
		d[p2].val = d[p2].minval = d[p2].maxval = n - 1 - a[p[i]];
		split(root1, d[p2].val, l, r);
		root1 = merge(l, merge(p2, r));
	}
	return 0;
}