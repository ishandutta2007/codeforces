#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

bool isPrime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

const int maxN = 5000;
int a, b, k;
int primes[maxN], m;

long long res = 0;

void rec(int index, long long lcm, int coef = 1) {
	if (lcm > b) {
		return;
	}
	{
		long long t = (long long)(b) / lcm - (long long)(a - 1) / lcm;
		if (coef == 1) {
			res += t;
		} else {
			res -= t;
		}
	}

	for (int i = index; i < m && primes[i] < k && primes[i] * lcm <= (long long)(b); ++i) {
		rec(i + 1, lcm * primes[i], -coef);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &a, &b, &k);
	if (!isPrime(k)) {
		printf("0\n");
		return 0;
	}

	for (int i = 2; i < 45000; ++i) {
		if (isPrime(i)) {
			primes[m++] = i;
		}
	}

	if (k > 45000) {
		int res = 0;
		for (long long i = k; i <= b; i += k) {
			if (i < a) {
				continue;
			}
			bool ok = true;
			for (int j = 0; j < m; ++j) {
				if (i % primes[j] == 0) {
					ok = false;
					break;
				}
			}
			res += ok;
		}
		printf("%d\n", res);
		return 0;
	}

	rec(0, k);
	cout << res << endl;
	
	return 0;
}