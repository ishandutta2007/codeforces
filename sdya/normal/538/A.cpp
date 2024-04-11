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

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string res = "CODEFORCES";
	string s;
	cin >> s;
	int n = s.size();
	if (s == res) {
		printf("YES\n");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (n - (j - i + 1) != res.size()) {
				continue;
			}
			string t = "";
			for (int k = 0; k < n; ++k) {
				if (k >= i && k <= j) {
					continue;
				}
				t += s[k];
			}
			if (t == res) {
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");

	return 0;
}