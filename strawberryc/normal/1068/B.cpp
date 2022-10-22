#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)

typedef long long ll;

ll n;
int S, ans;

int main()
{
	int i;
	std::cin >> n;
	S = sqrt(n);
	For (i, 1, S)
	{
		if (n % i) continue;
		ans++;
		if (1ll * i * i != n) ans++;
	}
	std::cout << ans << std::endl;
	return 0;
}