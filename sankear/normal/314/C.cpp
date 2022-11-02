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
const int MOD = int(1e9) + 7;
const int N = int(1e5);
const int M = int(1e6);

int maxv;
bool used[M + 100];
int a[N + 100], b[N + 100], d[N + 100];
int rsq[4 * N + 100];

inline void norm(int &a){
	while(a >= MOD){
		a -= MOD;
	}
}

inline void update(int a, int b){
	a += maxv;
	rsq[a] = b;
	while(a > 1){
		a /= 2;
		rsq[a] = rsq[a * 2] + rsq[a * 2 + 1];
		norm(rsq[a]);
	}
}

inline int get(int l, int r){
	int res = 0;
	l += maxv;
	r += maxv;
	while(l <= r){
		if(l % 2 != 0){
			res += rsq[l];
			norm(res);
		}
		l = (l + 1) / 2;
		if(r % 2 == 0){
			res += rsq[r];
			norm(res);
		}
		r = (r - 1) / 2;
	}
	return res;
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
		b[i] = a[i];
	}
	sort(b, b + n);
	int k = unique(b, b + n) - b;
	maxv = 1;
	while(maxv < k){
		maxv *= 2;
	}
	for(int i = 0; i < n; i++){
		int pos = lower_bound(b, b + k, a[i]) - b;
		d[i] = (a[i] + ll(a[i]) * get(0, pos)) % MOD;
		update(pos, d[i]);
	}
	int ans = 0;
	for(int i = n - 1; i >= 0; i--){
		if(used[a[i]]){
			continue;
		}
		used[a[i]] = true;
		ans += d[i];
		norm(ans);
	}
	printf("%d\n", ans);
	return 0;
}