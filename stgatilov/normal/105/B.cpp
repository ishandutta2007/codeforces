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

double ans;

int n, m, myhp;
int lyl[16], hp[16];
double win[256];

void Solve(int i, int r) {
	if (i == n) {
		double tres = 0.0;
		for (int u = 0; u<1<<n; u++) {
			double prob = 1.0;
			for (int v = 0; v<n; v++) {
				if (u & (1<<v))
					prob *= lyl[v] / 100.0;
				else
					prob *= (100-lyl[v]) / 100.0;
			}
			tres += prob * win[u];
		}
		if (ans < tres)
			ans = tres;
		return;
	}
	for (int t = 0; t<=r; t++) {
		if (lyl[i] + t*10 > 100) break;
		lyl[i] += t*10;
		Solve(i+1, r-t);
		lyl[i] -= t*10;
	}
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d%d", &n, &m, &myhp);
	for (int i = 0; i<n; i++)
		scanf("%d%d", hp+i, lyl+i);

	for (int i = 0; i<1<<n; i++) {
		int cntbad = 0;
		int sumbad = 0;
		for (int j = 0; j<n; j++) if (!(i & (1<<j))) {
			cntbad++;
			sumbad += hp[j];
		}
		double pwin = myhp / double(myhp + sumbad);
		if (cntbad * 2 < n)
			pwin = 1.0;
		win[i] = pwin;
	}

	ans = 0.0;
	Solve(0, m);

	printf("%0.12lf\n", ans);
	return 0;
}