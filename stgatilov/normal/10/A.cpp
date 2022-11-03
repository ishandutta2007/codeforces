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

int n;
int r1, r2, r3, t1, t2;
int ans;

int calc(int t) {
	int res = 0;

	int q = min(t, t1);
	t -= q;
	res += q * r1;

	q = min(t, t2);
	t -= q;
	res += q * r2;

	q = t;
	t -= q;
	res += q * r3;

	return res;
}

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d%d%d%d%d%d", &n, &r1, &r2, &r3, &t1, &t2);
	int last = -1;
	for (int i = 0; i<n; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (last >= 0) ans += calc(l - last);
		ans += r1 * (r - l);
		last = r;
	}

	printf("%d\n", ans);

	return 0;
}