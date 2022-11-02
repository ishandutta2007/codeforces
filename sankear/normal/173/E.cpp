#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

const int inf = (int)1e9;

struct tp{
	int r, a, num;
};

struct tq{
	int x, y, val, num;
};

struct td{
	int val, ans, best, sz, h, l, r;
};

int cv, k;
td d[100100];
tp p[100100];
tq q[100100];
int ans[100100], look[100100], sol[100100];

bool operator < (const tp &a, const tp &b){
	return a.r < b.r;
}

bool operator < (const tq &a, const tq &b){
	return a.val > b.val;
}

inline int getrand(){
	return (rand() << 16) + rand();
}

inline void calc(int v){
	d[v].best = d[v].ans;
	if(d[v].l > 0){
		d[v].best = max(d[v].best, d[d[v].l].best);
	}
	if(d[v].r > 0){
		d[v].best = max(d[v].best, d[d[v].r].best);
	}
	d[v].sz = d[d[v].l].sz + d[d[v].r].sz + 1;
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

inline void solve(int l, int r){
	for(int i = l; i <= r; i++){
		int p1, p2, p3;
		split(cv, p[i].a - k, p1, p2);
		split(p2, p[i].a + k + 1, p2, p3);
		ans[i] = d[p2].sz;
		cv = merge(p1, merge(p2, p3));
	}
}

int main(){
	srand(time(NULL));
	//freopen("b.in", "r", stdin);
	//freopen("b.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", &p[i].r);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &p[i].a);
		p[i].num = i;
	}
	sort(p, p + n);
	for(int i = 0; i < n; i++){
		look[p[i].num] = i;
	}
	int sz = 0, last = 0;
	for(int i = 0; i < n; i++){
		if(i > 0 && p[i - 1].r != p[i].r){
			solve(last, i - 1);
			last = i;
		}
		d[++sz].h = getrand();
		d[sz].val = p[i].a;
		d[sz].sz = 1;
		int l, r;
		split(cv, p[i].a, l, r);
		cv = merge(l, merge(sz, r));
	}
	solve(last, n - 1);
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &q[i].x, &q[i].y);
		q[i].x = look[q[i].x - 1];
		q[i].y = look[q[i].y - 1];
		q[i].val = max(p[q[i].x].r, p[q[i].y].r);
		q[i].num = i;
	}
	sort(q, q + m);
	int j = 0, i = n - 1;
	sz = cv = 0;
	d[0].best = -inf;
	while(i >= 0){
		int ni = i;
		while(ni > 0 && p[ni - 1].r == p[i].r){
			ni--;
		}
		for(int z = ni; z <= i; z++){
			d[++sz].val = p[z].a;
			d[sz].ans = d[sz].best = ans[z];
			d[sz].h = getrand();
			d[sz].sz = 1;
			d[sz].l = d[sz].r = 0;
			int l, r;
			split(cv, p[z].a, l, r);
			cv = merge(l, merge(sz, r));
		}
		while(j < m && q[j].val == p[i].r){
			int gl = max(p[q[j].x].a, p[q[j].y].a) - k, gr = min(p[q[j].x].a, p[q[j].y].a) + k;
			int p1, p2, p3;
			split(cv, gl, p1, p2);
			split(p2, gr + 1, p2, p3);
			sol[q[j].num] = d[p2].best;
			cv = merge(p1, merge(p2, p3));
			j++;
		}
		i = ni - 1;
	}
	for(int i = 0; i < m; i++){
		printf("%d\n", (sol[i] < 2 ? -1 : sol[i]));
	}
	return 0;
}