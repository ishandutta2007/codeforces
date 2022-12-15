#include<bits/stdc++.h>

using namespace std;

int a[107];

int main ()
{
	int n;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int sum = 0, maxi = -1;

	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
		maxi = max(maxi, a[i]);
	}

	for(int i = maxi; true; i++)
	{
		if(i*n > 2*sum)
		{
			cout << i << endl;

			return 0;
		}
	}

	return 0;


}