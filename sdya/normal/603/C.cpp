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

const int maxN = 110000;
int a[maxN], n, k;

unordered_map < int, int > M[2];

int solve(int n, int k) {
	if (n == 0) {
		return 0;
	}
	if (M[k].count(n)) {
		return M[k][n];
	}

	unordered_set < int > s;
	s.insert(solve(n - 1, k));

	if (n % 2 == 0) {
		if (k == 0) {
			s.insert(0);
		} else {
			s.insert(solve(n / 2, k));
		}
	}

	for (int i = 0; i < 5; ++i) {
		if (s.count(i) == 0) {
			return M[k][n] = i;
		}
	}
}

int calc(int n, int k) {
	if (k == 0) {
		if (n <= 2) {
			return n;
		}
		return 1 - (n % 2);
	}

	if (n == 0 || n == 2 || (n >= 5 && n % 2 == 1)) {
		return 0;
	}

	if (n == 1) {
		return 1;
	}

	{
		int m = n;
		if (m % 3 == 0) {
			m /= 3;
			int q = 0;
			while (m % 2 == 0) {
				m /= 2;
				++q;
			}
			if (q % 2 == 0 && m == 1) {
				return 1;
			}
		}
	}
	{
		int m = n;
		int q = 0;
		while (m % 2 == 0) {
			m /= 2;
			++q;
		}
		if (q % 2 == 1 && m >= 5) {
			return 1;
		}
		if (q % 2 == 1 && m == 1) {
			return 1;
		}
	}
	return 2;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	k %= 2;

	/*for (int k = 1; k < 2; ++k) {
		for (int i = 0; i < 2000; ++i) {
			printf("%d %d: %d\n", i, k, solve(i, k));

			if (calc(i, k) != solve(i, k)) {
				cerr << "BAD" << endl;
				cerr << i << endl;
			}
		}
	}*/

	int res = 0;
	for (int i = 0; i < n; ++i) {
		res ^= calc(a[i], k);
	}

	if (res == 0) {
		printf("Nicky\n");
	} else {
		printf("Kevin\n");
	}


	return 0;
}