#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 1211111;
typedef long long intl;

bool is_prime[N];

bool pal(int n)
{
	vector <int> vec;
	while(n > 0)
	{
		vec.push_back(n % 10);
		n /= 10;
	}
	int m = vec.size();
	for(int i = 0; i < m; i ++)
		if(vec[i] != vec[m - i - 1])
			return false;
	return true;
}

int main()
{
	ios :: sync_with_stdio(false);

	memset(is_prime, true, sizeof(is_prime));
	is_prime[1] = false;
	for(int i = 2; i < N; i ++)
		if(is_prime[i])
			for(int j = i * 2; j < N; j += i)
				is_prime[j] = false;

	int p, q;
	cin >> p >> q;

	intl c1 = 0, c2 = 0;
	int ans = 0;
	for(int i = 1; i < N; i ++)
	{
		if(is_prime[i])
			c1 ++;
		if(pal(i))
			c2 ++;
		if(c1 * q <= c2 * p)
			ans = i;
	}
	cout << ans << '\n';

	return 0;
}