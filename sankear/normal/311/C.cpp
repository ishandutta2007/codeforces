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
const int K = int(1e4);
const int SZ = 20;
const int N = int(1e5);

ll h;
int n, k, sz, maxv;
set <pair <ll, int> > s;
ll lst[SZ + 10];
ll d[K + 100];
ll a[N + 100];
int b[N + 100];
pii rmq[4 * N + 100];

inline void build(){
	for(int i = 0; i < k; i++){
		d[i] = h + 1;
	}
	d[0] = 0;
	s.insert(mp(d[0], 0));
	while(!s.empty()){
		int cur = s.begin()->sc;
		s.erase(s.begin());
		for(int i = 0; i < sz; i++){
			int ncur = (cur + lst[i]) % k;
			if(d[ncur] > d[cur] + lst[i]){
				s.erase(mp(d[ncur], ncur));
				d[ncur] = d[cur] + lst[i];
				s.insert(mp(d[ncur], ncur));
			}
		}
	}
	for(int i = 0; i < maxv; i++){
		rmq[i + maxv] = mp(-inf, 1);
	}
	for(int i = 0; i < n; i++){
		if(b[i] > 0 && d[a[i] % k] <= a[i]){
			rmq[i + maxv] = mp(b[i], -i);
		}
	}
	for(int i = maxv - 1; i > 0; i--){
		rmq[i] = max(rmq[i * 2], rmq[i * 2 + 1]);
	}
}

inline void update(int a, int b){
	a += maxv;
	rmq[a] = mp(b, -(a - maxv));
	while(a > 1){
		a /= 2;
		rmq[a] = max(rmq[a * 2], rmq[a * 2 + 1]);
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m;
	scanf(LLD" %d %d %d", &h, &n, &m, &k);
	for(int i = 0; i < n; i++){
		scanf(LLD" %d", &a[i], &b[i]);
		a[i]--;
	}
	maxv = 1;
	while(maxv < n){
		maxv *= 2;
	}
	sz = 0;
	build();
	for(int i = 0; i < m; i++){
		int t;
		scanf("%d", &t);
		if(t == 1){
			scanf(LLD, &lst[sz++]);
			build();
			continue;
		}
		if(t == 2){
			int x, y;
			scanf("%d %d", &x, &y);
			x--;
			b[x] -= y;
			if(d[a[x] % k] <= a[x]){
				update(x, b[x]);
			}
			continue;
		}
		int best = rmq[1].sc;
		if(best > 0 || rmq[1].fs <= 0){
			puts("0");
			continue;
		}
		best *= -1;
		printf("%d\n", b[best]);
		b[best] = 0;
		update(best, -inf);
	}
	return 0;
}