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

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll l, r;
	scanf(LLD" "LLD, &l, &r);
	ll ans = 0;
	for(int i = 1; i <= 60; i++){
		ll l2 = (1LL << i) - r - 1, r2 = (1LL << i) - l - 1;
		if(l2 > r){
			continue;
		}
		if(max(l, l2) <= min(r, r2)){
			ans = max(ans, (1LL << i) - 1);
			continue;
		}
		if(r2 < r){
			ll k = (r - r2) / (1LL << i);
			l2 += (1LL << i) * k;
			r2 += (1LL << i) * k;
			if(max(l, l2) <= min(r, r2)){
				ans = max(ans, (1LL << i) - 1);
				continue;
			}
			l2 += (1LL << i);
			r2 += (1LL << i);
			if(max(l, l2) <= min(r, r2)){
				ans = max(ans, (1LL << i) - 1);
			}
		}
	}
	printf(LLD"\n", ans);
	return 0;
}