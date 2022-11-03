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

int n, m;
int matr[1024][1024];

int k;
int ans[1024][3];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &m);
	memset(matr, -1, sizeof(matr));
	for (int i = 0; i<m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--;  b--;
		matr[a][b] = c;
	}

	for (int i = 0; i<n; i++) {
		int inc = 0, outc = 0;
		for (int j = 0; j<n; j++) {
			outc += (matr[i][j] >= 0);
			inc += (matr[j][i] >= 0);
		}
		if (inc == 0 && outc == 1) {
			int q = i;
			int maxd = 1000000000;
			while (1) {
				int j;
				for (j = 0; j<n; j++) if (matr[q][j] >= 0) {
					maxd = min(maxd, matr[q][j]);
					q = j;
					break;
				}
				if (j == n) break;
			}
			ans[k][0] = i;
			ans[k][1] = q;
			ans[k][2] = maxd;
			k++;
		}
	}
	printf("%d\n", k);
	for (int i = 0; i<k; i++) printf("%d %d %d\n", ans[i][0] + 1, ans[i][1] + 1, ans[i][2]);
	return 0;
}