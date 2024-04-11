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
#include <queue>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define len(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || __WIN32__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define hash _hash
#define y0 yy0
#define y1 yy1
#define link _link

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 2020;

struct ta {
	
	int t, h, m;
	
};

int n, x;
bool used[N];
ta a[N];

inline int solve(int step) {
	int cur = x;
	for (int i = 0; i < n; ++i) {
		used[i] = false;
	}
	int ans = 0;
	while (true) {
		int v = -1;
		for (int i = 0; i < n; ++i) {
			if (!used[i] && a[i].t == step && a[i].h <= cur && (v == -1 || a[i].m > a[v].m)) {
				v = i;
			}
		}
		if (v == -1) {
			break;
		}
		++ans;
		step ^= 1;
		used[v] = true;
		cur += a[v].m;
	}
	return ans;
}

int main() {
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d", &a[i].t, &a[i].h, &a[i].m);
	}
	int ans = max(solve(0), solve(1));
	printf("%d\n", ans);
	return 0;
}