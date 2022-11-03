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

const int SIZE = 20<<10;

int n, m, p;
int xarr[SIZE], yarr[SIZE];

int func(int a, int b) {
	return (xarr[a] + yarr[b]) % p;
}

void Clear(int *arr, int l, int r) {
	memset(arr+l, -63, (r-l+1) * sizeof(arr[0]));
}

int ans[SIZE];

int res[2][SIZE];
int mid[2][SIZE];
void Solve(int sa, int sb, int fa, int fb) {
//	fprintf(stderr, "Solve (%d;%d) - (%d;%d)\n", sa, sb, fa, fb);
	int middle = (sa + fa) / 2;

	Clear(res[sa&1], sb, fb);
	res[sa&1][sb] = 0;
	for (int i = sa; i<=fa; i++) {
		for (int j = sb+1; j<=fb; j++) {
			int nres = res[i&1][j-1] + func(i, j);
			if (res[i&1][j] < nres) {
				res[i&1][j] = nres;
				mid[i&1][j] = mid[i&1][j-1];
			}
		}
		if (i == fa) break;

		Clear(res[(i+1)&1], sb, fb);
		for (int j = sb; j<=fb; j++) {
			int nres = res[i&1][j] + func(i+1, j);
			if (res[(i+1)&1][j] < nres) {
				res[(i+1)&1][j] = nres;
				mid[(i+1)&1][j] = (i == middle ? j : mid[i&1][j]);
			}
		}
	}

	int mida = middle;
	int midb = mid[fa&1][fb];
//	fprintf(stderr, "Middle point (%d;%d) -> %I64d\n", mida, midb, res[fa&1][fb]);

	if (fa == sa + 1) {
		ans[mida] = midb;
	}
	else {
		Solve(sa, sb, mida, midb);
		Solve(mida, midb, fa, fb);
	}
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d%d", &n, &m, &p);
	n--;  m--;
	for (int i = 0; i<=n; i++) scanf("%d", &xarr[i]);
	for (int i = 0; i<=m; i++) scanf("%d", &yarr[i]);

	memset(ans, -1, sizeof(ans));
	if (n > 0)
		Solve(0, 0, n, m);
	ans[n] = m;

	string path;
	int val = func(0, 0);
	int y = 0;
	for (int i = 0; i<=n; i++) {
		while (y < ans[i]) {
			y++;
			path += 'S';
			val += func(i, y);
		}
		if (i == n) break;
		path += 'C';
		val += func(i+1, y);
	}

	printf("%d\n", val);
	printf("%s\n", path.c_str());
	return 0;
}