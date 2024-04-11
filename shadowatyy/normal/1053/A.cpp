#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, k;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> k;

	if((2*n*m)%k)
	{
		cout << "NO" << endl;
		return 0;
	}

	if(__gcd(2*n, k)>1)
	{
		int g = __gcd(2*n, k);
		int N = 2*n/g;
		int M = m/(k/g);

		cout << "YES" << endl << 0 << " " << 0 << endl << N << " " << 0 << endl << " " << 0 << " " << M << endl;
	}
	else
	{
		int g = __gcd(2*m, k);
		int M = 2*m/g;
		int N = n/(k/g);

		cout << "YES" << endl << 0 << " " << 0 << endl << N << " " << 0 << endl << " " << 0 << " " << M << endl;
	}
	
}