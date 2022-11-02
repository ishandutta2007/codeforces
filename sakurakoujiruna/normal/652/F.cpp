#include <iostream>
#include <algorithm>
using namespace std;

const int N = 300011;
typedef long long intl;

int s[N], d[N];
int e[N];
pair <int, int> p[N];

int ans[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	intl t;
	cin >> n >> m >> t;
	for(int i = 0; i < n; i ++)
	{
		char c;
		cin >> s[i] >> c;
		s[i] --;
		d[i] = (c == 'L');
		p[i] = {s[i], i};
	}
	intl shift = 0;
	for(int i = 0; i < n; i ++)
	{
		if(d[i] == 1)
		{
			e[i] = ((s[i] - t) % m + m) % m;
			shift += (s[i] - t - e[i]) / m;
		}
		else
		{
			e[i] = (s[i] + t) % m;
			shift += (s[i] + t - e[i]) / m;
		}
		shift = (shift % n + n) % n;
	}

	sort(p, p + n);
	sort(e, e + n);
	for(int i = 0; i < n; i ++)
		ans[p[i].second] = e[(i + shift) % n];
	for(int i = 0; i < n; i ++)
		cout << ans[i] + 1 << ' ';
	cout << '\n';

	return 0;
}