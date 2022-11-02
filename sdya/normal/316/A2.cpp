#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
char s[maxN];

long long Ank(long long n, long long k) {
	long long res = 1LL;
	for (int i = n; i > n - k; --i) {
		res *= (long long)(i);
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	gets(s);
	int n = strlen(s);

	vector < int > used(26, 0);
	int powers = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			++used[s[i] - 'A'];
		} else if (s[i] == '?') {
			++powers;
		}
	}

	if ((s[0] >= 'A' && s[0] <= 'Z') || (s[0] == '?')) {
		int letters = 0;
		for (int i = 0; i < 26; ++i) {
			if (used[i]) {
				++letters;
			}
		}

		if (s[0] == '?') {
			cout << Ank(10, letters) * 9;
			for (int i = 0; i < powers - 1; ++i) {
				printf("0");
			}
			printf("\n");
			return 0;
		} else {
			cout << Ank(10, letters) / 10LL * 9LL;
			for (int i = 0; i < powers; ++i) {
				printf("0");
			}
			printf("\n");
			return 0;
		}
	} else {
		int letters = 0;
		for (int i = 0; i < 26; ++i) {
			if (used[i]) {
				++letters;
			}
		}

		cout << Ank(10, letters);
		for (int i = 0; i < powers; ++i) {
			printf("0");
		}
		printf("\n");
		return 0;
	}

	return 0;
}