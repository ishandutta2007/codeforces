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

const int SIZE = 640;

int h, w;
int matr[SIZE][SIZE];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	int q;
	scanf("%d", &q);

	for (int tt = 0; tt < q; tt++) {
		scanf("%d%d", &h, &w);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				scanf("%d", &matr[i][j]);

		int cut = h/2;

		int diffZero = 0;
		int diffSwap = 0;
		for (int j = 0; j < w; j++) {
			diffZero += abs(matr[cut-1][j] - matr[cut][j]);
			diffSwap += abs(matr[0][j] - matr[h-1][j]);
		}

		Ef("%d -> %d\n", diffZero, diffSwap);
		printf(diffZero < diffSwap ? "NO\n" : "YES\n");
	}

	return 0;
}