#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXD = 13;
const int MOD = 10000;

struct bignum
{
	int d[MAXD];
};

bignum carry (bignum tval)
{
	for (int i = 0; i < MAXD - 1; i++)
	{
		while (tval.d[i] < 0)
		{
			tval.d[i] += MOD;
			tval.d[i+1]--;
		}
		tval.d[i+1] += tval.d[i] / MOD;
		tval.d[i] %= MOD;
	}
	return tval;
}

bignum conv (ll x)
{
	bignum tb;
	for (int i = 0; i < MAXD; i++)
		tb.d[i] = 0;
	
	int nd = 0;
	while (x > 0)
	{
		tb.d[nd] = x % MOD;
		x /= MOD;
		nd++;
	}
	
	return tb;
}

bignum mult (bignum left, bignum right)
{
	bignum tb;
	for (int i = 0; i < MAXD; i++)
	{
		tb.d[i] = 0;
		for (int j = 0; j <= i; j++)
			tb.d[i] += left.d[j] * right.d[i-j];
	}
	
	return carry (tb);
}

bignum add (bignum left, bignum right)
{
	for (int i = 0; i < MAXD; i++)
		left.d[i] += right.d[i];
	return carry (left);
}

bignum subt (bignum left, bignum right)
{
	for (int i = 0; i < MAXD; i++)
		left.d[i] -= right.d[i];
	return carry (left);
}

bignum ps (ll x, ll y)
{
	if (x == 0 || y == 0)
		return conv (0);
	swap (x, y);
	
	if (y >= x)
	{
		ll a[3] = {x, x + 1, 2 * x + 1};
		for (int i = 0; i < 3; i++)
			if (a[i] % 2 == 0)
			{
				a[i] /= 2;
				break;
			}
		for (int i = 0; i < 3; i++)
			if (a[i] % 3 == 0)
			{
				a[i] /= 3;
				break;
			}
		
		ll b[3] = {y, y + 1, 2 * y + 1};
		for (int i = 0; i < 3; i++)
			if (b[i] % 2 == 0)
			{
				b[i] /= 2;
				break;
			}
		for (int i = 0; i < 3; i++)
			if (b[i] % 3 == 0)
			{
				b[i] /= 3;
				break;
			}
		
		bignum ls = mult (conv (b[0]), mult (conv(b[1]), conv(b[2])));
		bignum rs = mult (conv (a[0]), mult (conv(a[1]), conv(a[2])));
		
		bignum f;
		if (x % 2 == 0)
			f = mult (conv (x / 2 * x), conv (x * x + 1));
		else
			f = mult (conv (x * x), conv ((x * x + 1) / 2));
		
		return add (f, subt (mult (conv (x), subt (ls, rs)), mult (conv (((x - 1) * x) / 2), conv (y - x))));
	}
	else
	{
		swap (x, y);
		
		return subt (ps (y, x), mult (conv (y), conv (x * (y - x))));
	}
}

int ndig (ll x)
{
	if (x == 0) return 1;
	int r = 0;
	while (x > 0)
	{
		x /= 10;
		r++;
	}
	return r;
}

int main()
{
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		bignum a = ps (x1 - 1, y1 - 1), b = ps (x1 - 1, y2), c = ps (x2, y1 - 1), d = ps (x2, y2);
		bignum fres = subt (add (a, d), add (b, c));
		
		//cout << ps (2, 3).d[0];
		//cout << a.d[0] << " " << b.d[0] << " " << c.d[0] << " " << d.d[0] << "\n";
		
		bool check = true;
		if (fres.d[2] >= 100)
			check = false;
		for (int j = 3; j < MAXD; j++)
			if (fres.d[j] > 0)
				check = false;
		if (check)
		{
			cout << (ll) (1e8 * fres.d[2] + 1e4 * (ll) fres.d[1] + (ll) fres.d[0]) << "\n";
		}
		else
		{
			ll res = 1e8 * ((ll)fres.d[2] % 100) + 1e4 * (ll) fres.d[1] + (ll) fres.d[0];
			cout << "...";
			for (int i = 0; i < 10 - ndig (res); i++)
				cout << "0";
			cout << res << "\n";
		}
	}
	return 0;
}