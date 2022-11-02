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

const long long P = 1000000007LL;

long long inv(long long a) {
	long long x1 = 1, b1 = a;
	long long x2 = 0, b2 = P;
	while (b2) {
		long long q = b1 / b2;
		b1 -= q * b2;
		x1 -= q * x2;
		swap(b1, b2);
		swap(x1, x2);
	}
	return ((x1 % P) + P) % P;
}

long long powmod(long long a, long long n) {
	if (n == 0) {
		return 1;
	}
	long long b = powmod(a, n / 2);
	b = (b * b) % P;
	if (n % 2 == 0) {
		return b;
	}
	return (a * b) % P;
}

const int maxN = 110000;

long long f[maxN], invf[maxN];
long long p25[maxN], p26[maxN];

int m;
string s;

long long calc(long long n, long long m) {
	if (m > n) {
		return 0;
	}
}

int mode[maxN], v[maxN];

map < int, map < int, int > > M;

int d[maxN];

long long cnk(int n, int k) {
	long long A = f[n];
	long long B = (invf[k] * invf[n - k]) % P;
	return (A * B) % P;
}

void solve(int len) {
	for (int i = 0; i < maxN; ++i) {
		d[i] = 0;
	}
	for (int i = len; i < maxN; ++i) {
		long long value = (long long)(d[i - 1]) * 26LL;
		value += cnk(i - 1, len - 1) * p25[i - len];
		d[i] = value % P;
	}

	map < int, int > &m = M[len];
	vector < int > keys;
	for (map < int, int > ::iterator it = m.begin(); it != m.end(); ++it) {
		keys.push_back(it->first);
	}
	for (int i = 0; i < keys.size(); ++i) {
		m[keys[i]] = d[keys[i]];
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	f[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		f[i] = (f[i - 1] * (long long)(i)) % P;
	}
	for (int i = 0; i < maxN; ++i) {
		invf[i] = inv(f[i]);
	}

	p25[0] = p26[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		p25[i] = (p25[i - 1] * 25LL) % P;
		p26[i] = (p26[i - 1] * 26LL) % P;
	}
	scanf("%d", &m);
	cin >> s;

	int len = s.size();

	vector < int > p;
	p.push_back(len);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &mode[i]);
		if (mode[i] == 1) {
			cin >> s;
			v[i] = s.size();
			p.push_back(v[i]);
		} else {
			scanf("%d", &v[i]);
			M[s.size()][v[i]] = -1;
		}
	}

	sort(p.begin(), p.end());
	p.resize(unique(p.begin(), p.end()) - p.begin());

	for (int i = 0; i < p.size(); ++i) {
		solve(p[i]);
	}

	for (int i = 0; i < m; ++i) {
		if (mode[i] == 1) {
			len = v[i];
		} else {
			printf("%d\n", M[len][v[i]]);
		}
	}


	return 0;
}