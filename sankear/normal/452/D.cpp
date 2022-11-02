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

int tm1[1010], tm2[1010], tm3[1010];

inline pii get(int *a, int n) {
	int pos = min_element(a, a + n) - a;
	return mp(a[pos], pos);
}

int main() {
	int k;
	cin >> k;
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	int t1, t2, t3;
	cin >> t1 >> t2 >> t3;
	for (int i = 0; i < k; ++i) {
		pii c1 = get(tm1, n1), c2 = get(tm2, n2), c3 = get(tm3, n3);
		int can = max(c1.fs, max(c2.fs - t1, c3.fs - t1 - t2));
		tm1[c1.sc] = can + t1;
		tm2[c2.sc] = can + t1 + t2;
		tm3[c3.sc] = can + t1 + t2 + t3;
	}
	int ans = 0;
	for (int i = 0; i < n3; ++i) {
		ans = max(ans, tm3[i]);
	}
	cout << ans << endl;
    return 0;
}