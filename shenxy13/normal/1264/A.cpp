#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, p, g = 0, s = 0, b = 0;
		bool pos = true;
		scanf("%d", &n);
		map<int, int> mp;
		for (int j = 0; j < n; ++j) {
			scanf("%d", &p);
			++mp[p];
		}
		g = (--mp.end()) -> second;
		mp.erase(--mp.end());
		while (s <= g) {
			if (mp.empty()) {
				pos = false;
				break;
			}
			s += (--mp.end()) -> second;
			mp.erase(--mp.end());
		}
		if (!pos) {
			printf("0 0 0\n");
			continue;
		}
		while (b <= g) {
			if (mp.empty()) {
				pos = false;
				break;
			}
			b += (--mp.end()) -> second;
			mp.erase(--mp.end());
		}
		if (!pos) {
			printf("0 0 0\n");
			continue;
		}
		if (2 * (g + s + b) > n) {
			printf("0 0 0\n");
			continue;
		}
		while (2 * (g + s + b + (--mp.end()) -> second) <= n) {
			b += (--mp.end()) -> second;
			mp.erase(--mp.end());
		}
		printf("%d %d %d\n", g, s, b);
	}
	return 0;
}