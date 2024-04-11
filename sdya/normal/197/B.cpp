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

int gcd(int a, int b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	if (a > b) {
		return gcd(a % b, b);
	}
	return gcd(b % a, a);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	vector < int > a(n + 1), b(m + 1);
	for (int i = 0; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i <= m; ++i) {
		cin >> b[i];
	}

	if (n > m) {
		if (a[0] * b[0] < 0) {
			cout << "-Infinity";
		} else {
			cout << "Infinity";
		}
	} else if (n < m) {
		cout << "0/1" << endl;
	} else {
		int d = gcd(abs(a[0]), abs(b[0]));
		a[0] /= d;
		b[0] /= d;
		if (b[0] < 0) {
			a[0] = -a[0];
			b[0] = -b[0];
		}
		cout << a[0] << "/" << b[0] << endl;
	}

	return 0;
}