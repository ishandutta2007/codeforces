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

ld a, b, c, d;

pair<ld, ld> bounds(ld a, ld b, ld c, ld d) {
	ld v1 = a * c, v2 = a * d, v3 = b * c, v4 = b * d;
	return make_pair(min(min(v1, v2), min(v3, v4)), max(max(v1, v2), max(v3, v4)));
}

bool check(ld m) {
	ld lq = m - a, rq = -m - a;
	ld lw = m - b, rw = -m - b;
	ld le = m - c, re = -m - c;
	ld lr = m - d, rr = -m - d;
	pair<ld, ld> pqr = bounds(lq, rq, lr, rr);
	pair<ld, ld> pew = bounds(le, re, lw, rw);

	return max(pqr.first, pew.first) <= min(pqr.second, pew.second);
}

int main() {
	cin >> a >> b >> c >> d;
	ld l = 0, r = 1e10;
	forn(it, 2000) {
		ld m = (l + r) / 2;
		if (check(m)) r = m;
		else l = m;
	}
	printf("%.10f\n", double((l + r) / 2));
	return 0;
}