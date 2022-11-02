#include <iostream>
using namespace std;

const int N = 100011;
typedef long long intl;

intl h[N], p[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i ++)
		cin >> h[i];
	for(int i = 0; i < m; i ++)
		cin >> p[i];

	intl ll = 0, rr = (intl)3e10;
	while(ll + 1 < rr)
	{
		intl mm = (ll + rr) / 2;
		int read = 0;
		for(int i = 0; i < n; i ++)
		{
			int left = read;
			int right = m + 1;
			while(left + 1 < right)
			{
				int mid = (left + right) / 2;
				intl tmin = p[read];
				intl tmax = p[mid - 1];
				intl tl = 0, tr = 0;
				if(tmin < h[i])
					tl = h[i] - tmin;
				if(tmax > h[i])
					tr = tmax - h[i];
				if(tl && tr)
				{
					if(2 * tl + tr <= mm - 1 || 2 * tr + tl <= mm - 1)
						left = mid;
					else
						right = mid;
				}
				else
				{
					if(tl + tr <= mm - 1)
						left = mid;
					else
						right = mid;
				}
			}
			read = left;
		}
		if(read == m)
			rr = mm;
		else
			ll = mm;
	}
	cout << ll << '\n';
	return 0;
}