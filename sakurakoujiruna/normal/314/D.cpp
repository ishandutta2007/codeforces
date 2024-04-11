#include <bits/stdc++.h>
using namespace std;

const int N = 100011;
typedef long long intl;

struct Point
{
	intl x, y;
	bool operator <(Point p) const {
		return tie(x, y) < tie(p.x, p.y);
	}
}p[N];

intl pre_min[N], pre_max[N];
intl suf_min[N], suf_max[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> p[i].x >> p[i].y;
		intl a = p[i].x - p[i].y;
		intl b = p[i].x + p[i].y;
		p[i].x = a;
		p[i].y = b;
	}
	sort(p + 1, p + n + 1);
	pre_min[0] = 1e12;
	pre_max[0] = -1e12;
	for(int i = 1; i <= n; i ++)
	{
		pre_min[i] = min(pre_min[i - 1], p[i].y);
		pre_max[i] = max(pre_max[i - 1], p[i].y);
	}
	suf_min[n + 1] = 1e12;
	suf_max[n + 1] = -1e12;
	for(int i = n; i >= 1; i --)
	{
		suf_min[i] = min(suf_min[i + 1], p[i].y);
		suf_max[i] = max(suf_max[i + 1], p[i].y);
	}

	double left = 0, right = 2e9;
	for(int _ = 0; _ < 60; _ ++)
	{
		double mid = (left + right) / 2;
		bool flag = false;
		int l = 1;
		for(int i = 1; i <= n; i ++)
		{
			while(l < i && p[l].x + 2 * mid < p[i].x)
				l ++;
			intl tmin = min(pre_min[l - 1], suf_min[i + 1]);
			intl tmax = max(pre_max[l - 1], suf_max[i + 1]);
			if(tmin + 2 * mid > tmax)
				flag = true;
		}
		if(flag)
			right = mid;
		else
			left = mid;
	}
	cout << setprecision(8) << left << '\n';
	return 0;
}