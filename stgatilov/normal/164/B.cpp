#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int SIZE = 2<<20;

int n, m;
int str[SIZE];
int seq[SIZE];
int sind[SIZE];
int64 subseq[SIZE];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &m);
	for (int i = 0; i<n; i++) scanf("%d", &str[i]);
	for (int i = 0; i<m; i++) scanf("%d", &seq[i]);

	memset(sind, -1, sizeof(sind));
	for (int i = 0; i<m; i++) sind[seq[i]] = i;

	bool hasans = false;
	for (int i = 0; i<n; i++) if (sind[str[i]] >= 0) hasans = true;
	if (!hasans) {
		printf("0\n");
		return 0;
	}

	memmove(str + n, str, n * sizeof(str[0]));

	bool bad = false;
	for (int i = 0; i<2*n; i++) {
		int c = str[i];
		int pos = sind[c];
		int64 prev = (i ? subseq[i-1] : 0);

		if (pos >= 0) {
			subseq[i] = (prev / m) * m + pos;
			while (subseq[i] < prev) subseq[i] += m;

			if (bad) subseq[i] += 2*m;
			bad = false;
		}
		else {
			subseq[i] = prev + 2*m;
			bad = true;
		}
	}

//	for (int i = 0; i<2*n; i++) printf("%I64d %I64d %I64d\n", subseq[i], subseq[i] / m, subseq[i] % m);

	int ans = 0;
	int r = 0;
	for (int l = 0; l<2*n; l++) {
		while (r<2*n && subseq[r] - subseq[l] < m)
			r++;
		if (r-l > ans) ans = r-l;
	}

	if (ans > n) ans = n;
	printf("%d\n", ans);

	return 0;
}