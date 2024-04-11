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

const int maxN = 300;
char s[maxN];
int n;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf("%s", &s);

	int res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			int x = 0, y = 0;
			for (int k = i; k <= j; ++k) {
				if (s[k] == 'U') {
					++x;
				} else if (s[k] == 'D') {
					--x;
				} else if (s[k] == 'L') {
					--y;
				} else {
					++y;
				}
			}
			if (x == 0 && y == 0) {
				++res;
			}
		}
	}
	printf("%d\n", res);

	return 0;
}