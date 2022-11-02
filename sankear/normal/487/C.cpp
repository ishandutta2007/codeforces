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

int n;
bool used[100], use[100];
int perm[100];

inline void gen(int x) {
	if (x >= n) {
		int cur = 1;
		for (int i = 0; i < n; ++i) {
			use[i] = false;
		}
		for (int i = 0; i < n; ++i) {
			cur = (cur * perm[i]) % n;
			if (use[cur]) {
				return;
			}
			use[cur] = true;
		}
		for (int i = 0; i < n; ++i) {
			cout << perm[i] << " ";
		}
		cout << endl;
		cur = 1;
		for (int i = 0; i < n; ++i) {
			cur = (cur * perm[i]) % n;
			cout << cur << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			perm[x] = i;
			used[i] = true;
			gen(x + 1);
			used[i] = false;
		}
	}
}

inline bool is_prime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

inline int calc(int a, int b, int c) {
	int res = 1;
	while (b > 0) {
		if (b % 2 != 0) {
			res = (1LL * res * a) % c;
		}
		a = (1LL * a * a) % c;
		b /= 2;
	}
	return res;
}

int main() {
#ifdef LOCAL42
#define TASK "C"
	freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
#else

#endif
	/*for (n = 1; n <= 10; ++n) {
		cout << "n = " << n << endl;
		gen(0);
	}*/
	int n;
	cin >> n;
	if (n == 4) {
		cout << "YES" << endl;
		cout << 1 << endl;
		cout << 3 << endl;
		cout << 2 << endl;
		cout << 4 << endl;
		return 0;
	}
	if (n == 1) {
		cout << "YES" << endl;
		cout << 1 << endl;
		return 0;
	}
	if (!is_prime(n)) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	int cur = 1;
	for (int i = 1; i < n; ++i) {
		int need = (1LL * i * calc(cur, n - 2, n)) % n;
		printf("%d\n", need);
		cur = (1LL * cur * need) % n;
	}
	printf("%d\n", n);
	return 0;
}