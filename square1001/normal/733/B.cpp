#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n, l[100009], r[100009];
int main() {
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++) scanf("%d %d", &l[i], &r[i]), sum += l[i] - r[i];
	int ret = abs(sum), pos = -1;
	for (int i = 0; i < n; i++) {
		int z = abs(sum - l[i] * 2 + r[i] * 2);
		if (ret < z) {
			ret = z;
			pos = i;
		}
	}
	printf("%d\n", pos + 1);
	return 0;
}