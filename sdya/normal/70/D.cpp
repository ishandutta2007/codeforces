#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
const double eps = 1e-16;

struct point {
	long long x, y;
	point() : x(0), y(0) {
	}
	point(long long x, long long y) : x(x), y(y) {
	}
	bool operator < (const point &other) const {
		return x * other.y < y * other.x;
	}
};

inline long long area(point a, point b, point c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
 
inline bool intersect_1(long long a, long long b, long long c, long long d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max(a,c) <= min(b,d);
}
 
bool intersect(point a, point b, point c, point d) {
	long long p = area(a,b,c), q = area(a,b,d);
	long long r = area(c,d,a), s = area(c,d,b);
	p = (p > 0 ? 1 : (p < 0 ? -1 : 0));
	q = (q > 0 ? 1 : (q < 0 ? -1 : 0));
	r = (r > 0 ? 1 : (r < 0 ? -1 : 0));
	s = (s > 0 ? 1 : (s < 0 ? -1 : 0));
	return intersect_1 (a.x, b.x, c.x, d.x)
		&& intersect_1 (a.y, b.y, c.y, d.y)
		&& p * q <= 0
		&& r * s <= 0;
}

point operator - (const point &A, const point &B) {
	return point(A.x - B.x, A.y - B.y);
}

int q, n;
set < int > S;
int x[maxN], y[maxN], t[maxN];
int id[maxN];
map < int, int > M;
int cx, cy;

long long len(long long x, long long y) {
	return x * x + y * y;
}

bool isIn(int index) {
	set < int > ::iterator it = S.lower_bound(id[index]);
	if (id[index] == *it) {
		int pos = M[*it];
		return len(x[index] - cx, y[index] - cy) <= len(x[pos] - cx, y[pos] - cy);
	}

	set < int > ::iterator jt = it;
	--jt;

	int u = M[*jt];
	int v = M[*it];
	if (intersect(point(x[u], y[u]), point(x[v], y[v]), point(x[index], y[index]), point(x[index], y[index]))) {
		return true;
	}
	return !intersect(point(x[u], y[u]), point(x[v], y[v]), point(x[index], y[index]), point(cx, cy));
}

void add(int index) {
	if (isIn(index)) {
		return;
	}
	S.insert(id[index]);
	S.insert(id[index] - n);
	S.insert(id[index] + n);
	S.insert(id[index] - 2 * n);
	S.insert(id[index] + 2 * n);
	M[id[index]] = index;
	M[id[index] - n] = index;
	M[id[index] + n] = index;
	M[id[index] - 2 * n] = index;
	M[id[index] + 2 * n] = index;
	set < int > ::iterator it = S.lower_bound(id[index]);
	vector < int > toBeDeleted;
	{
		set < int > ::iterator jt = it;
		++jt;
		set < int > ::iterator kt = jt;
		++kt;

		while (kt != S.end()) {
			int u = M[*jt];
			int v = M[*kt];
			point A(x[u] - x[index], y[u] - y[index]);
			point B(x[v] - x[u], y[v] - y[u]);
			if (A.x * B.y - A.y * B.x <= 0) {
				toBeDeleted.push_back(u);
				++jt;
				++kt;
			} else {
				break;
			}
		}
	}
	{
		set < int > ::iterator jt = it;
		--jt;
		set < int > ::iterator kt = jt;
		--kt;

		while (jt != S.begin()) {
			int u = M[*jt];
			int v = M[*kt];
			point A(x[u] - x[index], y[u] - y[index]);
			point B(x[v] - x[u], y[v] - y[u]);
			if (A.x * B.y - A.y * B.x >= 0) {
				toBeDeleted.push_back(u);
				--jt;
				--kt;
			} else {
				break;
			}
		}
	}
	for (int i = 0; i < toBeDeleted.size(); ++i) {
		int u = toBeDeleted[i];
		S.erase(id[u] - 2 * n);
		S.erase(id[u] - n);
		S.erase(id[u]);
		S.erase(id[u] + n);
		S.erase(id[u] + 2 * n);
	}
}

struct pt {
	long long x, y;
	pt() : x(0), y(0) {
	}
	pt(long long x, long long y) : x(x), y(y) {
	}
};

long long area(pt a, pt b, pt c) {
	long long res = a.x * b.y - a.y * b.x + b.x * c.y - b.y * c.x + c.x * a.y - c.y * a.x;
	return res > 0 ? res : -res;
}

long long area(vector <pt> &a) {
	long long res = 0;
	for (int i = 2; i < a.size(); ++i) {
		res += area(a[0], a[i - 1], a[i]);
	}
	return res;
}

long long area(vector <pt> &a, pt b) {
	long long res = 0;
	for (int i = 0; i < a.size(); ++i) {
		res += area(a[i], a[(i + 1) % a.size()], b);
	}
	return res;
}

bool cmp (pt a, pt b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<pt> & a) {
	if (a.size() == 1)  return;
	sort (a.begin(), a.end(), &cmp);
	pt p1 = a[0],  p2 = a.back();
	vector<pt> up, down;
	up.push_back (p1);
	down.push_back (p1);
	for (size_t i=1; i<a.size(); ++i) {
		if (i==a.size()-1 || cw (p1, a[i], p2)) {
			while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i==a.size()-1 || ccw (p1, a[i], p2)) {
			while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}
	a.clear();
	for (size_t i=0; i<up.size(); ++i)
		a.push_back (up[i]);
	for (size_t i=down.size()-2; i>0; --i)
		a.push_back (down[i]);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d%d%d", &t[i], &x[i], &y[i]);
		x[i] *= 3;
		y[i] *= 3;
	}
	/*srand(time(0));
	q = 1000;
	for (int i = 0; i < q; ++i) {
		if (i < 3) {
			t[i] = 1;
		} else {
			t[i] = 1 + (rand() % 2);
		}
		x[i] = (rand() % 1000) * (rand() % 1000);
		y[i] = (rand() % 1000) * (rand() % 1000);
		x[i] *= 3;
		y[i] *= 3;
	}

	vector <pt> hull;
	for (int i = 0; i < 3; ++i) {
		hull.push_back(pt(x[i], y[i]));
	}
	convex_hull(hull);*/
	
	cx = (x[1] + x[2] + x[0]) / 3;
	cy = (y[1] + y[2] + y[0]) / 3;

	vector < pair < long double, int > > values(q);
	for (int i = 0; i < q; ++i) {
		values[i] = make_pair(atan2((long double)(y[i] - cy), (long double)(x[i] - cx)), i);
	}
	sort(values.begin(), values.end());
	n = 0;
	for (int i = 0; i < q; ++i) {
		if (i == 0) {
			++n;
		}
		if (i > 0) {
			int u = values[i - 1].second;
			int v = values[i].second;
			if ((long long)(x[u] - cx) * (long long)(y[v] - cy) != (long long)(y[u] - cy) * (long long)(x[v] - cx)) {
				++n;
			}
		}
		id[values[i].second] = n;
	}

	for (int i = 0; i < 3; ++i) {
		S.insert(id[i] - 2 * n);
		S.insert(id[i] - n);
		S.insert(id[i]);
		S.insert(id[i] + n);
		S.insert(id[i] + 2 * n);
		M[id[i]] = i;
		M[id[i] - n] = i;
		M[id[i] + n] = i;
		M[id[i] - 2 * n] = i;
		M[id[i] + 2 * n] = i;
	}

	for (int i = 3; i < q; ++i) {
		if (t[i] == 1) {
			add(i);
			//hull.push_back(pt(x[i], y[i]));
			//convex_hull(hull);
		} else {
			if (isIn(i)) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}


	return 0;
}