#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n;
char s[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d\n", &n);
	gets(s);

	int m = strlen(s);
	vector < int > a;
	string cur = "";
	for (int i = 0; i < m; ++i) {
		if (s[i] == '.' || s[i] == '!' || s[i] == '?') {
			cur.push_back(s[i]);
			a.push_back(cur[0] == ' ' ? (cur.size() - 1) : cur.size());
			cur.clear();
		} else {
			cur += s[i];
		}
	}

	vector < int > dp(a.size() + 1, 1000000000);
	dp[0] = 0;
	for (int i = 0; i < a.size(); ++i) {
		int length = a[i];
		for (int j = i; j < a.size(); ++j) {
			if (length <= n) {
				dp[j + 1] = min(dp[j + 1], dp[i] + 1);
			} else {
				break;
			}
			if (j + 1 < a.size()) {
				length += a[j + 1] + 1;
			}
		}
	}
	if (dp[a.size()] == 1000000000) {
		cout << "Impossible" << endl;
	} else {
		cout << dp[a.size()] << endl;
	}

	return 0;
}