#include <iostream>

long long d[100000], ds = 0, n, ans = 0, i = 0, j = 1;

int main () {
	std::cin >> n;
	if (n % 3 == 0) {
		n /= 3;
		for (; j * j <= n; ++j)
			if (!(n % j))
				d[ds++] = j;
		for (; i < ds; ++i)
			for (j = 0; j < ds; ++j) {
				long long a = d[i], b = d[j], c = n / a / b;
				if (!(n % (a * b) || (a + b + c) % 2) && a + b > c && a + c > b && b + c > a)
					ans++;
			}
	}
	std::cout << ans;
}