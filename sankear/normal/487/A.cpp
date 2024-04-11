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
#include <stack>
#include <queue>
#include <deque>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#define fs first
#define sc second

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

int hp[2], atk[2], def[2];

inline bool check(int hp1, int atk1, int def1, int hp2, int atk2, int def2) {
	int can1 = max(0, atk1 - def2);
	int can2 = max(0, atk2 - def1);
	if (can1 == 0) {
		return false;
	}
	if (can2 == 0) {
		return true;
	}
	int need1 = (hp1 + can2 - 1) / can2, need2 = (hp2 + can1 - 1) / can1;
	return need1 > need2;
}

int main() {
#ifdef LOCAL42
#define TASK "A"
	freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
#else

#endif
	for (int i = 0; i < 2; ++i) {
		scanf("%d %d %d", &hp[i], &atk[i], &def[i]);
	}
	int h, a, d;
	scanf("%d %d %d", &h, &a, &d);
	int ans = inf;
	for (int i = 0; i < 1000; ++i) {
		for (int j = 0; j < 1000; ++j) {
			int l = 0, r = int(1e7);
			while (l <= r) {
				int mid = (l + r) / 2;
				if (check(hp[0] + mid, atk[0] + i, def[0] + j, hp[1], atk[1], def[1])) {
					ans = min(ans, mid * h + a * i + d * j);
					r = mid - 1;
				} else {
					l = mid + 1;
				}
			}
		}
	}
	cout << ans << endl;
	cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}