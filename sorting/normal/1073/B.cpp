#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

int a[N], where[N], b[N], res[N];

int main ()
{
	int n, maxi = 0;

	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		where[a[i]] = i;
	}

	for(int i = 1; i <= n; i++)
		cin >> b[i];

	for(int i = 1; i <= n; i++)
	{
		if(where[b[i]] > maxi)
		{
			res[i] = where[b[i]] - maxi;
			maxi = where[b[i]];
		}
		else
			res[i] = 0;
	}

	for(int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << "\n";

	return 0;
}