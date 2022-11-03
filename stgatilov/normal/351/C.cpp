#pragma comment(linker, "/STACK:20000000")
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

const int SIZE = 128;
const int MAXN = 24;
const int64 INF = 1000000000000000000LL;

int n, m;
int open[MAXN], close[MAXN];
int64 block[SIZE][SIZE];

int s;
struct Matr {
	int64 a[SIZE][SIZE];
};
Matr graph;

Matr Mult(Matr a, Matr b) {
	Matr res;
	for (int i = 0; i<s; i++)
		for (int j = 0; j<s; j++) {
			int64 ans = INF;
			for (int u = 0; u<s; u++)
				ans = min(ans, a.a[i][u] + b.a[u][j]);
			res.a[i][j] = ans;
		}
	return res;
}

Matr Identity() {
	Matr res;
	memset(&res, 63, sizeof(res));
	for (int i = 0; i<s; i++) res.a[i][i] = 0;
	return res;
}


Matr pwr(Matr a, int p) {
	Matr res = Identity();
	Matr x = a;
	for (; p; p>>=1) {
		if (p & 1) res = Mult(res, x);
		x = Mult(x, x);
	}
	return res;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &m);
	for (int i = 0; i<n; i++) scanf("%d", &open[i]);
	for (int i = 0; i<n; i++) scanf("%d", &close[i]);

	memset(block, 63, sizeof(block));
	for (int mask = 0; mask < 1<<n; mask++) {
		int bal = 0;
		int minb = 0;
		int cst = 0;
		for (int i = 0; i<n; i++) {
			if (mask & (1<<i)) {
				bal++;
				cst += open[i];
			}
			else {
				bal--;
				minb = min(minb, bal);
				cst += close[i];
			}
		}

		auto& num = block[MAXN + bal][-minb];
		if (num > cst)
			num = cst;
	}

	s = 3*n+1;
	memset(&graph, 63, sizeof(graph));
	for (int i = 0; i<s; i++)
		for (int r = 0; r<=i; r++)
			for (int b = -n; b<=n; b++) {
				int64 cst = block[MAXN + b][r];
				if (cst > INF) continue;
				auto& num = graph.a[i][i+b];
				num = min(num, cst);
			}

/*	for (int i = 0; i<s; i++)
		for (int j = 0; j<s; j++)
			if (graph.a[i][j] < INF)
				Ef("%d -> %d in %d\n", i, j, graph.a[i][j]);*/

	Matr trans = pwr(graph, m);
	printf("%I64d\n", trans.a[0][0]);

	return 0;
}