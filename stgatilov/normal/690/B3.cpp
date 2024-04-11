#pragma comment(linker, "/STACK:20000000")
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

struct Point {
	int x, y;

	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}

	Point operator- (Point b) const {
		return Point(x - b.x, y - b.y);
	}
	Point operator+ (Point b) const {
		return Point(x + b.x, y + b.y);
	}
	bool operator< (Point b) const {
		return make_pair(x, y) < make_pair(b.x, b.y);
	}
};

int64 cross (Point a, Point b) {
	return int64(a.x) * b.y - int64(a.y) * b.x;
}
int64 dot (Point a, Point b) {
	return int64(a.x) * b.x + int64(a.y) * b.y;
}

void Process(map<int, set<int>> &cells, set<Point> &dots) {
	for (auto it = cells.begin(); it != cells.end(); it++) {
		int x = it->first;
		const auto &ySet = it->second;
		int last = *ySet.begin();
		for (auto jt = ySet.begin(); jt != ySet.end(); jt++) {
			int curr = *jt;
			if (curr - last > 1) {
				dots.insert(Point(x, last+1));
				dots.insert(Point(x, curr));
				dots.insert(Point(x+1, last+1));
				dots.insert(Point(x+1, curr));
			}
			if (curr - last == 1) {
				if (cells.find(x+1) != cells.end()) {
					const auto &nSet = cells[x+1];
					if (nSet.find(last) != nSet.end() && nSet.find(curr) != nSet.end())
						dots.insert(Point(x+1, curr));
				}
			}
			last = curr;
		}
	}
}


int n, m;


set<Point> vis;
void DFS(const set<Point> &cmap, Point p) {
	vis.insert(p);
	for (int dx = -1; dx <= 1; dx++)
		for (int dy = -1; dy <= 1; dy++)
			if (abs(dx) + abs(dy) == 1) {
				Point np(p.x + dx, p.y + dy);
				if (cmap.find(np) != cmap.end() && vis.find(np) == vis.end())
					DFS(cmap, np);
			}
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	while (1) {
		scanf("%d%d", &n, &m);
		if (n == 0) break;

		set<Point> src;
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			x--; y--;
			src.insert(Point(x, y));
		}

		set<Point> dots;
		while (!src.empty()) {
			Point p = *src.begin();
			DFS(src, p);

			map<int, set<int>> cells;
			for (auto it = vis.begin(); it != vis.end(); it++) {
				Point p = *it;
				src.erase(p);
				cells[p.x].insert(p.y);
			}
			vis.clear();

			Process(cells, dots);
		}

		vector<Point> pts(dots.begin(), dots.end());
		Ef("%d\n", pts.size());
		for (int i = 0; i < pts.size(); i++)
			Ef("%d %d\n", pts[i].x, pts[i].y);

		Point ctr = pts[0];
		std::sort(pts.begin() + 1, pts.end(), [&](Point a, Point b) -> bool {
			int64 area = cross(a - ctr, b - ctr);
			if (area != 0)
				return area < 0;
			return dot(a - ctr, a - ctr) < dot(b - ctr, b - ctr);
		});

		vector<Point> hull;
		hull.push_back(pts[0]);
		hull.push_back(pts[1]);
        for (int i = 2; i < pts.size(); i++) {
			Point p = pts[i];
			while (hull.size() >= 2 && cross(hull.rbegin()[0] - hull.rbegin()[1], p - hull.rbegin()[0]) >= 0)
				hull.pop_back();
			hull.push_back(p);
        }

        printf("%d\n", hull.size());
        for (int i = 0; i < hull.size(); i++)
        	printf("%d %d\n", hull[i].x, hull[i].y);

	}
	return 0;
}