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

const long long inf = 8000000000000000000LL;

long long gcd(long long a, long long b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	if (a > b) {
		return gcd(a % b, b);
	} else {
		return gcd(b % a, a);
	}
}

long long lcm(long long a, long long b) {
	long long x = (a / gcd(a, b));
	if (x >= inf / b) {
		return inf;
	}
	return (a / gcd(a, b)) * b;
}

int n, x;

const int maxN = 1500000;
bool p[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 2; i * i < maxN; ++i) {
		if (!p[i]) {
			for (int j = i * i; j < maxN; j += i) {
				p[j] = true;
			}
		}
	}
	vector < int > primes;
	for (int i = 2; i < maxN; ++i) {
		if (!p[i]) {
			primes.push_back(i);
		}
	}

	scanf("%d%d", &n, &x);
	vector < int > a(n);
	long long g = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	if (x == 2) {
		cout << 0 << endl;
		return 0;
	}
	if (n > 0 && a[0] == 1) {
		cout << 1 << endl;
		return 0;
	}

	int index = lower_bound(primes.begin(), primes.end(), x) - primes.begin();
	if (index == primes.size()) {
		cout << -1 << endl;
		return 0;
	}

	bool ok = true;
	for (int i = 0; i < index; ++i) {
		if (!binary_search(a.begin(), a.end(), primes[i])) {
			ok = false;
			break;
		}
	}

	if (ok) {
		cout << index << endl;
	} else {
		cout << -1 << endl;
	}
	
	return 0;
}