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

const int maxN = 110000;
int n;
char s[maxN];
int d[maxN];

bool used[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf("%s", &s);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &d[i]);
	}

	int position = 0;
	while (true) {
		if (position < 0 || position >= n) {
			printf("FINITE\n");
			return 0;
		}
		if (used[position]) {
			printf("INFINITE\n");
			return 0;
		}
		used[position] = true;
		if (s[position] == '>') {
			position += d[position];
		} else {
			position -= d[position];
		}
	}

	return 0;
}