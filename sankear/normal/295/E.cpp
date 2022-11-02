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

struct td{
	ll val, sum, ans, rans;
	int sz, h, l, r;
};

ll x[100100];
td d[100100];

inline int get_rand(){
	return (rand() << 16) + rand();
}

inline void calc(int v){
	d[v].sz = d[d[v].l].sz + d[d[v].r].sz + 1;
	d[v].sum = d[d[v].l].sum + d[d[v].r].sum + d[v].val;
	d[v].ans = d[d[v].l].ans + d[v].val * d[d[v].l].sz * 2 + d[d[v].r].ans + d[d[v].r].sum * (d[d[v].l].sz + 1) * 2;
	d[v].rans = d[d[v].l].rans + d[d[v].l].sum * (d[d[v].r].sz + 1) * 2 + d[v].val * d[d[v].r].sz * 2 + d[d[v].r].rans;
}

void split(int v, ll val, int &l, int &r){
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

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	int sz = 0, cv = 0;
	for(int i = 0; i < n; i++){
		scanf(LLD, &x[i]);
		d[++sz].val = x[i];
		d[sz].h = get_rand();
		calc(sz);
		int l, r;
		split(cv, d[sz].val, l, r);
		cv = merge(l, merge(sz, r));
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int t;
		scanf("%d", &t);
		if(t == 1){
			int p, D;
			scanf("%d %d", &p, &D);
			p--;
			int p1, p2, p3;
			split(cv, x[p], p1, p3);
			split(p1, x[p] - 1, p1, p2);
			cv = merge(p1, p3);
			x[p] += D;
			d[p2].val = x[p];
			calc(p2);
			split(cv, d[p2].val, p1, p3);
			cv = merge(p1, merge(p2, p3));
			continue;
		}
		ll l, r;
		scanf(LLD" "LLD, &l, &r);
		int p1, p2, p3;
		split(cv, r, p1, p3);
		split(p1, l - 1, p1, p2);
		ll ans;
		if(d[p2].sz % 2 == 0){
			int mid = d[p2].sz / 2;
			int lf, rg;
			split_sz(p2, mid, lf, rg);
			ans = d[rg].ans + d[rg].sum - d[lf].rans - d[lf].sum;
			p2 = merge(lf, rg);
		}
		else{
			int mid = (d[p2].sz + 1) / 2;
			int lf, rg;
			split_sz(p2, mid, lf, rg);
			ans = d[rg].ans + d[rg].sum * 2 - d[lf].rans;
			p2 = merge(lf, rg);
		}
		cv = merge(p1, merge(p2, p3));
		printf(LLD"\n", ans);
	}
	return 0;
}