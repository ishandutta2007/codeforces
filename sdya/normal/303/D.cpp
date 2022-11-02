#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
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

long long powmod(long long a, long long n, long long p) {
	if (n == 0) {
		return 1LL % p;
	}
	long long b = powmod(a, n / 2, p);
	b = (b * b) % p;
	if (n % 2 == 1) {
		b = (b * a) % p;
	}
	return b;
}

bool check(long long x, const vector < long long > &d, long long p) {
	for (int i = 0; i < d.size(); ++i) {
		long long value = powmod(x % p, (p - 1) / d[i], p);
		if (value == 1) {
			return false;
		}
	}
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, x;
	cin >> n >> x;
	if (!isPrime(n + 1)) {
		printf("-1\n");
		return 0;
	}

	vector < long long > d;
	int m = n;
	{
		int i = 2;
		while (i * i <= n) {
			int q = 0;
			while (m % i == 0) {
				++q;
				m /= i;
			}
			if (q > 0) {
				d.push_back(i);
			}
			++i;
		}
		if (m != 1) {
			d.push_back(m);
		}
	}

	for (int i = x - 1; i > 1; --i) {
		if (check(i, d, n + 1)) {
			cout << i << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}