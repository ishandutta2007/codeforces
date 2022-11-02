#include <bits/stdc++.h>
using namespace std;

const int N = 1011;
typedef long long intl;

struct Point
{
	intl x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	Point operator +(Point p) {
		return {x + p.x, y + p.y};
	}
	Point operator /(intl m) {
		return {x / m, y / m};
	}
	Point operator *(intl m) {
		return {x * m, y * m};
	}
	intl cross(Point p) {
		return x * p.y - y * p.x;
	}
}p[N];
intl xmul(Point a, Point b, Point c) {
	return (b - a).cross(c - a);
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> p[i].x >> p[i].y;
	p[n] = p[0];

	deque <Point> deq;
	Point sub = p[1] - p[0];
	intl t = abs(__gcd(sub.x, sub.y));
	Point step = sub / t;
	for(int i = 0; i <= t; i ++)
		deq.push_back(p[0] + step * i);

	for(int i = 1; i < n; i ++)
	{
		while(deq.size() >= 1 &&
			xmul(p[i], p[i + 1], *deq.begin()) > 0)
			deq.pop_front();
		while(deq.size() >= 1 &&
			xmul(p[i], p[i + 1], *deq.rbegin()) > 0)
			deq.pop_back();
	}
	cout << deq.size() << '\n';
	return 0;
}