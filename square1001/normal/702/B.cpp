#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n, a;
int main() {
	scanf("%d", &n);
	map<int, int> d;
	long long ret = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		for (int j = 0; j <= 30; j++) {
			if (a < 1 << j) ret += d[(1 << j) - a];
		}
		d[a]++;
	}
	printf("%lld\n", ret);
	return 0;
}