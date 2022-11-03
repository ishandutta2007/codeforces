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

struct Point {
	int x, y;
	inline Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

	Point operator+ (Point b) const { return Point(x+b.x, y+b.y); }
	Point operator- (Point b) const { return Point(x-b.x, y-b.y); }
	Point operator* (int b) const { return Point(x*b, y*b); }
};

int64 vect(Point a, Point b) {
	return int64(a.x) * b.y - int64(a.y)*b.x;
}

bool LessLex(Point a, Point b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

bool operator!= (Point a, Point b) {
	return a.x != b.x || a.y != b.y;
}

const int K = 3;
const int SIZE = 200<<10;

int n[K];
Point pts[K][SIZE];

int m;
Point qry[SIZE];

int ind[K];
int r;
Point res[SIZE];

typedef multimap<int, int>::iterator mIter;
multimap<int, int> qmap;
bool gup[SIZE], glow[SIZE];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	for (int i = 0; i<K; i++) {
		scanf("%d", &n[i]);
		for (int j = 0; j<n[i]; j++)
			scanf("%d%d", &pts[i][j].x, &pts[i][j].y);
		pts[i][n[i]] = pts[i][0];
	}
	scanf("%d", &m);
	for (int i = 0; i<m; i++) scanf("%d%d", &qry[i].x, &qry[i].y);

	Point start;
	for (int i = 0; i<K; i++) {
		int best = 0;
		for (int j = 0; j<n[i]; j++)
			if (LessLex(pts[i][j], pts[i][best]))
				best = j;
		ind[i] = best;
		start = start + pts[i][best];
	}

	Point curr = start;
	do {
		res[r++] = curr;	

		int chg = -1;
		Point was;
		for (int i = 0; i<K; i++) {
			Point will = pts[i][ind[i]+1] - pts[i][ind[i]];
			if (chg < 0 || vect(was, will) < 0) {
				chg = i;
				was = will;
			}
		}

		curr = curr + was;
		ind[chg]++;
		if (ind[chg] == n[chg])
			ind[chg] = 0;

	} while (curr != start);
    res[r] = res[0];

	for (int i = 0; i<m; i++) qmap.insert(make_pair(K*qry[i].x, i));

	int t = 0;
	do {
		Point left = res[t];
		Point right = res[t+1];

		if (left.x != right.x) {
			bool rev = (right.x < left.x);
			if (rev) swap(left, right);

			mIter lit = qmap.lower_bound(left.x);
			mIter rit = qmap.upper_bound(right.x);
			for (mIter it = lit; it != rit; it++) {
				Point p = qry[it->second] * K;
				int64 dx1 = int64(p.x) - int64(left.x);
				int64 dx2 = int64(right.x) - int64(left.x);
				int64 dy1 = int64(p.y) - int64(left.y);
				int64 dy2 = int64(right.y) - int64(left.y);
//				int64 pv = vect(p - left, right - left);
				int64 pv = dx1*dy2 - dy1*dx2;

				if (!rev && pv <= 0) glow[it->second] = true;
				if ( rev && pv >= 0)  gup[it->second] = true;
			}
		}

		t++;
		if (t == r) t = 0;
	} while (t != 0);

	for (int i = 0; i<m; i++) {
		if (glow[i] && gup[i]) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}