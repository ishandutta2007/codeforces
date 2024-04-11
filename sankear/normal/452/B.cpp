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

int n, m;
double res;
pii p[4], best[4];
set<pii> s;

inline double sqr(double a) {
	return a * a;
}

inline double dist(pii a, pii b) {
	return sqrt(sqr(a.fs - b.fs) + sqr(a.sc - b.sc));
}

void gen(int x) {
	if (x >= 4) {
		double ans = 0;
		for (int i = 0; i < 3; ++i) {
			ans += dist(p[i], p[i + 1]);
		}
		if (ans > res) {
			res = ans;
			for (int i = 0; i < 4; ++i) {
				best[i] = p[i];
			}
		}
		return;
	}
	for (set<pii>::iterator it = s.begin(); it != s.end(); ++it) {
		p[x] = *it;
		bool fl = false;
		for (int i = 0; i < x; ++i) {
			if (p[i] == p[x]) {
				fl = true;
				break;
			}
		}
		if (!fl) {
			gen(x + 1);
		}
	}
}

inline void add(int x, int y) {
	if (x >= 0 && x <= n && y >= 0 && y <= m) {
		s.insert(mp(x, y));
	}
}

int main() {
	cin >> n >> m;
	res = 0;
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			add(i, j);
			add(n + i, j);
			add(n + i, m + j);
			add(i, m + j);
		}
	}
	gen(0);
	for (int i = 0; i < 4; ++i) {
		cout << best[i].fs << " " << best[i].sc << endl;
	}
    return 0;
}