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
#include <stack>
#include <ctime>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;
char s1[maxN], s2[maxN];

void solve(char s[], int l, int r) {
	if ((r - l + 1) % 2 == 1) {
		return ;
	}
	int n = (r - l + 1) / 2;
	solve(s, l, l + n - 1);
	solve(s, l + n, r);

	bool isLess = true;
	for (int i = l; i < l + n; ++i) {
		if (s[i] < s[i + n]) {
			break;
		}
		if (s[i] == s[i + n]) {
			continue;
		}
		if (s[i] > s[i + n]) {
			isLess = false;
			break;
		}
	}
	if (!isLess) {
		for (int i = l; i < l + n; ++i) {
			swap(s[i], s[i + n]);
		}
	}
}

void norm(char s[]) {
	int n = strlen(s);
	solve(s, 0, n - 1);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", &s1);
	scanf("%s", &s2);
	norm(s1);
	norm(s2);

	int n = strlen(s1);
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		if (s1[i] != s2[i]) {
			ok = false;
		}
	}

	if (ok) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}