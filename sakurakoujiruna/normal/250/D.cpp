#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 100011;
typedef long long intl;

struct Point
{
	intl x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	double length() {
		return sqrt(x * x + y * y);
	}
	intl cross(Point p) {
		return x * p.y - y * p.x;
	}
};

struct Event
{
	int y, l;
	bool operator <(Event rhs) const {
		return y < rhs.y;
	}
}r[N];
int l[N];

int a, b;
double solve(int ll, int rr)
{
	double ol = Point{a, l[ll]}.length();
	double lr = (Point{a, l[ll]} - Point{b, r[rr].y}).length();
	return ol + lr + r[rr].l;
}

void update(int l, int r, int &al, int &ar)
{
	if(solve(l, r) < solve(al, ar))
	{
		al = l;
		ar = r;
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m >> a >> b;
	for(int i = 0; i < n; i ++)
		cin >> l[i];
	for(int i = 0; i < m; i ++)
		cin >> r[i].y;
	for(int i = 0; i < m; i ++)
		cin >> r[i].l;
	sort(l, l + n);
	sort(r, r + m);

	int al = 0, ar = 0;
	int p = 0;
	for(int i = 0; i < m; i ++)
	{
		while(p < n - 1 && Point{a, l[p + 1]}.cross({b, r[i].y}) >= 0)
			p ++;
		update(p, i, al, ar);
		if(p != n - 1)
			update(p + 1, i, al, ar);
	}
	cout << al + 1 << ' ' << ar + 1 << '\n';
	return 0;
}