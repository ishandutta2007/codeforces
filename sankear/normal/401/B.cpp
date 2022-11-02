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
const int X = 4040;

bool used[X];

int main() {
	int x, k;
	scanf("%d %d", &x, &k);
	for (int i = 0; i < k; ++i) {
		int t, num2;
		scanf("%d %d", &t, &num2);
		used[num2] = true;
		if (t == 1) {
			int num1;
			scanf("%d", &num1);
			used[num1] = true;
		}
	}
	int ansMin = 0, ansMax = 0;
	int i = 1;
	while (i < x) {
		if (used[i]) {
			++i;
			continue;
		}
		int j = i;
		while (j + 1 < x && !used[j + 1]) {
			++j;
		}
		ansMin += (j - i + 2) / 2;
		ansMax += j - i + 1;
		i = j + 1;
	}
	printf("%d %d\n", ansMin, ansMax);
	return 0;
}