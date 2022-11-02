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
const int N = int(3e5);

int maxv;
int a[N + 10], p[N + 10];
int rsq[4 * N + 10];

inline int get(int l, int r){
	int res = 0;
	l += maxv;
	r += maxv;
	while(l <= r){
		if(l % 2 != 0){
			res += rsq[l];
		}
		l = (l + 1) / 2;
		if(r % 2 == 0){
			res += rsq[r];
		}
		r = (r - 1) / 2;
	}
	return res;
}

inline void update(int a, int b){
	a += maxv;
	rsq[a] = b;
	while(a > 1){
		a /= 2;
		rsq[a] = rsq[a * 2] + rsq[a * 2 + 1];
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		a[i]--;
		p[a[i]] = i;
	}
	maxv = 1;
	while(maxv < n){
		maxv *= 2;
	}
	for(int i = 0; i < n - 1; i++){
		if(p[i] > p[i + 1]){
			rsq[i + maxv] = 1;
		}
	}
	for(int i = maxv - 1; i > 0; i--){
		rsq[i] = rsq[i * 2] + rsq[i * 2 + 1];
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y);
		x--;
		y--;
		if(t == 1){
			int ans = get(x, y - 1) + 1;
			printf("%d\n", ans);
			continue;
		}
		p[a[x]] = y;
		p[a[y]] = x;
		swap(a[x], a[y]);
		if(a[x] > 0){
			update(a[x] - 1, p[a[x] - 1] > p[a[x]]);
		}
		update(a[x], (a[x] + 1 < n && p[a[x]] > p[a[x] + 1]));
		if(a[y] > 0){
			update(a[y] - 1, p[a[y] - 1] > p[a[y]]);
		}
		update(a[y], (a[y] + 1 < n && p[a[y]] > p[a[y] + 1]));
	}
	return 0;
}