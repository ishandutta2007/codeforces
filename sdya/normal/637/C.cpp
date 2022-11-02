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

const int maxN = 1100;
const int maxL = 25;
int n;
char s[maxN][maxL];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s[i]);
	}

	int res = 6;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int d = 0;
			for (int k = 0; k < 6; ++k) {
				if (s[i][k] == s[j][k]) {
					++d;
				}
			}
			if (d == 5 || d == 4) {
				res = min(res, 0);
			}
			if (d == 3 || d == 2) {
				res = min(res, 1);
			}
			if (d == 1 || d == 0) {
				res = min(res, 2);
			}
		}
	}
	printf("%d\n", res);

	return 0;
}