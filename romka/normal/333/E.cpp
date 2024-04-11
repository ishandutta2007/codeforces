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

const ld eps = 1e-9;
const ld PI = acos(-1.0);
const ld da = PI / 6;

struct Point {
	ld x, y, angle, dist;
};

bool operator<(const Point& lhs, const Point& rhs) {
	return lhs.angle < rhs.angle;
}

ld ans;
int n;
Point p[3010], pp[3010];
int k;
ld tree[20010];
int N;

#define sqr(x) (x)*(x)

int findL(ld x) {
	int l = 0, r = k - 1;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		if (pp[m].angle > x - eps) r = m;
		else l = m;
	}

	if (pp[l].angle > x - eps) return l;
	else if (pp[r].angle > x - eps) return r;

	return -1;
}

int findR(ld x) {
	int l = 0, r = k - 1;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		if (pp[m].angle < x + eps) l = m;
		else r = m;
	}
	if (pp[r].angle < x + eps) return r;
	else if (pp[l].angle < x + eps) return l;

	return -1;
}

ld getmax(int i, int L, int R, int qL, int qR) {
	if (L == qL && R == qR) {
		return tree[i];
	} else {
		int M = (L + R) >> 1;
		ld res = 0;
		if (qL <= M) res = max(res, getmax(i * 2, L, M, qL, min(M, qR)));
		if (qR > M) res = max(res, getmax(i * 2 + 1, M + 1, R, max(M+1, qL), qR));
		return res;
	}
}

void check(ld qL, ld qR, ld dist) {
	// printf("check %.5f %.5f\n", qL, qR);
	int iL = findL(qL);
	int iR = findR(qR);
	if (iL == -1 || iR == -1 || iL > iR) return;
	// printf(">> %d %d\n", iL, iR);
	if (getmax(1, 0, N-1, iL, iR) > dist - eps) {
		ans = dist;
		// printf("ok, ans is %.5f\n", dist);
	}
}

void process() {
	N = 1;
	while (N < k) N <<= 1;
	forn(i, N) tree[N+i] = pp[i].dist;
	for (int i = N-1; i >= 1; i--)
		tree[i] = max(tree[i*2], tree[i*2+1]);
}

void naive() {
	ld ans = 0;
	forn(i, n)
		forn(j, i)
			forn(k, j) {
				ld a = sqrt(sqr(p[j].x - p[i].x) + sqr(p[j].y - p[i].y));
				ld b = sqrt(sqr(p[j].x - p[k].x) + sqr(p[j].y - p[k].y));
				ld c = sqrt(sqr(p[k].x - p[i].x) + sqr(p[k].y - p[i].y));
				ld z = min(min(a, b), c);
				if (z > ans) ans = z;
			}

	ans *= 0.5;
	printf("%.8f - naive\n", double(ans));
}

int main() {
	scanf("%d", &n);
	forn(i, n) cin >> p[i].x >> p[i].y;

	forn(i, n) {
		k = 0;
		forn(j, n) if (j != i) {
			pp[k] = p[j];
			pp[k].angle = atan2(p[j].y - p[i].y, p[j].x - p[i].x);
			if (pp[k].angle < 0) pp[k].angle += 2 * PI;
			pp[k].dist = sqrt(sqr(p[j].x - p[i].x) + sqr(p[j].y - p[i].y));
			k++;
		}

		sort(pp, pp+k);

		process();

		// printf(">>> sorted:");
		// forn(j, k) printf(" %.5f", pp[j].angle);
		// printf("\n");

		forn(j, k) {
			if (pp[j].dist < ans) continue;

			// printf("now checking (%.5f %.5f) -> (%.5f %.5f)\n", p[i].x, p[i].y, pp[j].x, pp[j].y);

			ld left = pp[j].angle - da - da + eps;
			ld right = pp[j].angle + da + da - eps;
			// printf("angles: %.5f, left %.5f, right %.5f\n", pp[j].angle, left, right);
			if (left > 0) {
				ld qR = left;
				ld qL = 0;
				if (right > 2 * PI) qL = right - 2 * PI;
				check(qL, qR, pp[j].dist);
			}
			if (right < 2 * PI) {
				ld qL = right;
				ld qR = 2 * PI;
				if (left < 0) qR = 2 * PI + left;
				check(qL, qR, pp[j].dist);
			}
		}
	}

	ans *= 0.5;
	printf("%.8f\n", double(ans));
	// naive();

	return 0;
}