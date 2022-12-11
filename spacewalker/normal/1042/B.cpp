#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
constexpr int INF = 500000000;

int minWay[8];

int toBitmask(string &s) {
	int res = 0;
	for (char c : s) {
		if (c == 'A') res |= 1;
		if (c == 'B') res |= 2;
		if (c == 'C') res |= 4;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 8; ++i) minWay[i] = INF;
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int x; string s; cin >> x >> s;
		int tb = toBitmask(s);
		minWay[tb] = min(minWay[tb], x);
	}
	minWay[0] = 0;
	int ans = INF;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			for (int k = 0; k < 8; ++k) {
				if ((i | j | k) == 7) {
					// printf("%d %d %d valid cost %d\n",i, j, k, minWay[i] + minWay[j] + minWay[k]);
					ans = min(ans, minWay[i] + minWay[j] + minWay[k]);
				}
			}
		}
	}
	printf("%d\n", (ans == INF ? -1 : ans));
	return 0;
}