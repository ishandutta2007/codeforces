#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n, k, nL = 0, score = 0;
		scanf("%d %d", &n, &k);
		char s[n];
		for (int i = 0; i < n; ++i) scanf(" %c", &s[i]);
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'W' && i != 0 && s[i - 1] == 'W') score += 2;
			else if (s[i] == 'W') ++score;
			else ++nL;
		}
		if (nL == n) {
			printf("%d\n", max(0, 2 * min(k, n) - 1));
			continue;
		}
		int ptr = 0, pre = 0;
		vector<int> tak;
		while (ptr != n && s[ptr] == 'L') ++ptr;
		pre = ptr;
		while (ptr < n) {
			if (s[ptr] == 'L') ++ptr;
			else if (ptr != pre) {
				tak.push_back(ptr - pre);
				pre = ++ptr;
			} else pre = ++ptr;
		}
		sort(tak.begin(), tak.end());
		reverse(tak.begin(), tak.end());
		while (!tak.empty() && tak.back() <= k) {
			score += 2 * tak.back() + 1;
			nL -= tak.back();
			k -= tak.back();
			tak.pop_back();
		}
		score += 2 * min(k, nL);
		printf("%d\n", score);
	}
	return 0;
}