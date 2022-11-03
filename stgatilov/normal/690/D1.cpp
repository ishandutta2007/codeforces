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

const int SIZE = 1024;

int r, c;
char matr[SIZE][SIZE];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &r, &c);
	for (int i = r-1; i >= 0; i--)
		scanf("%s", matr[i]);

	int ans = 0;

	int last = -10000;
	for (int j = 0; j < c; j++) {
		int hgt = 0;
		while (hgt < r && matr[hgt][j] == 'B')
			hgt++;

		if (hgt > 0) {
			if (j - last > 1)
				ans++;
			last = j;
		}
	}
	
	printf("%d\n", ans);

	return 0;
}