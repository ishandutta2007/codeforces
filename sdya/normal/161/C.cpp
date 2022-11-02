#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

map < pair < pair < int, int >, pair < int, int > >, int > M;
#define mp(a, b, c, d) make_pair(make_pair(a, b), make_pair(c, d))

int solve(int l1, int r1, int l2, int r2, int k = 30) {
	if (l1 > r1 || l2 > r2 || k < 0) return 0;
	if (l1 == l2 && r1 == r2) return r1 - l1 + 1;
	if (l1 <= l2 && r2 <= r1) return r2 - l2 + 1;
	if (l2 <= l1 && r1 <= r2) return r1 - l1 + 1;
	if (M.count(mp(l1, r1, l2, r2)) != 0) return M[mp(l1, r1, l2, r2)];
	if (M.count(mp(l2, r2, l1, r1)) != 0) return M[mp(l2, r2, l1, r1)];

	int f1 = false, f2 = false;
	if (l1 <= (1 << k) && r1 >= (1 << k)) f1 = true;
	if (l2 <= (1 << k) && r2 >= (1 << k)) f2 = true;

	if (!f1 && !f2) {
		int nl1 = l1, nr1 = r1, nl2 = l2, nr2 = r2;
		if (nl1 > (1 << k)) nl1 -= (1 << k), nr1 -= (1 << k);
		if (nl2 > (1 << k)) nl2 -= (1 << k), nr2 -= (1 << k);
		int res = solve(nl1, nr1, nl2, nr2, k - 1);
		return M[mp(l1, r1, l2, r2)] = res;
	}

	if (!f1 && f2) {
		int nl1 = l1, nr1 = r1;
		if (nl1 > (1 << k)) nl1 -= (1 << k), nr1 -= (1 << k);
		int res = max(
			solve(nl1, nr1, l2, (1 << k) - 1, k - 1),
			solve(nl1, nr1, 1, r2 - (1 << k), k - 1));
		return M[mp(l1, r1, l2, r2)] = res;
	}
	if (f1 && !f2) {
		int nl2 = l2, nr2 = r2;
		if (nl2 > (1 << k)) nl2 -= (1 << k), nr2 -= (1 << k);
		int res = max(
			solve(nl2, nr2, l1, (1 << k) - 1, k - 1),
			solve(nl2, nr2, 1, r1 - (1 << k), k - 1));
		return M[mp(l1, r1, l2, r2)] = res;
	}

	if (f1 && f2) {
		int A11 = (1 << k) - max(l1, l2);
		int A12 = solve(l1, (1 << k) - 1, 1, r2 - (1 << k), k - 1);
		int A21 = solve(1, r1 - (1 << k), l2, (1 << k) - 1, k - 1);
		int A22 = min(r1, r2) - (1 << k);
		int res = max(max(A12, A21), A11 + A22 + 1);
		return M[mp(l1, r1, l2, r2)] = res;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int l1, r1, l2, r2;
	scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
	printf("%d\n", solve(l1, r1, l2, r2));

	return 0;
}