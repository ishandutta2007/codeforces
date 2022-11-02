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

const int maxN = 1100000;
int p[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 2; i < maxN; ++i) {
		if (!p[i]) {
			for (int j = i + i; j < maxN; j += i) {
				p[j] = true;
			}
		}
	}

	int n;
	cin >> n;
	for (int i = 2; i + 2 <= n; ++i) {
		if (p[i] && p[n - i]) {
			printf("%d %d\n", i, n - i);
			return 0;
		}
	}


	return 0;
}