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

const ll inf = ll(1e11);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5);

ll a[N + 10], b[N + 10], c[N + 10], can[N + 10];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf(LLD, &a[i]);
	}
	for(int i = 0; i < m; i++){
		scanf(LLD, &b[i]);
	}
	ll ans = inf, l = 0, r = inf;
	while(l <= r){
		ll mid = (l + r) / 2;
		int ptr = -1;
		for(int i = 0; i < n; i++){
			int nptr = ptr;
			while(nptr + 1 < m){
				ll l = max(a[i] - b[ptr + 1], 0LL), r = max(b[nptr + 1] - a[i], 0LL);
				if(min(2 * l + r, 2 * r + l) <= mid){
					nptr++;
				}
				else{
					break;
				}
			}
			ptr = nptr;
		}
		if(ptr == m - 1){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	printf(LLD"\n", ans);
	return 0;
}