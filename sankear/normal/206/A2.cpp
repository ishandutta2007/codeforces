#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <complex>
#include <queue>
#include <cassert>

using namespace std;

//#define HOME
#define pb push_back
#define mp make_pair
#define next _next
#define prev _prev
#define rank _rank
#define fs first
#define sc second
#define sz(s) int((s).size())

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = acos(double(-1));

struct td{
	int val, sz, h, l, r;
};

int pos[5050], k[5050];
int a[3][200200];
td d[5050];
pii lst[200200];

inline int get_rand(){
	return (rand() << 15) + rand();
}

inline void calc(int v){
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

void splitsz(int v, int sz, int &l, int &r){
	if(v == 0){
		l = r = 0;
		return;
	}
	if(d[d[v].l].sz + 1 <= sz){
		splitsz(d[v].r, sz - d[d[v].l].sz - 1, d[v].r, r);
		l = v;
	}
	else{
		splitsz(d[v].l, sz, l, d[v].l);
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
#ifdef HOME
	double start = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif
	//cout << sizeof(lst) / 1024 / 1024 << endl;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int x, y, m;
		scanf("%d %d %d %d %d", &k[i], &a[i][0], &x, &y, &m);
		for(int j = 1; j < k[i]; j++){
			a[i][j] = ((ll)a[i][j - 1] * x + y) % m;
		}
	}
	int sum = 0, cv = 0;
	for(int i = 0; i < n; i++){
		sum += k[i];
		d[i + 1].h = get_rand();
		d[i + 1].val = a[i][0];
		d[i + 1].sz = 1;
		d[i + 1].l = d[i + 1].r = 0;
		int l, r;
		split(cv, a[i][0], l, r);
		cv = merge(l, merge(i + 1, r));
	}
	int g = -inf, ans = 0;
	for(int i = 0; i < sum; i++){
		int l, r;
		split(cv, g, l, r);
		if(r == 0){
			ans++;
			cv = l;
			g = -inf;
			split(cv, g, l, r);
		}
		int r1, r2;
		splitsz(r, 1, r1, r2);
		g = d[r1].val;
		if(i < 200 * 1000){
			lst[i] = mp(d[r1].val, r1);
		}
		pos[r1 - 1]++;
		if(pos[r1 - 1] < k[r1 - 1]){
			cv = merge(l, r2);
			d[r1].val = a[r1 - 1][pos[r1 - 1]];
			d[r1].h = get_rand();
			split(cv, d[r1].val, l, r);
			cv = merge(l, merge(r1, r));
		}
		else{
			cv = merge(l, r2);
		}
	}
	printf("%d\n", ans);
	if(sum <= 200 * 1000){
		for(int i = 0; i < sum; i++){
			printf("%d %d\n", lst[i].fs, lst[i].sc);
		}
	}
#ifdef HOME
	printf("time = %.18lf\n", (clock() - start) / CLOCKS_PER_SEC);
#endif
	return 0;
}