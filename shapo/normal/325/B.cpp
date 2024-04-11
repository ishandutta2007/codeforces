#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

typedef long long ll;

#define maxn 100

ll n;
vector< ll > ans;

int main()
{
	cin >> n;
	ll l = 0, r = n + 1;
	while (l < r - 1)
	{
		ll m = (l + r) / 2;
		if ((2 * n + m - 1) / m <= m - 1)
		{
			r = m;
		}
		else
		{
			l = m;
		}
	}
	if (2 * n % r == 0 && 2 * n / r == (r - 1) && r % 2 == 1)
	{
		ans.push_back(r);
	}
	ll pk = 2LL;
	while (pk - 2 <= 2 * n)
	{
		ll lf = -1, rf = n + 1;
		while (lf < rf - 1)
		{
			ll mf = (lf + rf) / 2;
			ll k = 2 * mf + 1;
			//cout << "mf = " << mf << endl;
			if ((2 * n + k - 1) / k <= k + 2 * pk - 3)
			{
				rf = mf;
			}
			else
			{
				lf = mf;
			}
		}
		//cout << "n = " << n << " rf = " << rf << " pk = " << pk << endl;
		if (2 * n % (2 * rf + 1) == 0 && 2 * n / (2 * rf + 1) == (2 * rf + 2 * pk - 2))
		{
			ans.push_back((2 * rf + 1) * pk);
		}
		pk <<= 1;
	}
	if (ans.empty())
	{
		cout << "-1" << endl;
	}
	else
	{
		sort(ans.begin(), ans.end());
		for (vector< ll >::iterator it = ans.begin(); it != ans.end(); ++it)
		{
			cout << *it << endl;
		}
	}
	return 0;
}