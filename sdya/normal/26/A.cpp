#include <iostream>

using namespace std;

bool is_prime(int x)
{
	for (int i = 2; i * i <= x; i ++)
		if (x % i == 0) return false;
	return true;
}

int p[4000];

int main()
{
	for (int i = 2; i <= 3000; i ++)
		p[i] = is_prime(i);

	int res = 0;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		int c = 0;
		for (int j = 1; j <= i; j ++)
			if (i % j == 0 && p[j]) c ++;
		if (c == 2) res ++;
	}

	cout << res << endl;

	return 0;
}