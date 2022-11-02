#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n, m, a[200009];
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	long long sum = 0, ret = 0;
	for (int i = 0; i < m; i++) sum += a[i];
	ret = sum;
	for (int i = m; i < n; i++) {
		sum += a[i] - a[i - m];
		ret += sum;
	}
	printf("%.15lf\n", 1.0 * ret / (n - m + 1));
	return 0;
}