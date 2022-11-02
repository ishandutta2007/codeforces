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

const int maxN = 1100000;
int f[maxN];
int used[maxN];

void calc(int n) {
	int l = 1;
	while (l * l * l * l < n) {
		++l;
	}

	for (int i = l; i * i <= n && i < n; ++i) {
		used[f[i]] = n;
	}
	for (int i = 0; ; ++i) {
		if (used[i] != n) {
			f[n] = i;
			break;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	f[0] = 0;
	for (int i = 1; i <= 200000; ++i) {
		calc(i);
		/*f (true) {
			printf("%d: %d\n", i, f[i]);
		}*/
	}

	int n;
	scanf("%d", &n);
	int res = 0;
	long long D = 50625LL;
	for (int i = 1; i <= n; ++i) {
		long long x;
		scanf("%I64d", &x);
		if (x < D * D) {
			if (x > 200000) {
				x = 200000;
			}
			res ^= f[x];
		} else {
			res ^= 2;
		}
	}

	if (res != 0) {
		printf("Furlo\n");
	} else {
		printf("Rublo\n");
	}

	return 0;
}