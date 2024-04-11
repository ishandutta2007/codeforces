#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100011;
typedef long long intl;
const intl Inf = 0x3f3f3f3f3f3f3f3fLL;

struct Point
{
	intl x, y;
	Point() { }
	bool operator <(const Point &rhs) const
	{
		return x < rhs.x;
	}
};

Point p[2][N];
intl pre_min[2][N];
intl pre_max[2][N];
intl suf_min[2][N];
intl suf_max[2][N];

bool check(int n, intl limit)
{
	if((p[0][1].x - p[0][n].x) * (p[0][1].x - p[0][n].x) <= limit)
		return true;
	if((pre_min[0][n] - pre_max[0][n]) * (pre_min[0][n] - pre_max[0][n]) <= limit)
		return true;
	for(int k = 0; k < 2; k ++)
	{
		int r = 1;
		for(int i = 1; i <= n; i ++)
		{
			while(r < n && abs(p[k][r + 1].x) <= abs(p[k][i].x) &&
				(p[k][r + 1].x - p[k][i].x) * (p[k][r + 1].x - p[k][i].x) <= limit)
				r ++;
			while(r > i && abs(p[k][r].x) > abs(p[k][i].x))
				r --;

			intl xx = max(p[k][i].x * p[k][i].x, p[k][r].x * p[k][r].x);
			intl c[2] = {min(pre_min[k][i - 1], suf_min[k][r + 1]),
						 max(pre_max[k][i - 1], suf_max[k][r + 1])};

			bool flag = true;
			if((c[0] - c[1]) * (c[0] - c[1]) > limit)
				flag = false;
			for(int t = 0; t < 2; t ++)
			{
				c[t] *= c[t];
				if(c[t] + xx > limit)
					flag = false;
			}
			if(flag)
				return true;
		}
	}
	return false;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> p[0][i].x >> p[0][i].y;
		p[1][i] = p[0][i];
	}
	sort(p[0] + 1, p[0] + n + 1);
	sort(p[1] + 1, p[1] + n + 1);
	reverse(p[1] + 1, p[1] + n + 1);

	for(int k = 0; k < 2; k ++)
	{
		pre_min[k][0] = Inf;
		pre_max[k][0] = -Inf;
		for(int i = 1; i <= n; i ++)
		{
			pre_min[k][i] = min(pre_min[k][i - 1], p[k][i].y);
			pre_max[k][i] = max(pre_max[k][i - 1], p[k][i].y);
		}
		//pre_min[k][0] = pre_max[k][0] = 0;

		suf_min[k][n + 1] = Inf;
		suf_max[k][n + 1] = -Inf;
		for(int i = n; i >= 1; i --)
		{
			suf_min[k][i] = min(suf_min[k][i + 1], p[k][i].y);
			suf_max[k][i] = max(suf_max[k][i + 1], p[k][i].y);
		}
		//suf_min[k][n + 1] = suf_max[k][n + 1] = 0;
	}

	intl left = 0;
	intl right = Inf;
	while(left + 1 < right)
	{
		intl mid = (left + right) >> 1;
		if(check(n, mid - 1))
			right = mid;
		else
			left = mid;
	}
	cout << left << '\n';
	return 0;
}