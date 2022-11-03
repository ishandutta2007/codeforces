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

const int SIZE = 1<<20;

int n, m;
int arr[SIZE];
int stk;
int stx[SIZE], sty[SIZE];

int64 sum[SIZE];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	for (int i = 0; i<n; i++) scanf("%d", &arr[i]);
	arr[n] = 0;

	stx[0] = -1;
	sty[0] = 0;
	stk = 1;

	for (int i = 0; i<=n; i++) {
		int q = arr[i];

		while (q < sty[stk-1]) {
			int newlvl = max(q, sty[stk-2]);
			int hgt = sty[stk-1] - newlvl;
			int len = i - stx[stk-1];

			sum[len] += hgt;

			sty[stk-1] -= hgt;
			if (sty[stk-1] == sty[stk-2])
				stk--;
		}

		if (q > sty[stk-1]) {
			stx[stk] = i;
			sty[stk] = q;
			stk++;
		}
	}

//	for (int i = 1; i<=n; i++) printf("%I64d ", sum[i]); printf("\n");
	int64 curr = 0;
	for (int i = n; i>0; i--) {
		curr += sum[i];
		sum[i] = curr;
	}
//	for (int i = 1; i<=n; i++) printf("%I64d ", sum[i]); printf("\n");
	curr = 0;
	for (int i = n; i>0; i--) {
		curr += sum[i];
		sum[i] = curr;
	}
//	for (int i = 1; i<=n; i++) printf("%I64d ", sum[i]); printf("\n");


	scanf("%d", &m);
	for (int i = 0; i<m; i++) {
		int ll;
		scanf("%d", &ll);

		int combs = n - ll + 1;
		double res = double(sum[ll]) / combs;
//		printf("%I64d %d\n", sum[ll], combs);
		printf("%0.15lf\n", res);
	}

	return 0;
}