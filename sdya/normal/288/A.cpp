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

const int maxN = 1100000;
char s[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, k;
	scanf("%d%d", &n, &k);

	if (k == 1) {
		if (n == 1) {
			printf("a\n");
			return 0;
		}
		printf("-1\n");
		return 0;
	}

	if (k > n) {
		printf("-1\n");
		return 0;
	}
	if (k == 2) {
		for (int i = 0; i < n; ++i) {
			s[i] = (i % 2 == 0 ? 'a' : 'b');
		}
		puts(s);
		return 0;
	}

	if ((n - k) % 2 == 0) {
		for (int i = 0; i < n - k; ++i) {
			s[i] = (i % 2 == 0 ? 'a' : 'b');
		}
		for (int i = n - k; i < n; ++i) {
			s[i] = i - (n - k) + 'a';
		}
		puts(s);
		return 0;
	}
	for (int i = 0; i < n - k; ++i) {
		s[i] = (i % 2 == 0 ? 'a' : 'b');
	}
	for (int i = n - k; i < n; ++i) {
		s[i] = i - (n - k) + 'a';
	}
	swap(s[n - k], s[n - k + 1]);
	puts(s);

	return 0;
}