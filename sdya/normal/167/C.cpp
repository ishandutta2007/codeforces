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

map < pair < long long, long long >, int > F;

int calc(long long a, long long b) {
	if (a > b) {
		swap(a, b);
	}
	if (a == 0 || b == 0) { 
		return 2;
	}
	if (b % a == 0) {
		return 1;
	}

	if (a <= 2000000000LL) {
		long long d = a;
		if (a % 2LL == 0LL) {
			d *= (a + 1LL);
		} else {
			d *= (a - 1LL);
		}
		b -= ((b - a - 1LL) / d) * d;

		if (b + 2LL * a >= a + d && a % 2 == 0LL) {
			return 1;
		}
	}
	b -= ((b - a - 1) / (2LL * a)) * (2LL * a);
	if (F.count(make_pair(a, b))) {
		return F[make_pair(a, b)];
	}
	if (calc(b % a, a) == 2) {
		return F[make_pair(a, b)] = 1;
	}

	if (calc(b - a, a) == 2) {
		return F[make_pair(a, b)] = 1;
	}
	return F[make_pair(a, b)] = 2;
}

map < pair < int, int >, int > M;

int triv(int a, int b) {
	if (a > b) {
		swap(a, b);
	}
	if (a == 0 || b == 0) {
		return 2;
	}
	if (b % a == 0) {
		return 1;
	}
	if (M.count(make_pair(a, b))) {
		return M[make_pair(a, b)];
	}

	if (triv(a, b % a) == 2) {
		return M[make_pair(a, b)] = 1;
	}
	long long value = a;
	while ((long long)(b) >= value) {
		if (triv(b - value, a) == 2) {
			return M[make_pair(a, b)] = 1;
		}
		value *= a;
	}
	return M[make_pair(a, b)] = 2;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	/*for (int i = 2; i <= 1000; ++i) {
		printf("%d: ", i);
		for (int j = i + 1; j <= 1000; ++j) {
			if (triv(i, j) != calc(i, j)) {
				cerr << "Bad" << endl;
			}
		}
		printf("\n");
	}

	return 0;
	while (true) {
		int a, b;
		cin >> a >> b;
		cout << triv(a, b) << endl;
	}*/

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		long long a, b;
		cin >> a >> b;
		int res = calc(a, b);
		if (res == 1) {
			printf("First\n");
		} else {
			printf("Second\n");
		}
		F.clear();
	}



	return 0;
}