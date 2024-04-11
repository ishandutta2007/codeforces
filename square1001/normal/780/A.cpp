#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n, a[200009], c[200009];
int main() {
	scanf("%d", &n);
	int ret = 0, sum = 0;
	for (int i = 0; i < 2 * n; i++) {
		scanf("%d", &a[i]);
		c[a[i]]++; sum++;
		if (c[a[i]] == 2) c[a[i]] = 0, sum -= 2;
		ret = max(ret, sum);
	}
	printf("%d\n", ret);
	return 0;
}