#include <bits/stdc++.h>
using namespace std;

const int N = 100011;
typedef long long intl;

struct Point
{
	intl x, y;
	int id;
	Point operator -(Point p) {
		return {x - p.x, y - p.y, -1};
	}
	bool operator <(Point p) const {
		return tie(x, y, id) < tie(p.x, p.y, p.id);
	}
	intl cross(Point p) {
		return x * p.y - y * p.x;
	}
	intl y_inter(intl k) {
		return -k * x + y;
	}
}p[N];
intl xmul(Point a, Point b, Point c)
{
	return (b - a).cross(c - a);
}

vector <Point> convex(int l, int r)
{
	static Point q[N];
	vector <Point> ret;
	int n = r - l;
	copy(p + l, p + r, q);
	sort(q, q + n);
	for(int i = 0; i < n; i ++)
		if(i == n - 1 || q[i].x < q[i + 1].x)
		{
			while(ret.size() >= 2 &&
				xmul(*++ret.rbegin(), *ret.rbegin(), q[i]) >= 0)
				ret.pop_back();
			ret.push_back(q[i]);
		}
	return ret;
}

struct SegTree
{
	int l[N << 2], r[N << 2];
	vector <Point> cv[N << 2];
	void init(int left, int right, int x = 1)
	{
		l[x] = left;
		r[x] = right;
		cv[x] = convex(left, right);
		/*
		cout << "------\n";
		cout << x << ' ' << left << ' ' << right << '\n';
		for(auto &p : cv[x])
			cout << p.x << ' ' << p.y << ' ' << p.id << '\n';
			*/
		if(left + 1 != right)
		{
			int mid = (left + right) / 2;
			init(left, mid, 2 * x);
			init(mid, right, 2 * x + 1);
		}
	}
	Point query(intl k, vector <Point> &cv)
	{
		int n = cv.size();
		int left = 0, right = n;
		while(left + 1 < right)
		{
			int mid = (left + right) / 2;
			if(cv[mid - 1].y_inter(k) > cv[mid].y_inter(k))
				right = mid;
			else
				left = mid;
		}
		return cv[left];
	}
	Point query(int left, int right, intl k, int x = 1)
	{
		if(l[x] == left && r[x] == right)
			return query(k, cv[x]);
		int mid = (l[x] + r[x]) / 2;
		if(right <= mid)
			return query(left, right, k, 2 * x);
		else if(left >= mid)
			return query(left, right, k, 2 * x + 1);
		else
		{
			Point p1 = query(left, mid, k, 2 * x);
			Point p2 = query(mid, right, k, 2 * x + 1);
			return (p1.y_inter(k) > p2.y_inter(k)) ? p1 : p2;
		}
	}
}st;

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> p[i].y >> p[i].x;
		p[i].id = i;
	}
	st.init(1, n + 1);
	
	while(m --)
	{
		int l, r, k;
		cin >> l >> r >> k;
		cout << st.query(l, r + 1, -k).id << '\n';
	}
	
	return 0;
}