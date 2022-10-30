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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;
int n, p[maxN], b[maxN];
bool used[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
		cnt += b[i];
	}

	int cycles = 0;
	for (int i = 1; i <= n; ++i) {
		if (used[i]) {
			continue;
		}
		int j = i;
		while (!used[j]) {
			used[j] = true;
			j = p[j];
		}
		++cycles;
	}

	int res = (cnt % 2 == 0 ? 1 : 0);
	if (cycles > 1) {
		res += cycles;
	}
	printf("%d\n", res);

	return 0;
}