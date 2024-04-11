#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n, c, p[100009], r[100009], rinv[100009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]); rinv[i] = -1;
		if (--p[i] == i) rinv[i] = c, r[c++] = i;
	}
	bool f = true;
	for (int i = 0; i < n; i++) {
		if (rinv[p[i]] == -1) f = false;
	}
	if (!f) printf("-1\n");
	else {
		printf("%d\n", c);
		for (int i = 0; i < n; i++) printf("%d ", rinv[p[i]] + 1); printf("\n");
		for (int i = 0; i < c; i++) printf("%d ", r[i] + 1); printf("\n");
	}
	return 0;
}