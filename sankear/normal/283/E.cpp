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

struct tr{
	bool need;
	int val, l, r;
};

int maxv;
int a[100100], ans[100100];
tr rmq[280280];
vector <pii> add[100100], del[100100];

inline void push(int v){
	if(!rmq[v].need){
		return;
	}
	rmq[v].val = rmq[v].r - rmq[v].l + 1 - rmq[v].val;
	if(v < maxv){
		rmq[v * 2].need ^= true;
		rmq[v * 2 + 1].need ^= true;
	}
	rmq[v].need = false;
}

inline void calc(int v){
	rmq[v].val = rmq[v * 2].val + rmq[v * 2 + 1].val;
}

void update(int v, int l, int r){
	push(v);
	if(rmq[v].l > r || rmq[v].r < l){
		return;
	}
	if(rmq[v].l >= l && rmq[v].r <= r){
		rmq[v].need = true;
		push(v);
		return;
	}
	update(v * 2, l, r);
	update(v * 2 + 1, l, r);
	calc(v);
}

int get(int v, int l, int r){
	push(v);
	if(rmq[v].l > r || rmq[v].r < l || l > r){
		return 0;
	}
	if(rmq[v].l >= l && rmq[v].r <= r){
		return rmq[v].val;
	}
	return get(v * 2, l, r) + get(v * 2 + 1, l, r);
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for(int i = 0; i < m; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		int l = lower_bound(a, a + n, A) - a;
		int r = lower_bound(a, a + n, B) - a;
		if(r == n || a[r] > B){
			r--;
		}
		if(l > r){
			continue;
		}
		add[l].pb(mp(l, r));
		del[r].pb(mp(l, r));
	}
	maxv = 1;
	while(maxv < n){
		maxv *= 2;
	}
	for(int i = 0; i < maxv; i++){
		rmq[i + maxv].l = rmq[i + maxv].r = i;
		rmq[i + maxv].val = 1;
	}
	for(int i = maxv - 1; i > 0; i--){
		rmq[i].l = rmq[i * 2].l;
		rmq[i].r = rmq[i * 2 + 1].r;
		calc(i);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < sz(add[i]); j++){
			update(1, add[i][j].fs, add[i][j].sc);
		}
		ans[i] += get(1, i + 1, n - 1);
		for(int j = 0; j < sz(del[i]); j++){
			update(1, del[i][j].fs, del[i][j].sc);
		}
	}
	for(int i = 0; i < maxv; i++){
		rmq[i + maxv].val = 0;
		rmq[i + maxv].need = false;
	}
	for(int i = maxv - 1; i > 0; i--){
		rmq[i].need = false;
		calc(i);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < sz(add[i]); j++){
			update(1, add[i][j].fs, add[i][j].sc);
		}
		ans[i] += get(1, 0, i - 1);
		for(int j = 0; j < sz(del[i]); j++){
			update(1, del[i][j].fs, del[i][j].sc);
		}
	}
	ll res = ll(n) * (n - 1) * (n - 2) / 6;
	for(int i = 0; i < n; i++){
		res -= ll(ans[i]) * (ans[i] - 1) / 2;
	}
	printf(LLD"\n", res);
	return 0;
}