#include<bits/stdc++.h>

using namespace std;

void solve()
{
	int n, x, y, d;

	cin >> n >> x >> y >> d;

	if(abs(x-y) % d == 0)
	{
		cout << abs(x-y) / d << "\n";

		return;
	}

	int res = -1;

	if(1%d == y%d)
	{
		int p = (x-1), q = 0;

		q= p/d;

		if(p%d)
			q++;

		p = (y-1);

		q+= p/d;

		if(p%d)
			q++;

		if(res == -1)
			res = q;
		else
			res = min(res, q);
	}

	if(n%d == y%d)
	{
		int p = (n-x), q = 0;

		q= p/d;

		if(p%d)
			q++;

		p = (n-y);

		q+= p/d;

		if(p%d)
			q++;

		if(res == -1)
			res = q;
		else
			res = min(res, q);
	}


	cout << res << "\n";

	return;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;

	while(t--)
		solve();

	return 0;
}