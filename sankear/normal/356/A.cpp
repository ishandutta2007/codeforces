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
#define len(s) int((s).size())
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
typedef long long int64;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long lint;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(3e5);

struct tr{
	bool need;
	int val, new_val, l, r;
};

int maxv;
int l[N + 10], r[N + 10], x[N + 10];
tr rmq[4 * N + 10];

inline void push(int v){
	if(!rmq[v].need){
		return;
	}
	rmq[v].val = rmq[v].new_val;
	if(v < maxv){
		rmq[v * 2].need = true;
		rmq[v * 2].new_val = rmq[v].new_val;
		rmq[v * 2 + 1].need = true;
		rmq[v * 2 + 1].new_val = rmq[v].new_val;
	}
	rmq[v].need = false;
}

void update(int v, int l, int r, int val){
	push(v);
	if(rmq[v].l > r || rmq[v].r < l || l > r){
		return;
	}
	if(rmq[v].l >= l && rmq[v].r <= r){
		rmq[v].need = true;
		rmq[v].new_val = val;
		push(v);
		return;
	}
	update(v * 2, l, r, val);
	update(v * 2 + 1, l, r, val);
}

void dfs(int v){
	push(v);
	if(v >= maxv){
		return;
	}
	dfs(v * 2);
	dfs(v * 2 + 1);
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &l[i], &r[i], &x[i]);
		l[i]--;
		r[i]--;
		x[i]--;
	}
	maxv = 1;
	while(maxv < n){
		maxv *= 2;
	}
	for(int i = 0; i < maxv; i++){
		rmq[i + maxv].val = -1;
		rmq[i + maxv].l = rmq[i + maxv].r = i;
	}
	for(int i = maxv - 1; i > 0; i--){
		rmq[i].l = rmq[i * 2].l;
		rmq[i].r = rmq[i * 2 + 1].r;
	}
	for(int i = m - 1; i >= 0; i--){
		update(1, l[i], x[i] - 1, x[i]);
		update(1, x[i] + 1, r[i], x[i]);
	}
	dfs(1);
	for(int i = 0; i < n; i++){
		printf("%d ", rmq[i + maxv].val + 1);
	}
	puts("");
	return 0;
}