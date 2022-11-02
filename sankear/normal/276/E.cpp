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

struct node{
	int l, r, add, val;
};

int sz;
bool used[100100];
int num[100100], d[100100];
vi v[100100], lst[100100];
vector <node> rmq[100100];

void dfs(int a, int b){
	used[a] = true;
	d[a] = b;
	num[a] = sz;
	lst[sz].pb(a);
	for(int i = 0; i < sz(v[a]); i++){
		if(!used[v[a][i]]){
			dfs(v[a][i], b + 1);
		}
	}
}

inline void push(vector <node> &rmq, int v){
	rmq[v].val += rmq[v].add;
	if(v < sz(rmq) / 2){
		rmq[v * 2].add += rmq[v].add;
		rmq[v * 2 + 1].add += rmq[v].add;
	}
	rmq[v].add = 0;
}

void update(vector <node> &rmq, int v, int l, int r, int add){
	push(rmq, v);
	if(rmq[v].l > r || rmq[v].r < l || l > r){
		return;
	}
	if(rmq[v].l >= l && rmq[v].r <= r){
		rmq[v].add += add;
		push(rmq, v);
		return;
	}
	update(rmq, v * 2, l, r, add);
	update(rmq, v * 2 + 1, l, r, add);
}

int get(vector <node> &rmq, int v, int p){
	push(rmq, v);
	if(rmq[v].l > p || rmq[v].r < p){
		return inf;
	}
	if(rmq[v].l == rmq[v].r){
		return rmq[v].val;
	}
	if(rmq[v * 2].r >= p){
		return get(rmq, v * 2, p);
	}
	return get(rmq, v * 2 + 1, p);
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n - 1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	sz = 0;
	used[0] = true;
	for(int i = 0; i < sz(v[0]); i++){
		sz++;
		dfs(v[0][i], 1);
		int maxv = 1;
		while(maxv < sz(lst[sz]) + 1){
			maxv *= 2;
		}
		rmq[sz].resize(2 * maxv);
		for(int j = 0; j < maxv; j++){
			rmq[sz][j + maxv].add = rmq[sz][j + maxv].val = 0;
			rmq[sz][j + maxv].l = rmq[sz][j + maxv].r = j;
		}
		for(int j = maxv - 1; j > 0; j--){
			rmq[sz][j].add = rmq[sz][j].val = 0;
			rmq[sz][j].l = rmq[sz][j * 2].l;
			rmq[sz][j].r = rmq[sz][j * 2 + 1].r;
		}
	}
	int maxv = 1;
	while(maxv < n){
		maxv *= 2;
	}
	rmq[0].resize(2 * maxv);
	for(int i = 0; i < maxv; i++){
		rmq[0][i + maxv].add = rmq[0][i + maxv].val = 0;
		rmq[0][i + maxv].l = rmq[0][i + maxv].r = i;
	}
	for(int i = maxv - 1; i > 0; i--){
		rmq[0][i].add = rmq[0][i].val = 0;
		rmq[0][i].l = rmq[0][i * 2].l;
		rmq[0][i].r = rmq[0][i * 2 + 1].r;
	}
	for(int i = 0; i < m; i++){
		int t, v;
		scanf("%d %d", &t, &v);
		v--;
		if(t == 0){
			int x, D;
			scanf("%d %d", &x, &D);
			if(v == 0){
				update(rmq[0], 1, 0, D, x);
				continue;
			}
			if(d[v] > D){
				update(rmq[num[v]], 1, d[v] - D, d[v] + D, x);
				continue;
			}
			int DD = D - d[v];
			update(rmq[0], 1, 0, DD, x);
			update(rmq[num[v]], 1, DD + 1, d[v] + D, x);
			continue;
		}
		int ans = get(rmq[0], 1, d[v]);
		if(v != 0){
			ans += get(rmq[num[v]], 1, d[v]);
		}
		printf("%d\n", ans);
	}
	return 0;
}