#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int a[110];
	int mx = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	int mn = mx;
	for(;;mn++)
	{
		int x = 0;
		for(int i = 0; i < n; i++)
		{
			if(mn > a[i]) x += mn - a[i];
		}
		if(x >= m) break;
	}
	cout << mn << " " << mx + m << endl;
}