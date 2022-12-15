#include <bits/stdc++.h>

const long long N = 1e5 + 7;
const long long maxi = 1e13;
const long long inf = 1e9;


long long a[N];

long long is_square(long long x)
{
	long long r = sqrt(x);

	if(r*r == x)
		return r;
	if((r+1)*(r+1) == x)
		return r+1;
	if((r-1)*(r-1) == x)
		return r-1;

	return -1;
}

int main ()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	long long n;

	std::cin >> n;

	for(long long i = 1; 2*i <= n; i++)
		std::cin >> a[2*i];

	long long pr = 0;

	for(long long i = 1; 2*i <= n; i++)
	{
		long long ind = 2*i - 1, x;

		for(x = pr+1; x*x - pr*pr <= maxi; x++)
			if(is_square(x*x + a[ind+1]) != -1)
				break;

		a[ind] = x*x - pr*pr;
		pr = is_square(x*x + a[ind+1]);

		if(a[ind] > maxi || x > inf)
		{
			std::cout << "No\n";
			
			return 0;
		}
	}

	std::cout << "Yes\n";

	for(long long i = 1; i <= n; i++)
		std::cout << a[i] << " ";

	std::cout << "\n";

	return 0;
}