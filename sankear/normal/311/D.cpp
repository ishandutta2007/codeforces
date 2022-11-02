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
const int MOD = 95542721;
const int MAGIC = 48;
const int N = int(1e5);

struct tr{
	int add, l, r;
	int val[MAGIC];
};	

int maxv;
int a[N + 100], tmp[MAGIC + 100];
tr rmq[4 * N + 100];

inline int calc(int a, int b){
	int res = 1;
	while(b > 0){
		if(b % 2 != 0){
			res = (ll(res) * a) % MOD;
		}
		a = (ll(a) * a) % MOD;
		b /= 2;
	}
	return res;
}

inline int gcd(int a, int b){
	while(b > 0){
		a %= b;
		swap(a, b);
	}
	return a;
}

inline void norm(int &a){
	if(a >= MOD){
		a -= MOD;
	}
}

inline void push(int v){
	if(rmq[v].add == 0){
		return;
	}
	for(int i = 0; i < MAGIC; i++){
		int ni = (i - rmq[v].add) % MAGIC;
		if(ni < 0){
			ni += MAGIC;
		}
		tmp[ni] = rmq[v].val[i];
	}
	for(int i = 0; i < MAGIC; i++){
		rmq[v].val[i] = tmp[i];
	}
	if(v < maxv){
		rmq[v * 2].add += rmq[v].add;
		rmq[v * 2 + 1].add += rmq[v].add;
	}
	rmq[v].add = 0;
}

inline void calc(int v){
	for(int i = 0; i < MAGIC; i++){
		rmq[v].val[i] = rmq[v * 2].val[i] + rmq[v * 2 + 1].val[i];
		norm(rmq[v].val[i]);
	}
}

void update(int v, int l, int r){
	push(v);
	if(rmq[v].l > r || rmq[v].r < l || l > r){
		return;
	}
	if(rmq[v].l >= l && rmq[v].r <= r){
		rmq[v].add++;
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
		return rmq[v].val[0];
	}
	int res = get(v * 2, l, r) + get(v * 2 + 1, l, r);
	norm(res);
	return res;
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	/*int res = 1;
	for(int i = 0; i < int(1e5); i++){
		int cur = i, ch = i;
		for(int j = 1; ; j++){
			ch = calc(ch, 3);
			if(ch == cur){
				res = (res * j) / gcd(res, j);
				break;
			}
		}
	}
	cerr << res << endl;*/
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		a[i] %= MOD;
	}
	maxv = 1;
	while(maxv < n){
		maxv *= 2;
	}
	for(int i = 0; i < maxv; i++){
		rmq[i + maxv].l = rmq[i + maxv].r = i;
	}
	for(int i = 0; i < n; i++){
		int cur = a[i];
		for(int j = 0; j < MAGIC; j++){
			rmq[i + maxv].val[j] = cur;
			cur = calc(cur, 3);
		}
	}
	for(int i = maxv - 1; i > 0; i--){
		rmq[i].l = rmq[i * 2].l;
		rmq[i].r = rmq[i * 2 + 1].r;
		calc(i);
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int t, l, r;
		scanf("%d %d %d", &t, &l, &r);
		l--;
		r--;
		if(t == 1){
			printf("%d\n", get(1, l, r));
			continue;
		}
		update(1, l, r);
	}
	return 0;
}