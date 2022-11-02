#include <iostream>
#include <algorithm>
using namespace std;

typedef long long intl;
const int N = 501111;
const intl Mod = (intl)1e9 + 7;
const intl Inv2 = (Mod + 1) / 2;

int x[N << 2];
int y[N << 2];

intl cross(intl a, intl b, intl c, intl d)
{
	return a * d - b * c;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> x[i] >> y[i];
	reverse(x, x + n);
	reverse(y, y + n);
	for(int i = 0; i < n; i ++)
	{
		x[i + 2 * n] = x[i + n] = x[i];
		y[i + 2 * n] = y[i + n] = y[i];
	}
	intl area = 0;
	for(int i = 1; i < n - 1; i ++)
		area += cross(x[i] - x[0], y[i] - y[0], x[i + 1] - x[0], y[i + 1] - y[0]);
	intl t_area = 0;
	intl sum_area = 0;
	intl sum_x = x[n - 1];
	intl sum_y = y[n - 1];
	intl ans = 0;
	int p = n - 1;
	while(true)
	{
		//cout << p << '\n';
		intl nxt = cross(x[p - 1] - x[0], y[p - 1] - y[0], x[p] - x[0], y[p] - y[0]);
		if(t_area + nxt <= area / 2)
		{
			t_area += nxt;
			sum_area += t_area;
			sum_area %= Mod;
			sum_x += x[p - 1];
			sum_y += y[p - 1];
			sum_x %= Mod;
			sum_y %= Mod;
			p --;
		}
		else
			break;
	}
	/*
	cout << p << '\n';
	cout << sum_area << '\n';
	cout << t_area << '\n';
	*/
	//cout << sum_x << ' ' << sum_y << '\n';
	intl half = 0;
	for(int i = 0; i < n; i ++)
	{
		while(t_area > area / 2)
		{
			sum_area -= t_area;
			sum_area %= Mod;
			t_area -= cross(x[p] - x[i], y[p] - y[i], x[p + 1] - x[i], y[p + 1] - y[i]);
			sum_x -= x[p];
			sum_y -= y[p];
			sum_x %= Mod;
			sum_y %= Mod;
			p ++;
		}
		if(t_area == area / 2 && (!(area & 1)))
		{
			half += t_area;
			half %= Mod;
		}
		//cout << "------\n";
		//cout << i << ' ' << p << '\n';
		//cout << t_area << '\n';
		//cout << '!' << ' ' << sum_area << '\n';
		//cout << sum_x << ' ' << sum_y << '\n';
		ans += sum_area;
		ans %= Mod;
		int cnt = i + n - p;
		//cout << cnt << '\n';
		t_area += cross(x[i + 1] - x[i], y[i + 1] - y[i], x[p] - x[i], y[p] - y[i]);
		sum_area += cross(x[i + 1] - x[i], y[i + 1] - y[i],
			sum_x - x[i] * (intl)cnt % Mod, sum_y - y[i] * (intl)cnt % Mod);
		/*
		cout << cross(x[i + 1] - x[i], y[i + 1] - y[i],
			sum_x - x[i] * (intl)cnt % Mod, sum_y - y[i] * (intl)cnt % Mod) << '\n';
			*/
		sum_area %= Mod;
		sum_x += x[i];
		sum_y += y[i];
		sum_x %= Mod;
		sum_y %= Mod;
		//cout << '\n';
		//cout << t_area << '\n';
		//cout << sum_area << '\n';
	}
	//cout << half << '\n';
	ans = ans - half * Inv2 % Mod;
	ans %= Mod;
	//cout << n * (n - 3) / 2 * area << '\n';
	//cout << ans << '\n';
	cout << (((intl)n * (n - 3) / 2 % Mod * (area % Mod) % Mod - 2 * ans) % Mod + Mod) % Mod << '\n';
	return 0;
}