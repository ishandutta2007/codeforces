//#pragma comment(linker, "/STACK:20000000")
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
};

int cross (Point a, Point b) {
	return a.x * b.y - a.y * b.x;
}
int dot (Point a, Point b) {
	return a.x * b.x + a.y * b.y;
}


const int SIZE = 5<<10;

int n;
char matr[SIZE][SIZE];


char buff[1<<20];
int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;

		for (int y = n-1; y >= 0; y--) {
			scanf("%s", buff);
			for (int x = 0; x < n; x++)
				matr[x][y] = buff[x] - '0';
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				int prev = 0;
				if (i) prev += matr[i-1][j];
				if (j) prev += matr[i][j-1];
				if (i && j) prev += matr[i-1][j-1];
				matr[i][j] -= prev;
			}

		for (int y = n-1; y >= 1; y--) {
			for (int x = 0; x <= n-1; x++)
				Ef("%d", int(matr[x][y]));
			Ef("\n");
		}
//				assert(matr[i][j] >= 0 && matr[i][j] <= 1);

		vector<Point> pts;
		for (int i = 0; i < n; i++) {
			int jMin = 1000000, jMax = -1000000;
			for (int j = 0; j < n; j++)
				if (matr[i][j]) {
					jMin = min(jMin, j);
					jMax = max(jMax, j);
				}

			if (jMax >= jMin) {
				pts.push_back(Point(i, jMin));
				if (jMax != jMin)
					pts.push_back(Point(i, jMax));
			}
		}

		Point ctr = pts[0];
		std::sort(pts.begin() + 1, pts.end(), [&](Point a, Point b) -> bool {
			int area = cross(a - ctr, b - ctr);
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
        	printf("%d %d\n", hull[i].x + 1, hull[i].y + 1);

	}
	return 0;
}