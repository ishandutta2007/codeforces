#include<bits/stdc++.h>

using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long n, res = 0;

	cin >> n;

	for(long long i = 2; i <= n; i++)
	{
		long long p = n/i;
		res += (p*(p+1)/2) - 1;
	}

	res *= 4ll;

	cout << res << "\n";

	return 0;
}