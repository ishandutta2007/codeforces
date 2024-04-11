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

const ll inf = ll(1e17);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(3e5);

int a[N + 10], b[N + 10], lst[N + 10], min_pos[N + 10], max_pos[N + 10];
ll s[N + 10];

inline ll get_sum(int l, int r){
	if(l > r){
		return 0;
	}
	return s[r] - (l > 0 ? s[l - 1] : 0);
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
	for(int i = 0; i < n; i++){
		s[i] = (i > 0 ? s[i - 1] : 0);
		if(a[i] > 0){
			s[i] += a[i];
		}
	}
	for(int i = 0; i < k; i++){
		min_pos[i] = n;
		max_pos[i] = -1;
	}
	for(int i = 0; i < n; i++){
		int pos = lower_bound(b, b + k, a[i]) - b;
		min_pos[pos] = min(min_pos[pos], i);
		max_pos[pos] = max(max_pos[pos], i);
	}
	ll ans = -inf;
	int l, r;
	for(int i = 0; i < k; i++){
		if(min_pos[i] < max_pos[i]){
			ll sum = get_sum(min_pos[i] + 1, max_pos[i] - 1) + 2LL * b[i];
			if(sum > ans){
				ans = sum;
				l = min_pos[i];
				r = max_pos[i];
			}
		}
	}
	int sz = 0;
	for(int i = 0; i < l; i++){
		lst[sz++] = i;
	}
	for(int i = l + 1; i < r; i++){
		if(a[i] <= 0){
			lst[sz++] = i;
		}
	}
	for(int i = r + 1; i < n; i++){
		lst[sz++] = i;
	}
	printf(LLD" %d\n", ans, sz);
	for(int i = 0; i < sz; i++){
		printf("%d ", lst[i] + 1);
	}
	puts("");
	return 0;
}