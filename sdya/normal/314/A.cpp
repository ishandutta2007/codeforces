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

const int maxN = 210000;
int n, d, a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	long double total = 0, cnt = 0;
	for (int i = 1; i <= n; ++i) {
		long double value = total - cnt * (long double)(n - i) * (long double)(a[i]);
		if (value < (long double)(d) - 0.5) {
			printf("%d\n", i);
			continue;
		}
		total += cnt * (long double)(a[i]);
		cnt += 1.0;
	}


	return 0;
}