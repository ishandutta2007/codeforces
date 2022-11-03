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

const int SIZE = 2<<10;
const int MOD = 1000000007;

int n, k;
int res[SIZE][SIZE];

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &k);

	for (int j = 1; j<=n; j++) res[1][j] = 1;

	for (int i = 1; i<k; i++)
		for (int j = 1; j<=n; j++) if (res[i][j]) {
			for (int u = 1, curr = j; curr <= n; u++, curr += j) 
				add(res[i+1][curr], res[i][j]);
		}

	int ans = 0;
	for (int j = 1; j<=n; j++) add(ans, res[k][j]);
	
	printf("%d\n", ans);

	return 0;
}