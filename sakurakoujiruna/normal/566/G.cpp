#include <bits/stdc++.h>
using namespace std;

const int N = 100011;
typedef long long intl;

struct Point
{
	intl x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	bool operator <(Point p) const {
		return tie(x, y) < tie(p.x, p.y);
	}
	intl cross(Point p) {
		return x * p.y - y * p.x;
	}
};
intl xmul(Point a, Point b, Point c) {
	return (b - a).cross(c - a);
}

Point p[N], q[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	cin >> p[0].x >> p[0].y;
	for(int i = 0; i < n; i ++)
		cin >> p[i].x >> p[i].y;
	for(int i = 0; i < m; i ++)
		cin >> q[i].x >> q[i].y;

	sort(p, p + n);
	sort(q, q + m);
	reverse(p, p + n);
	reverse(q, q + m);
	
	vector <Point> conv;
	for(int i = 0; i < m; i ++)
	{
		while(conv.size() >= 2 &&
			xmul(*++conv.rbegin(), *conv.rbegin(), q[i]) <= 0)
			conv.pop_back();
		conv.push_back(q[i]);
	}
	while(conv.size() >= 2 &&
		conv.rbegin() -> y <= (++conv.rbegin()) -> y)
		conv.pop_back();
	conv.push_back({0, conv.rbegin() -> y});

	bool flag = (p[0].x >= conv[0].x);
	int cp = 0;
	for(int i = 0; i < n; i ++)
	{
		while(p[i].x < conv[cp + 1].x)
			cp ++;
		if(xmul(p[i], conv[cp], conv[cp + 1]) <= 0)
			flag = true;
	}

	cout << (flag ? "Max" : "Min") << '\n';
	
	return 0;
}