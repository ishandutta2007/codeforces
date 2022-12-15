#include<bits/stdc++.h>

using namespace std;

const int N = 1007;

int a[N];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	a[0] = 0;
	a[n+1] = 1001;

	int res = 0, cons = 1;

	for(int i = 0; i <= n; i++)
	{
		if(a[i]+1 == a[i+1])
			cons++;
		else
		{
			res = max(cons-2, res);
			cons = 1;
		}
	}

	res = max(cons-2, res);

	cout << res << "\n";

	return 0;
}