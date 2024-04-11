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

const int maxN = 210;
int n, f[maxN], f2[maxN], g[maxN], g2[maxN];
int used[maxN];

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
	return (a / gcd(a, b)) * b;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> f[i];
	}
	for (int i = 1; i <= n; ++i) {
		f2[i] = f[f[i]];
	}

	for (int i = 1; i <= n; ++i) {
		g[i] = i;
		g2[i] = i;
	}

	for (int k = 1; k <= 100000; ++k) {
		bool isOk = true;
		for (int i = 1; i <= n; ++i) {
			g[i] = f[g[i]];
			g2[i] = f2[g2[i]];
			if (g[i] != g2[i]) {
				isOk = false;
			}
		}
		if (isOk) {
			printf("%d\n", k);
			//break;
			return 0;
		}
	}

	long long res = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			used[j] = 0;
		}

		int v = i;
		int cnt = 1;
		while (true) {
			if (used[v] != 0) {
				res = lcm(res, cnt - used[v]);
				break;
			}
			used[v] = cnt;
			++cnt;
			v = f[v];
		}
	}

	cout << res << endl;

	return 0;
}