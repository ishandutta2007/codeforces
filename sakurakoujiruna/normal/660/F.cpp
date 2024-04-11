#include <iostream>
using namespace std;

const int N = 200011;
typedef long long intl;

struct Point
{
	intl x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	intl cross(Point p) {
		return x * p.y - y * p.x;
	}
	intl y_inter(intl k) {
		return -k * x + y;
	}
};

intl xmul(Point a, Point b, Point c)
{
	return (b - a).cross(c - a);
}

intl a[N];
Point p[N];

intl bin(int n, intl k)
{
	int left = 0, right = n;
	while(left + 1 < right)
	{
		int mid = (left + right) / 2;
		if(p[mid].y_inter(k) > p[mid - 1].y_inter(k))
			left = mid;
		else
			right = mid;
	}
	return p[left].y_inter(k);
}

intl solve(int l, int r)
{
	if(l + 1 == r)
		return max(a[l], 0LL);
	int mid = (l + r) / 2;
	intl ret = max(solve(l, mid), solve(mid, r));

	int top = 0;
	p[top ++] = {0, 0};
	intl tri_sum = 0;
	intl seg_sum = 0;
	for(int i = mid - 1; i >= l; i --)
	{
		seg_sum += a[i];
		tri_sum += seg_sum;
		Point now = {mid - i, tri_sum};
		while(top > 1 && xmul(p[top - 2], p[top - 1], now) >= 0)
			top --;
		p[top ++] = now;
	}

	tri_sum = 0;
	seg_sum = 0;
	for(int i = mid; i < r; i ++)
	{
		seg_sum += a[i];
		tri_sum += (i - mid + 1) * a[i];
		ret = max(ret, bin(top, -seg_sum) + tri_sum);
	}
	return ret;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	cout << solve(0, n) << '\n';
	return 0;
}