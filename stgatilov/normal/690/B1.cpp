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

int n;
char matr[128][128];
char check[128][128];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
		scanf("%s", matr[i]);

    int cnt4 = 0;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++) {
			matr[i][j] -= '0';
			cnt4 += (matr[i][j] == 4);
		}
	
	int ansCnt = 0;

	for (int x1 = 0; x1 <= n; x1++)
		for (int y1 = 0; y1 <= n; y1++) {
			if (x1 > 0 && y1 > 0 && matr[x1-1][y1-1] != 1)
				continue;

			for (int x2 = x1+1; x2 <= n; x2++)
				for (int y2 = y1+1; y2 <= n; y2++) {
					if (x2 < n && y2 < n && matr[x2][y2] != 1)
						continue;
					if ((x2-x1) * (y2-y1) != cnt4)
						continue;

					bool ok = true;

					memset(check, 0, sizeof(check));
					for (int i = x1; ok && i <= x2; i++)
						for (int j = y1; ok && j <= y2; j++) {
							check[i][j]++;
							if (i) check[i-1][j]++;
							if (j) check[i][j-1]++;
							if (i && j) check[i-1][j-1]++;

							if (i && j && check[i-1][j-1] != matr[i-1][j-1])
								ok = false;
								
						}

					for (int i = 0; ok && i < n; i++)
						for (int j = 0; ok && j < n; j++)
							if (check[i][j] != matr[i][j])
								ok = false;

					if (ok)
						ansCnt++;
				}
		}

	printf(ansCnt == 1 ? "Yes" : "No");

	return 0;
}