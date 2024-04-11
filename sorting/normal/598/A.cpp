#include<bits/stdc++.h>

using namespace std;

int main ()
{
	int t;

	cin >> t;

	for(t; t > 0; t--)
	{
		long long n;

		cin >> n;

		long long logg;

		for(logg = 0; true; logg++)
			if((1<<logg) > n)
				break;

		cout << n*(n+1)/2 - 2*( (1<<logg) - 1) << "\n";
	}

	return 0;
}