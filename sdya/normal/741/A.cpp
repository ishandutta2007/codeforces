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

long long gcd(long long a, long long b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	if (a > b) {
		return gcd(a % b, b);
	}
	return gcd(b % a, a);
}

long long lcm(long long a, long long b) {
	return (a / gcd(a, b)) * b;
}

const int maxN = 110;
int g[maxN][maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector < int > p(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}

	long long res = 1;
	for (int i = 1; i <= n; ++i) {
		int r = -1;
		for (int j = 1; j <= n; ++j) {
			int x = i;
			for (int k = 0; k < 2 * j; ++k) {
				x = p[x];
			}
			if (x == i) {
				g[i][j] = 1;
				r = j;
				break;
			}
		}
		if (r == -1) {
			cout << -1 << endl;
			return 0;
		}
		res = lcm(res, r);
	}

	cout << res << endl;

	return 0;
}