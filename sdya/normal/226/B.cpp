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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int a[maxN], n;

long long r[maxN];
long long s[maxN];

void solve(int k) {
	long long index = n - 1;
	long long res = 0;
	long long coef = 1;
	while (index > 0) {
		res += s[index - 1];
		index -= coef * k;
		coef *= k;
	}
	r[k] = res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		s[i] = a[i];
		if (i > 0) {
			s[i] += s[i - 1];
		}
	}

	for (int i = 1; i < n; ++i) {
		solve(i);
	}

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int k;
		scanf("%d", &k);
		if (k > n - 1) {
			k = n - 1;
		}
		printf("%I64d ", r[k]);
	}
	printf("\n");


	return 0;
}