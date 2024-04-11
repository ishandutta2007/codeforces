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

const int maxN = 110000;
int a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		while (a[i] % 2 == 0) {
			a[i] /= 2;
		}
		while (a[i] % 3 == 0) {
			a[i] /= 3;
		}
	}

	bool isOk = true;
	for (int i = 1; i < n; ++i) {
		if (a[i] != a[0]) {
			isOk = false;
		}
	}
	if (isOk) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}