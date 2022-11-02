#define _CRT_SECURE_NO_WARNINGS
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
#include <list>
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

int powmod (int a, int b, int p) {
	int res = 1;
	while (b)
		if (b & 1)
			res = int (res * 1ll * a % p),  --b;
		else
			a = int (a * 1ll * a % p),  b >>= 1;
	return res;
}

int generator (int p) {
	vector<int> fact;
	int phi = p-1,  n = phi;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			fact.push_back (i);
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		fact.push_back (n);

	for (int res=2; res<=p; ++res) {
		bool ok = true;
		for (size_t i=0; i<fact.size() && ok; ++i)
			ok &= powmod (res, phi / fact[i], p) != 1;
		if (ok)  return res;
	}
	return -1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	if (n == 1) {
		printf("YES\n1\n");
		return 0;
	}
	if (n == 2) {
		printf("YES\n1\n2\n");
		return 0;
	}
	if (n == 4) {
		printf("YES\n1\n3\n2\n4\n");
		return 0;
	}

	if (!isPrime(n)) {
		printf("NO\n");
		return 0;
	}

	long long g = generator(n);

	vector < long long > p(n);
	vector < int > v(n);
	p[0] = 1;
	v[1] = 0;
	for (int i = 1; i <= n - 2; ++i) {
		p[i] = ((long long)(g) * p[i - 1]) % n;
		v[p[i]] = i;
	}

	vector < int > seq;
	int l = 0, r = n - 2;
	for (int i = 0; i < n - 1; ++i) {
		if (i % 2 == 0) {
			seq.push_back(l);
			++l;
		} else {
			seq.push_back(r);
			--r;
		}
	}

	vector < int > res;
	res.push_back(1);
	for (int i = 1; i < seq.size(); ++i) {
		int diff = seq[i] - seq[i - 1];
		if (diff < 0) {
			diff += n - 1;
		}
		res.push_back(p[diff]);
	}
	res.push_back(n);

	printf("YES\n");
	for (int i = 0; i < res.size(); ++i) {
		printf("%d\n", res[i]);
	}

	vector < bool > used(n);
	long long pp = 1;
	for (int i = 0; i < res.size(); ++i) {
		pp = (long long)(res[i]) * pp;
		pp %= (long long)(n);
		if (used[pp]) {
			cerr << "FUCK" << endl;
		}
		used[pp] = true;
	}

	return 0;
}