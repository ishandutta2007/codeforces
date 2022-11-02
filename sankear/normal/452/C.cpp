#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#ifdef LOCAL42
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif
#define next _next
#define prev _prev
#define hash _hash
#define rank _rank
#define link _link

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<double> tc;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const double eps = 1e-9;

inline ld cnk(int n, int k) {
	if (k > n) {
		return 0;
	}
	ld res = 1;
	for (int i = 1; i <= k; ++i) {
		res = res / i * (n - i + 1);
	}
	return res;
}

inline ld sqr(ld a) {
	return a * a;
}

int main() {
	int n, m;
	cin >> n >> m;
	ld ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += cnk(m, i) * cnk(n * m - m, n - i) / cnk(n * m, n) * sqr(i) / n;
	}
	printf("%.18lf\n", (double) ans);
    return 0;
}