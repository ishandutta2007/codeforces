#define _CRT_SECURE_NO_WARNINGS
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
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100000;
char s[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", &s);
	int n = strlen(s);
	int pos = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '^') {
			pos = i;
		}
	}
	long long score = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			score += (long long)(s[i] - '0') * (long long)(pos - i);
		}
	}
	if (score == 0) {
		cout << "balance";
	} else if (score > 0) {
		cout << "left";
	} else {
		cout << "right";
	}

	return 0;
}