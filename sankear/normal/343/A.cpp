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

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll a, b;
	scanf(LLD" "LLD, &a, &b);
	ll ans = 0;
	while(a > 0){
		if(a >= b){
			ll k = a / b;
			while(a - (k - 1) * b < b){
				k--;
			}
			while(a - k * b >= b){
				k++;
			}
			ans += k;
			a -= k * b;
		}
		else{
			ll k = b / a;
			while(b - (k - 1) * a <= a){
				k--;
			}
			while(b - k * a > a){
				k++;
			}
			ans += k;
			b -= k * a;
		}
	}
	printf(LLD"\n", ans);
	return 0;
}