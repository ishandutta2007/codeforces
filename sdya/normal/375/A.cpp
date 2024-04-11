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

	map < int, int > M;
	vector < int > a({ 1, 6, 8, 9 });
	do {
		int rem = 0, value = 0;
		for (int i = 0; i < 4; ++i) {
			rem = rem * 10 + a[i];
			rem %= 7;
			value = value * 10 + a[i];
		}
		M[rem] = value;
	} while (next_permutation(a.begin(), a.end()));

	scanf("%s", &s);
	vector < int > b(10, 0);
	int n = strlen(s);
	for (int i = 0; i < n; ++i) {
		++b[s[i] - '0'];
	}
	--b[1];
	--b[6];
	--b[8];
	--b[9];
	if (b[0] + 4 == n) {
		printf("%d", M[0]);
		for (int i = 0; i < b[0]; ++i) {
			printf("0");
		}
		printf("\n");
		return 0;
	}
	int score = 0;
	for (int i = 9; i >= 0; --i) {
		for (int j = 0; j < b[i]; ++j) {
			score = score * 10 + i;
			score %= 7;
			printf("%d", i);
		}
	}

	
	score = (score * 10000) % 7;
	int need = (7 - score) % 7;
	printf("%d\n", M[need]);

	return 0;
}