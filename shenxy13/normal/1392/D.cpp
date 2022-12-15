#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n, ans = 0;
		scanf("%d", &n);
		char s[n];
		for (int i = 0; i < n; ++i) scanf(" %c", &s[i]);
		int l = 0;
		vector<int> conts;
		for (int i = 1; i < n; ++i) {
			if (s[i] != s[i - 1]) conts.push_back(i - l), l = i;
		}
		conts.push_back(n - l);
		if (conts.size() == 1) {
			printf("%d\n", (n + 2) / 3);
			continue;
		}
		if (s[0] == s[n - 1] && conts.size() != 1) conts[0] += conts.back(), conts.pop_back();
		for (int i: conts) ans += i / 3;
		printf("%d\n", ans);
	}
	return 0;
}