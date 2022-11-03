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
/*int power(int a, int k) {
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
}*/

const int SIZE = 104;

int c, w, h;
int n;

struct Matr {
	int a[SIZE][SIZE];
	
	void Zero() {
		memset(a, 0, sizeof(a));
	}
	void Identity() {
		Zero();
		for (int i = 0; i < n; i++)
			a[i][i] = 1;
	}
};

Matr mult(Matr a, Matr b) {
	Matr res;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int64 t = 0;
			for (int u = 0; u < n; u++)
				t += int64(a.a[i][u]) * b.a[u][j];
			res.a[i][j] = t % MOD;
		}
	return res;
}
Matr power(Matr x, int k) {
	Matr res;
	res.Identity();
	for (; k > 0; k >>= 1) {
		if (k & 1)
			res = mult(res, x);
		x = mult(x, x);
	}
	return res;
}


int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d%d", &c, &w, &h);

	n = w+1;

	Matr transition;
	transition.Zero();
	for (int i = 0; i <= w; i++) {
		transition.a[i][0] = 1;
		if (i < w)
			transition.a[i][i+1] = h;
	}

	Matr all = power(transition, c);
	int ans = 0;
	for (int i = 0; i <= w; i++)
		add(ans, all.a[0][i]);

	printf("%d\n", ans);

	return 0;
}