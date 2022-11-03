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

const int MOD = 1000003;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}
int mult(int a, int b) {
	return (int64(a) * b) % MOD;
}
int power(int a, int k) {
	int res = 1;
	int x = a;
	for (; k > 0; k >>= 1) {
		if (k & 1)
			res = mult(res, x);
		x = mult(x, x);
	}
	return res;
}
int inv(int a) {
	return power(a, MOD-2);
}

const int SIZE = MOD;
int n, c;
int fact[SIZE];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &c);

	fact[0] = 1;
	for (int i = 1; i < SIZE; i++)
		fact[i] = mult(fact[i-1], i);

	int ans = 0;
	for (int k = 1; k <= n; k++)
		add(ans, mult(fact[k+c-1], inv(mult(fact[k], fact[c-1]))));

	printf("%d\n", ans);

	return 0;
}