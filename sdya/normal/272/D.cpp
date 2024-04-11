#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int P;

long long powmod(long long a, long long n) {
	if (n == 0) {
		return 1LL % (long long)(P);
	}

	long long b = powmod(a, n / 2LL);
	b = (b * b) % (long long)(P);

	if (n % 2LL == 0LL) {
		return b;
	} else {
		return (a * b) % (long long)(P);
	}
}

vector < int > primes;

bool isPrime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

long long getPower(long long n, long long p) {
	long long q = p, res = 0;
	while (q <= n) {
		res += n / q;
		q *= p;
	}
	return res;
}

long long factorial(long long n, long long k) {
	long long res = 1LL;
	for (int i = 0; i < primes.size(); ++i) {
		if (primes[i] > n) {
			break;
		}
		res *= powmod(primes[i], getPower(n, primes[i]) - (primes[i] == 2 ? k : 0));
		res %= (long long)(P);
	}
	return res;
}

int main() {
	int n;
	scanf("%d", &n);
	vector < pair < int, int > > parts;
	for (int j = 0; j < 2; ++j) {
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			parts.push_back(make_pair(x, i));
		}
	}
	scanf("%d", &P);

	for (int i = 2; i <= 200000; ++i) {
		if (isPrime(i)) {
			primes.push_back(i);
		}
	}

	sort(parts.begin(), parts.end());
	int left_bound = 0;
	long long res = 1LL;
	for (int i = 1; i <= parts.size(); ++i) {
		if (i == parts.size() || parts[i].first > parts[i - 1].first) {
			int length = i - left_bound;
			int common = 0;
			for (int j = left_bound + 1; j < i; ++j) {
				if (parts[j] == parts[j - 1]) {
					++common;
				}
			}
			res *= factorial(length, common);
			res %= (long long)(P);
			left_bound = i;
		}
	}

	printf("%d\n", (int)(res));
	return 0;
}