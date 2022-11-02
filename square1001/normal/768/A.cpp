#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n, a[100009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int l = *min_element(a, a + n);
	int r = *max_element(a, a + n);
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != l && a[i] != r) ret++;
	}
	printf("%d\n", ret);
	return 0;
}