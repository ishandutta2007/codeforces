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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 410000;
int n, a[maxN];
long long s[maxN];

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

	long long current = s[n - 1];
	long long res = current;
	for (int i = 0; i + 1 < n; ++i) {
		current -= a[i];
		res += current;
		res += (long long)(a[i]);
	}

	cout << res << endl;

	return 0;
}