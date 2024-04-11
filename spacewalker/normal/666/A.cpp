/*
 * it is decomposable if
 * 2
 * 3
 * 2 + 3
 * 6 and up can be decomposed 
 * so the only issue is strings of length 1 and 4
 *
 * LENGTH 2 SUFFIXES
 * if remaining has length 1: impossible
 * if remaining has length 2: check if 
 * if rhl 3: 
 * aabbb
 * aabbbcc
 * aabbb
 */

#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 1000000;

char str[NMAX];

bool checkSame(int i, int j) {
	for (int k = 0; k < j - i; ++k) {
		if (str[i + k] != str[j + k]) return false;
	}
	return true;
}

int main() {
	scanf("%s", str);
	int n = strlen(str);
	vector<bool> pBehind2(n, false);
	vector<bool> pBehind3(n, false);
	set<string> ans;
	for (int si = n - 2; si > 4; --si) {
		// first, check if the 2-string is doable
		if (si == n - 2) pBehind2[si] = true;
		if (si < n - 3 && !checkSame(si, si + 2) && pBehind2[si + 2]) pBehind2[si] = true;
		if (si < n - 4 && pBehind3[si + 2]) pBehind2[si] = true;
		if (pBehind2[si]) ans.emplace(begin(str) + si, begin(str) + si + 2);
		if (si == n - 3) pBehind3[si] = true;
		if (si < n - 4 && pBehind2[si + 3]) pBehind3[si] = true;
		if (si < n - 5 && !checkSame(si, si + 3) && pBehind3[si + 3]) pBehind3[si] = true;
		if (pBehind3[si]) ans.emplace(begin(str) + si, begin(str) + si + 3);
	}
	printf("%lu\n", ans.size());
	for (auto s : ans) {
		printf("%s\n", s.c_str());
	}
	return 0;
}