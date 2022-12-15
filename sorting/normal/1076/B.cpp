#include<bits/stdc++.h>

using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	cin >> n;

	for(long long i = 2; i*i <= n; i++)
		if(n % i == 0)
		{
			if(i == 2)
				cout << n/2 << "\n";
			else
				cout << (n-i)/2 + 1 << "\n";

			return 0;
		}

	cout << "1\n";

	return 0;
}