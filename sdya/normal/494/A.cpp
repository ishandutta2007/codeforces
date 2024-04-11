#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <string>
#include <queue>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1000000;
char s[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", &s);
	int n = strlen(s);
	int balance = 0;
	int m = count(s, s + n, '#');
	vector < int > cnt(m);
	int k = 0;
	int total = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			++total;
		} else if (s[i] == ')') {
			--total;
		} else {
			--total;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			++balance;
		} else if (s[i] == ')') {
			--balance;
		}
		if (balance < 0) {
			printf("-1\n");
			return 0;
		}
		if (s[i] == '#') {
			if (k + 1 == m) {
				cnt[k++] = (total + 1);
			} else {
				cnt[k++] = (1);
			}
			balance -= cnt[k - 1];
			if (cnt[k - 1] <= 0) {
				printf("-1\n");
				return 0;
			}
		}
		if (balance < 0) {
			printf("-1\n");
			return 0;
		}
	}
	if (balance == 0) {
		for (int i = 0; i < m; ++i) {
			printf("%d\n", cnt[i]);
		}
	} else {
		printf("-1\n");
	}
	return 0;
}