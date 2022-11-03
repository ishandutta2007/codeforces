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

typedef double real;
const real EPS = 1e-15;

int n, m;
int x, y;
real prob[1024][1024];
real res[1024][1024];
real temp[1024], tres[1024];

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &m);
	scanf("%d%d", &x, &y);
	x--; y--;
	prob[x][y] = 1.0;
	for (int i = x; i<n-1; i++) {
		while (1) {
			bool rep = false;
			memset(temp, 0, sizeof(temp));
			memset(tres, 0, sizeof(tres));
			for (int j = 0; j<m; j++) if (prob[i][j] > EPS) {
				rep = true;
				int t = 2 + (j>0) + (j<m-1);
				real cp = prob[i][j] / t;
				real cr = res[i][j] / t + cp;

				prob[i+1][j] += cp;
				res[i+1][j] += cr;
				temp[j] += cp;
				tres[j] += cr;
				if (j > 0) {
					temp[j-1] += cp;
					tres[j-1] += cr;
				}
				if (j < m-1) {
					temp[j+1] += cp;
					tres[j+1] += cr;
				}
			}
			memcpy(prob[i], temp, sizeof(temp));
			memcpy(res[i], tres, sizeof(tres));
			if (!rep) break;
		}
	}
	real sum = 0.0;
	real ans = 0.0;
	for (int j = 0; j<m; j++) {
		sum += prob[n-1][j];
		ans += res[n-1][j];
	}
	printf("%0.20lf\n", double(ans));
//	printf("%0.20lf\n", double(sum));

	return 0;
}