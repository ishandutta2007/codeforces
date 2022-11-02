#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define double long double
const double Eps = 1e-9;
int sgn(double a, double b = 0)
{
	a -= b;
	return (a > Eps) - (a < -Eps);
}

const int N = 101;
int v[N], a[N], b[N];
char c[N];
bool vis[N];
int solve(int n, double ty, char dir, double k)
{
	//cout << dir << ' ' << k << '\n';
	int ret = 0;
	fill(vis, vis + n, false);
	double tx = 0;
	while(true)
	{
		if(dir == 'F')
		{
			tx += ty * k;
			ty = 0;
		}
		else
		{
			tx += (100 - ty) * k;
			ty = 100;
		}
		if(sgn(tx, 1e5) >= 0)
			break;
		bool flag = false;
		for(int i = 0; i < n; i ++)
			if(c[i] == dir && !vis[i] && sgn(a[i], tx) <= 0 && sgn(tx, b[i]) <= 0)
			{
				vis[i] = true;
				flag = true;
				ret += v[i];
			}
		if(!flag)
			return 0;
		dir = (dir == 'F' ? 'T' : 'F');
	}
	return ret;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	int hl, hr;
	cin >> hl >> hr;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> v[i] >> c[i] >> a[i] >> b[i];

	int ans = 0;
	for(int i = 0; i <= 50; i ++)
	{
		ans = max(ans, solve(n, hl, 'F', 1e5 / (hl + hr + i * 200)));
		ans = max(ans, solve(n, hl, 'T', 1e5 / (200 - hl - hr + i * 200)));

		ans = max(ans, solve(n, hl, 'F', 1e5 / (200 + hl - hr + i * 200)));
		ans = max(ans, solve(n, hl, 'T', 1e5 / (200 + hr - hl + i * 200)));
	}
	cout << ans << '\n';
	return 0;
}