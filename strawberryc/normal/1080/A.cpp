#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

int n, k;

int main()
{
	std::cin >> n >> k;
	std::cout << (2 * n + k - 1) / k + (5 * n + k - 1) / k
		+ (8 * n + k - 1) / k << std::endl;
	return 0;
}