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

const int maxN = 210000;
int n, a[maxN], b[maxN];
int pos[maxN], r[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}

	multiset < int > positive, negative;
	int zero = 0;
	for (int i = 1; i <= n; ++i) {
		if (i >= pos[b[i]]) {
			positive.insert(i - pos[b[i]]);
		} else {
			negative.insert(pos[b[i]] - i);
		}
	}

	for (int i = 1; i <= n; ++i) {
		int res = 1000000;
		if (!positive.empty()) {
			res = min(res, *positive.begin() + zero);
		}
		if (!negative.empty()) {
			res = min(res, *negative.begin() - zero);
		}
		//printf("%d\n", res);
		if (i == 1) {
			r[i] = res;
		} else {
			r[n + 2 - i] = res;
		}

		if (i == n) {
			break;
		}
		++zero;
		while (!negative.empty()) {
			int value = *negative.begin();
			if (value == zero) {
				negative.erase(negative.begin());
				positive.insert(-value);
			} else {
				break;
			}
		}

		int value = b[n + 1 - i];
		int score = (n + 1 - i) - pos[b[n + 1 - i]];
		positive.erase(positive.find(score));

		int newScore = pos[b[n + 1 - i]] - 1;
		if (newScore == 0) {
			positive.insert(newScore - zero);
		} else {
			negative.insert(newScore + zero);
		}
	}

	for (int i = 1; i <= n; ++i) {
		printf("%d\n", r[i]);
	}

	return 0;
}