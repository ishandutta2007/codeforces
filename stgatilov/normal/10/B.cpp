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
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

int n, k, c;
bool matr[128][128];

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	c = k / 2;
	for (int i = 0; i<n; i++) {
		int m;
		scanf("%d", &m);

		int mins = 1000000000;
		int bx = -1;
		int byl = -1;

		for (int x = 0; x<k; x++) {
			for (int yl = 0; ; yl++) {
				int yr = yl + m;
				if (yr > k) break;

				int j;
				for (j = yl; j<yr; j++) if (matr[x][j]) break;
				if (j < yr) continue;

				int sum = 0;
				for (j = yl; j<yr; j++) sum += abs(j - c) + abs(x - c);
				if (sum < mins || (sum == mins && x < bx) || (sum == mins && x == bx && yl < byl)) {
					mins = sum;
					bx = x;
					byl = yl;
				}
			}
		}

		if (mins == 1000000000) printf("-1\n");
		else {
			printf("%d %d %d\n", bx+1, byl+1, byl+m);
			for (int j = byl; j<byl+m; j++) matr[bx][j] = true;
		}
	}
	
	return 0;
}