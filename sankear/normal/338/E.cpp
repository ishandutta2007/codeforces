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
const int N = 150 * 1000;

struct tr{
	int add, val, l, r;
};

int maxv;
int a[N + 10], b[N + 10];
tr rmq[4 * N + 10];

inline void calc(int v){
	rmq[v].val = min(rmq[v * 2].val, rmq[v * 2 + 1].val);
}

inline void push(int v){
	rmq[v].val += rmq[v].add;
	if(v < maxv){
		rmq[v * 2].add += rmq[v].add;
		rmq[v * 2 + 1].add += rmq[v].add;
	}
	rmq[v].add = 0;
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

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, h;
	scanf("%d %d %d", &n, &m, &h);
	for(int i = 0; i < m; i++){
		scanf("%d", &b[i]);
	}
	sort(b, b + m);
	maxv = 1;
	while(maxv < m){
		maxv *= 2;
	}
	for(int i = 0; i < maxv; i++){
		rmq[i + maxv].l = rmq[i + maxv].r = i;
		rmq[i + maxv].val = (i < m ? -(i + 1) : 0);
	}
	for(int i = maxv - 1; i > 0; i--){
		rmq[i].l = rmq[i * 2].l;
		rmq[i].r = rmq[i * 2 + 1].r;
		calc(i);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < m; i++){
		update(1, lower_bound(b, b + m, h - a[i]) - b, m - 1, 1);
	}
	int ans = 0;
	for(int i = 0; i + m - 1 < n; i++){
		if(rmq[1].val >= 0){
			ans++;
		}
		if(i + m < n){
			update(1, lower_bound(b, b + m, h - a[i]) - b, m - 1, -1);
			update(1, lower_bound(b, b + m, h - a[i + m]) - b, m - 1, 1);
		}
	}
	printf("%d\n", ans);
	return 0;
}