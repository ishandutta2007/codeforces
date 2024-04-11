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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long P = 1000000007LL;

long long inv(long long a) {
	long long x1 = 1, b1 = a;
	long long x2 = 0, b2 = P;
	while (b2) {
		long long q = b1 / b2;
		b1 -= q * b2;
		x1 -= q * x2;
		swap(x1, x2);
		swap(b1, b2);
	}
	return ((x1 % P) + P) % P;
}

const int maxN = 210000;
long long f[maxN], invf[maxN], p[maxN];

long long cnk(long long n, long long k) {
	if (n < 0 || k < 0 || n < k) {
		return 0LL;
	}
	long long q = (invf[k] * invf[n - k]) % P;
	return (f[n] * q) % P;
}

int n, k;
string s;

long long c[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	f[0] = invf[0] = p[0] = 1LL;
	for (int i = 1; i < maxN; ++i) {
		f[i] = (f[i - 1] * (long long)(i)) % P;
		invf[i] = inv(f[i]);
		p[i] = (p[i - 1] * 10LL) % P;
	}

	cin >> n >> k;
	cin >> s;

	if (k == 0) {
		long long res = 0;
		for (int i = 0; i < n; ++i) {
			res = res * 10LL + (long long)(s[i] - '0');
			res %= P;
		}
		cout << res << endl;
		return 0;
	}

	long long coef = 0;
	for (int i = 1; i < n; ++i) {
		c[i - 1] = cnk(n - i - 1, k - 1);
	}


	long long res = 0, sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += (c[i] * p[i]) % P;
		sum %= P;
	}
	for (int i = 0; i < n; ++i) {
		long long value = s[i] - '0';
		int length = n - 1 - i;
		if (c[length + 1] > 0) {
			sum -= (c[length + 1] * p[length + 1]) % P;
			sum += (c[length + 1] * p[length]) % P;
			c[length] = (c[length] + c[length + 1]) % P;
			c[length + 1] = 0;
		}
		sum = ((sum % P) + P) % P;
		res += value * sum;
		res %= P;
	}

	cout << res << endl;


	return 0;
}