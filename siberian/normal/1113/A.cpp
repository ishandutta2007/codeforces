#include <bits/stdc++.h>

using namespace std;

#define int long long

void read()
{
	int v, n;
	cin >> n >> v;
	int ans;
	if (v >= n - 1)
	{
		ans = n - 1;
	}
	else
	{
		ans = 0;
		n -= v;
		ans += v;
		ans += n*(n + 1) / 2;
		ans--;
		//ans = v + (n - v)*(n - v - 1)/2 - 1;
	}

	cout << ans;	
}

void run()
{
	
}

void write()
{
	
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}