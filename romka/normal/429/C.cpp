#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int n, c[25];
bool memf[1 << 24];
bool u[1 << 24];
bool us[1 << 25], mems[1 << 25];
int bc[1 << 24];

bool splittable(int mask, bool can_all);

bool ok(int mask) {
	// printf("call ok %d\n", mask);
	bool& res = memf[mask];
	if (u[mask]) return res;
	u[mask] = true;
	int bc = 0, mx = 0, mj = 0;
	forn(i, n) {
		if ((1 << i) & mask) {
			bc++;
			if (c[i] > mx) { mx = c[i]; mj = i; }
		}
	}
	if (mx != bc) return res = false;
	mask ^= 1 << mj;

	if (mask == 0) res = true;
	else res = splittable(mask, false);

	// printf("ok %d -> %d\n", mask, res);

	return res;
}

bool rec(int mask, int i, int m, bool can_all, int p, int taken, int mx) {
	// printf("rec %d %d %d %d %d\n", mask, i, m, can_all, p);
	if (taken + bc[mask & ((1 << (i + 1)) - 1)] < mx) return false;
	if (i == -1) {
		if ((m != mask || can_all) && m != 0) {
			// bool res1 = ok(m);
			// bool res2 = splittable(mask ^ m, true);
			bool res = ok(m) && splittable(mask ^ m, true);
			// printf("rec %d %d %d %d %d is %d (%d && %d)\n", mask, i, m, can_all, p, res, res1, res2);
			return res;
		}
		return false;
	} else
		if (mask & (1 << i)) {
			if (rec(mask, i - 1, m, can_all, c[i], taken, mx)) return true;
			if (c[i] != p)
				if (rec(mask, i - 1, m ^ (1 << i), can_all, p, taken + 1, c[i])) return true;
		} else return rec(mask, i - 1, m, can_all, p, taken, mx);

	return false;
}

bool splittable(int mask, bool can_all) {
	// printf("call splittable %d (%d)\n", mask, can_all);
	if (mask == 0) return true;
	bool& res = mems[mask * 2 + can_all];
	if (us[mask * 2 + can_all]) return res;
	us[mask * 2 + can_all] = true;
	res = rec(mask, n - 1, 0, can_all, -1, 0, 0);

	// printf("splittable %d (%d) -> %d\n", mask, can_all, res);
	return res; // = false;
}

int main() {
	bc[0] = 0;
	bc[1] = 1;
	for (int i = 2; i < (1 << 24); i++)
		bc[i] = bc[i & (i - 1)] + 1;
	scanf("%d", &n);
	forn(i, n) scanf("%d", &c[i]);
	sort(c, c + n);
	reverse(c, c + n);
	if (ok((1 << n) - 1)) printf("YES\n");
	else printf("NO\n");
	return 0;
}