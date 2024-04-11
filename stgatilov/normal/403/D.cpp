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

const int MAXN = 1<<10;
const int SIZE = 2*MAXN;
const int MOD = 1000000007;
const int64 MOD2 = int64(MOD) * MOD;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int mult(int a, int b) {
	return (int64(a) * b) % MOD;
}

int fact[SIZE];
int comb[SIZE][SIZE];
int combt[SIZE][SIZE];
int parts[MAXN][MAXN];
int pord[MAXN][MAXN];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	
	fact[0] = 1;
	for (int i = 1; i<SIZE; i++)
		fact[i] = mult(fact[i-1], i);

	for (int i = 0; i<SIZE; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j<i; j++) {
			comb[i][j] = comb[i-1][j-1];
			add(comb[i][j], comb[i-1][j]);
		}
	}
	for (int i = 0; i<SIZE; i++)
		for (int j = 0; j<SIZE; j++)
			combt[j][i] = comb[i][j];

	parts[0][0] = 1;
	for (int k = 1; k<MAXN; k++)
		for (int n = 0; n<MAXN; n++)
			for (int x = 1, rem = n - k; rem >= 0; x++, rem -= k)
				add(parts[k][n], parts[k-1][rem]);
	for (int k = 0; k<MAXN; k++) {
		for (int n = 0; n<MAXN; n++)
			pord[k][n] = mult(parts[k][n], fact[k]);
	}
	E(!);

	int tests;
	scanf("%d", &tests);
//	tests = 200000;
	for (int tt = 0; tt < tests; tt++) {
		int n, k;
		scanf("%d%d", &n, &k);
//		n = 1000; k = 10;

		int64 ans = 0;
		for (int a = n-k; a >= 0; a--) {
			int z = n-k-a;
//			add(ans, mult(combt[k][a+k], pord[k][z+k]));
			ans += int64(combt[k][a+k]) * pord[k][z+k];
			while (ans >= MOD2) ans -= MOD2;
		}
		ans %= MOD;
		printf("%d\n", int(ans));
	}

	E(!);


	return 0;
}