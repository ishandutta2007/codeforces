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

int Solve(int lvl, int l1, int r1, int l2, int r2) {
	if (r1 == l1 || r2 == l2) return 0;

	int len = (1<<(lvl+1)) - 1;
	if (l1 == 0 && r1 == len) return r2 - l2;
	if (l2 == 0 && r2 == len) return r1 - l1;

	if (lvl == 0) assert(0);

	int mid = (1<<lvl) - 1;
	bool hasmid1 = (mid >= l1 && mid < r1);
	bool hasmid2 = (mid >= l2 && mid < r2);
	#define RED(x) ((x) > mid ? (x) - (mid+1) : (x))

	if (!hasmid1 && !hasmid2)
		return Solve(lvl-1, RED(l1), RED(r1), RED(l2), RED(r2));

	if (!hasmid1)
		return Solve(lvl, l2, r2, l1, r1);

	if (!hasmid2) {
		int left = Solve(lvl-1, l1, mid, RED(l2), RED(r2));
		int right = Solve(lvl-1, 0, RED(r1), RED(l2), RED(r2));
		return max(left, right);
	}

	int middle = min(r1, r2) - max(l1, l2);
	int left1 = Solve(lvl-1, l1, mid, 0, RED(r2));
	int right1 = Solve(lvl-1, 0, RED(r1), l2, mid);
	return max(middle, max(left1, right1));
}

const int LEVELS = 30;

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	int l1, r1, l2, r2;
	scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
	l1--;  l2--;
	int ans = Solve(LEVELS - 1, l1, r1, l2, r2);
	printf("%d\n", ans);
	return 0;
}