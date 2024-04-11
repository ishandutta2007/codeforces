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

int64 n, t;
int64 comb[64][64];

int64 Free(int k, int bs) {
	if (bs < 0 || bs > k)
		return 0;
	return comb[k][bs];
}

int64 Solve(int64 right, int bs) {
	if (right == 0) return 0;

	int pos;
	for (pos = 60; !(right & (1LL<<pos)); pos--);

	int64 res = Free(pos, bs);
    res += Solve(right - (1LL<<pos), bs-1);
    return res;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	for (int i = 0; i<64; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j<i; j++)
			comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
	}

	scanf("%I64d%I64d", &n, &t);
	if (t & (t-1)) {
		printf("0\n");
		return 0;
	}

	int lt = 0;
	while (t > 1) t>>=1, lt++;
	int bits = lt + 1;
	Eo(bits);

	int64 ans = Solve(n+2, bits) - Solve(2, bits);
	printf("%I64d\n", ans);
	
	return 0;
}