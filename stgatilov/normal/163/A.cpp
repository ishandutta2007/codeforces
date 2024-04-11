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

const int SIZE = 5<<10;
const int MOD = 1000000007;

int n, m;
char str[SIZE];
char im[SIZE];
int res[SIZE][SIZE];
int sum[SIZE][SIZE];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	
	scanf("%s%s", str, im);
	n = strlen(str);
	m = strlen(im);

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (str[i] != im[j]) continue;
			res[i][j] = 1;
			if (i) res[i][j] += sum[i-1][j];
			res[i][j] %= MOD;
		}

		sum[i][0] = 0;
		for (int j = 0; j<m; j++) {
			sum[i][j+1] = sum[i][j] + res[i][j];
			sum[i][j+1] %= MOD;
		}
	}

	int ans = 0;
	for (int i = 0; i<n; i++) {
		ans += sum[i][m];
		ans %= MOD;
	}
	printf("%d\n", ans);

	return 0;
}