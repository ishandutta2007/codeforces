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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

long long gcd(long long a, long long b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	if (a > b) {
		return gcd(a % b, b);
	}
	return gcd(b % a, a);
}

const int maxN = 210000;
int n, a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	long long p = 0, q = (long long)(n);
	long long s = 0;
	for (int i = 0; i < n; ++i) {
		p += (long long)(i) * (long long)(a[i]) - s;
		s += (long long)(a[i]);
	}
	p *= 2LL;
	p += s;
	long long d = gcd(p, q);
	cout << p / d << " " << q / d << endl;

	return 0;
}