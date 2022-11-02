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

inline void fail(){
	puts("-1");
	exit(0);
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll x, y, m;
	scanf(LLD" "LLD" "LLD, &x, &y, &m);
	ll ans = 0;
	while(x < m && y < m){
		if(x < 0 && y < 0){
			fail();
		}
		if(x < y){
			if(y == 0){
				fail();
			}
			ll k = (y - x + y - 1) / y;
			k = max(k, 1LL);
			x += k * y;
			ans += k;
		}
		else{
			if(x == 0){
				fail();
			}
			ll k = (x - y + x - 1) / x;
			k = max(k, 1LL);
			y += k * x;
			ans += k;
		}
	}
	printf(LLD"\n", ans);
	return 0;
}