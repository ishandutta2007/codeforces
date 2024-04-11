#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <string>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n, a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	sort(a, a + n);

	int res = 0;
	long long t = 0;
	for (int i = 0; i < n; ++i) {
		if ((long long)(a[i]) >= t) {
			++res;
			t += a[i];
		}
	}

	printf("%d\n", res);



	return 0;
}