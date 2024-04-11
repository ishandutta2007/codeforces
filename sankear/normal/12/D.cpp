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
#include <queue>
#include <complex>
#include <cassert>
 
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
 
typedef long long ll;
typedef long long llong;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;
 
const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

struct td{
	int key, val, max_val, h, l, r;
};

pair <int, pii> p[500500];
td d[500500];

inline int get_rand(){
	return (rand() << 16) + rand();
}

inline void calc(int v){
	d[v].max_val = max(d[v].val, max(d[d[v].l].max_val, d[d[v].r].max_val));
}

void split(int v, int key, int &l, int &r){
	if(v == 0){
		l = r = 0;
		return;
	}
	if(d[v].key <= key){
		split(d[v].r, key, d[v].r, r);
		l = v;
	}
	else{
		split(d[v].l, key, l, d[v].l);
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
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("table.in", "r", stdin);
	//freopen("table.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &p[i].fs);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &p[i].sc.fs);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &p[i].sc.sc);
	}
	sort(p, p + n);
	reverse(p, p + n);
	int sz = 0, cv = 0, i = 0, ans = 0;
	d[0].max_val = -inf;
	while(i < n){
		int j = i;
		while(j + 1 < n && p[i].fs == p[j + 1].fs){
			j++;
		}
		for(int z = i; z <= j; z++){
			int l, r;
			split(cv, p[z].sc.fs, l, r);
			if(d[r].max_val > p[z].sc.sc){
				ans++;
			}
			cv = merge(l, r);
		}
		for(int z = i; z <= j; z++){
			d[++sz].key = p[z].sc.fs;
			d[sz].val = d[sz].max_val = p[z].sc.sc;
			d[sz].h = get_rand();
			int l, r;
			split(cv, d[sz].key, l, r);
			cv = merge(l, merge(sz, r));
		}
		i = j + 1;
	}
	printf("%d\n", ans);
	return 0;
}