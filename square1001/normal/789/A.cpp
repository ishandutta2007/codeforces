#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, m, x;
int main() {
	scanf("%d %d", &n, &m);
	long long ret = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		ret += (x + m - 1) / m;
	}
	printf("%lld\n", (ret + 1) / 2);
	return 0;
}