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

const long long P = 1000000007;
const int maxN = 2100;
int h, w, n;
int x[maxN], y[maxN];
long long d[maxN];

const int maxL = 210000;
long long f[maxL], invf[maxL];

long long inv(long long a) {
	long long x1 = 1, b1 = a;
	long long x2 = 0, b2 = P;
	while (b2) {
		long long q = (b1 / b2);
		b1 -= q * b2;
		x1 -= q * x2;
		swap(b1, b2);
		swap(x1, x2);
	}
	return ((x1 % P) + P) % P;
}

long long cnk(long long n, long long k) {
	if (k < 0 || k > n || n < 0) {
		return 0;
	}
	long long A = f[n];
	long long B = (invf[n - k] * invf[k]) % P;
	return (A * B) % P;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &h, &w, &n);
	vector < pair < int, int > > p(n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		p[i] = make_pair(x, y);
	}
	sort(p.begin(), p.end());
	f[0] = invf[0] = 1;
	for (int i = 1; i < maxL; ++i) {
		f[i] = f[i - 1] * (long long)(i);
		f[i] %= P;
		invf[i] = inv(f[i]);
	}

	for (int i = 0; i < n; ++i) {
		long long ways = cnk(p[i].first + p[i].second - 2, p[i].first - 1);
		for (int j = 0; j < n; ++j) {
			if (i != j && p[j].first <= p[i].first && p[j].second <= p[i].second) {
				ways -= d[j] * cnk(p[i].first - p[j].first + p[i].second - p[j].second, p[i].first - p[j].first);
				ways %= P;
			}
		}
		d[i] = ways;
	}

	long long res = cnk(h + w - 2, h - 1);
	for (int i = 0; i < n; ++i) {
		res -= d[i] * cnk(h - p[i].first + w - p[i].second, h - p[i].first);
		res %= P;
	}
	res = ((res % P) + P) % P;
	cout << res << endl;

	return 0;
}