//#pragma comment(linker, "/STACK:20000000")
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

const int MAXN = 32;
const int SIZE = (1<<20) + 20;

int n, m;
int arr[SIZE];
int sorted[SIZE], tmp[SIZE];

int curr;
int64 res[MAXN][2];

void Solve(int h, int l, int r) {
	if (r - l == 1) {
		assert(h == n);
		sorted[l] = arr[l];
		return;
	}
	int m = (l + r) / 2;
	Solve(h+1, l, m);
	Solve(h+1, m, r);

	int64 tinv = 0;
	int pl = l, pr = m;
	int pall = 0;
	while (pl < m || pr < r) {
		bool mr = false;
		if (pl == m) mr = true;
		else if (pr == r) mr = false;
		else mr = sorted[pr] < sorted[pl];

		if (mr)
			tmp[pall++] = sorted[pr++];
		else {
			tmp[pall++] = sorted[pl++];
			tinv += (pr - m);
		}
	}
	assert(pall == r-l);
	memcpy(&sorted[l], &tmp[0], (r-l) * sizeof(sorted[0]));

/*	Eo(l);
	Eo(r);
	Eo(tinv);*/

	res[h][curr] += tinv;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	for (int i = 0; i < 1<<n; i++) scanf("%d", &arr[i]);

	for (curr = 0; curr < 2; curr++) {
		Solve(0, 0, 1<<n);

		for (int i = 0; i+1 < 1<<n; i++)
			assert(sorted[i] <= sorted[i+1]);

		for (int i = n-1; i>=0; i--)
			res[i][curr] += res[i+1][curr];

		reverse(arr, arr + (1<<n));
	}

	for (int i = 0; i<=n; i++) Ef("%I64d %I64d\n", res[i][0], res[i][1]); Ef("\n");

	scanf("%d", &m);
	for (int i = 0; i<m; i++) {
		int q;
		scanf("%d", &q);
		q = n-q;

		int64 delta[2];
		for (int t = 0; t<2; t++)
			delta[t] = res[q][!t] - res[q][t];
/*		Eo(q);
		Eo(delta[0]);
		Eo(delta[1]);*/

		for (int h = q; h<=n; h++) swap(res[h][0], res[h][1]);
		for (int h = q-1; h>=0; h--)
			for (int t = 0; t<2; t++)
				res[h][t] += delta[t];

//		for (int i = 0; i<=n; i++) Ef("%I64d %I64d\n", res[i][0], res[i][1]); Ef("\n");

		printf("%I64d\n", res[0][0]);
	}

	return 0;
}