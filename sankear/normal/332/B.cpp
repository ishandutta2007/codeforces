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

const ll inf = ll(1e18);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(2e5);

int a[N + 10], ptr[N + 10];
ll s[N + 10], d[N + 10];

inline ll get_sum(int l, int r){
	return s[r] - (l > 0 ? s[l - 1] : 0);
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		s[i] = (i > 0 ? s[i - 1] : 0) + a[i];
	}
	for(int i = 0; i < n; i++){
		d[i] = -inf;
		if(i > 0){
			d[i] = d[i - 1];
			ptr[i] = ptr[i - 1];
		}
		if(i >= k - 1){
			ll cur = get_sum(i - k + 1, i);
			if(cur > d[i]){
				d[i] = cur;
				ptr[i] = i - k + 1;
			}
		}
	}
	ll ans = -inf;
	int x = -1, y = -1;
	for(int i = n - 1; i > 0; i--){
		if(i + k - 1 < n){
			ll res = get_sum(i, i + k - 1) + d[i - 1];
			if(res >= ans){
				ans = res;
				x = ptr[i - 1];
				y = i;
			}
		}
	}
	printf("%d %d\n", x + 1, y + 1);
	//cerr << ans << endl;
	return 0;
}