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

const int maxN = 110000;
int n, k;
long long b;
long long a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &k);
	scanf("%I64d", &b);
	for (int i = 1; i <= n; ++i) {
		scanf("%I64d", &a[i]);
	}

	multiset < long long > S;
	long long sum = 0;
	int res = n;
	for (int i = n; i >= 1; --i) {
		if (b - sum < a[i]) {
			res = i;
		}
		if (i != n) {
			S.insert(a[i]);
			sum += a[i];
		}
		if (S.size() > k - 1) {
			sum -= *S.begin();
			S.erase(S.begin());
		}
	}
	printf("%d\n", res);

	return 0;
}