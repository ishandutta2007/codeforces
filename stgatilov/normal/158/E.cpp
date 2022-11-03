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

const int T = 86400;
const int N = 4096;

int n, k;
int st[N], len[N];
int res[N][N];

inline void relax(int &a, int b) {
	if (a > b) a = b;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &k);
	for (int i = 0; i<n; i++) {
		scanf("%d%d", &st[i], &len[i]);
		st[i]--;
	}

	memset(res, 63, sizeof(res));
	res[0][0] = 0;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<=k; j++) if (res[i][j] < 1000000000) {
			relax(res[i+1][j+1], res[i][j]);
			relax(res[i+1][j], max(res[i][j], st[i]) + len[i]);
		}

	int ans = 0;
	for (int i = 0; i<=n; i++) {
		int begin = 1000000000;
		for (int j = 0; j<=k; j++)
			relax(begin, res[i][j]);
		int end = (i<n ? st[i] : T);

		ans = max(ans, end - begin);
	}

	printf("%d\n", ans);
	return 0;
}