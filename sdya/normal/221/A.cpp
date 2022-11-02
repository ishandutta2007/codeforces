#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int maxN = 1100000;
bool p[maxN];

long long getRoot(long long n) {
	long long d = sqrt((double)(n));
	for (long long i = d - 1; i <= d + 1; ++i) {
		if (i * i == n && i > 0) {
			return i;
		}
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	cout << n << " ";
	for (int i = 1; i < n; ++i) {
		cout << i << " ";
	}
	return 0;
}