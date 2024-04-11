#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long m, n;
	cin >> m >> n;
	if(m%2 == 0 && n%2 == 0)
	{
		if(m == 2 && n == 2) cout << 0 << endl;
		else cout << m*n << endl;
	}
	else if((m + n)%2 && min(m, n) > 1)
	{
		if(n % 2 == 0) swap(m, n);
		if(m == 2)
		{
			if(n == 1) cout << 0 << endl;
			else if(n == 3) cout << 4 << endl;
			else if(n == 7) cout << 12 << endl;
			else cout << m*n << endl;
		}
		else cout << m*n << endl;
	}
	else
	{
		if(m > n) swap(m, n);
		if(m > 1) cout << m*n - 1 << endl;
		else
		{
			if(n % 6 == 0) cout << n << endl;
			else if (n % 6 == 2) cout << n - 2 << endl;
			else if (n % 6 == 4) cout << n - 2 << endl; 
			else if(n % 6 == 3) cout << n - 3 << endl;
			else cout << m*n - 1 << endl;
		}
	}
}