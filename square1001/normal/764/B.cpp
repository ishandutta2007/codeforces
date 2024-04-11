#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n, a[200009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int p = n / 2 - 1;
	for (int i = p; i >= 0; i--) {
		if ((min(i, n - i - 1) + 1) & 1) swap(a[i], a[n - i - 1]);
	}
	for (int i = 0; i < n; i++) {
		if (i) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
	return 0;
}