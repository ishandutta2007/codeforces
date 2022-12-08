#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	char s[10005];
	scanf("%s", s);
	set<char> ss;
	set<pair<char, char>> sss;
	set<tuple<char, char, char>> ssss;
	for (int i = 0; i < n; ++i) {
		ss.insert(s[i]);
	}
	for (int i = 0; i < n - 1; ++i) {
		sss.insert(make_pair(s[i], s[i + 1]));
	}
	for (int i = 0; i < n - 2; ++i) {
		ssss.insert(make_tuple(s[i], s[i + 1], s[i + 2]));
	}
	for (int i = 0; i < 26; ++i) {
		if (ss.find((char) ('a' + i)) == ss.end()) {
			printf("%c\n", (char) ('a' + i));
			return;
		}
	}
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			if (sss.find(make_pair((char) ('a' + i), (char) ('a' + j))) == sss.end()) {
				printf("%c%c\n", (char) ('a' + i), (char) ('a' + j));
				return;
			}
		}
	}
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			for (int k = 0; k < 26; ++k) {
				if (ssss.find(make_tuple((char) ('a' + i), (char) ('a' + j), (char) ('a' + k))) == ssss.end()) {
					printf("%c%c%c\n", (char) ('a' + i), (char) ('a' + j), (char) ('a' + k));
					return;
				}
			}
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}