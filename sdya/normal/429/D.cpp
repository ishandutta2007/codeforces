#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

struct pt {
	long long x, y, id;
	pt(long long x, long long y, long long id) : x(x), y(y), id(id) {}
	pt() {}
};

inline bool cmp_x (const pt & a, const pt & b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

inline bool cmp_y (const pt & a, const pt & b) {
	return a.y < b.y;
}

const int maxN = 110000;
pt a[maxN];

long long mindist = 8000000000000000000LL;
int ansa, ansb;

inline void upd_ans (const pt & a, const pt & b) {
	long long dist = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
	if (dist < mindist)
		mindist = dist,  ansa = a.id,  ansb = b.id;
}

void rec (int l, int r) {
	if (r - l <= 3) {
		for (int i=l; i<=r; ++i)
			for (int j=i+1; j<=r; ++j)
				upd_ans (a[i], a[j]);
		sort (a+l, a+r+1, &cmp_y);
		return;
	}

	int m = (l + r) >> 1;
	long long midx = a[m].x;
	rec (l, m),  rec (m+1, r);
	static pt t[maxN];
	merge (a+l, a+m+1, a+m+1, a+r+1, t, &cmp_y);
	copy (t, t+r-l+1, a+l);

	int tsz = 0;
	for (int i=l; i<=r; ++i)
		if ((a[i].x - midx) * (a[i].x - midx) < mindist) {
			for (int j=tsz-1; j>=0 && (a[i].y - t[j].y) * (a[i].y - t[j].y) < mindist; --j)
				upd_ans (a[i], t[j]);
			t[tsz++] = a[i];
		}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector < int > x(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x[i]);
	}

	for (int i = 0; i < n; ++i) {
		a[i].x = i;
		a[i].y = x[i];
		a[i].id = i;
		if (i > 0) {
			a[i].y += a[i - 1].y;
		}
	}

	sort (a, a+n, &cmp_x);
	rec (0, n-1);
	cout << mindist << endl;

	return 0;
}