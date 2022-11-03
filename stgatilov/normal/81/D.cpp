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

int n, m;
int cnt[64];
int res[1024];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &m);
	for (int i = 0; i<m; i++) scanf("%d", cnt+i);

	int best = 0;
	for (int i = 0; i<m; i++) if (cnt[i] > cnt[best]) best = i;

	memset(res, -1, sizeof(res));

	int take = min(cnt[best], n/2);
	int tmp = 0;
	for (int i = 0; i<take; i++) {
		res[tmp/take] = best;
		tmp += n;
	}
/*	for (int i = 0; i<n; i++) printf("%d ", res[i]);
	printf("\n");*/

	for (int i = 0; i<n; i++) if (res[i] < 0) {
		int mx = -1;
		int mxi = -1;
		for (int c = 0; c<m; c++) if (c != best && !(i && c == res[i-1])) {
			if (mx < cnt[c]) {
				mx = cnt[c];
				mxi = c;
			}
		}
		if (mxi == -1 || mx <= 0) break;

		cnt[mxi]--;
		res[i] = mxi;
	}

	bool check = true;
	for (int i = 0; i<n; i++) {
		if (res[i] < 0) check = false;
		if (res[i] == res[(i+1)%n]) check = false;
	}

	if (!check) {
		printf("-1\n");
	}
	else {
		for (int i = 0; i<n; i++) printf("%d ", res[i]+1);
	}

	return 0;
}