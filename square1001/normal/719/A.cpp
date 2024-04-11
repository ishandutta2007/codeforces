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
	if (a[n - 1] == 0) puts("UP");
	else if (a[n - 1] == 15) puts("DOWN");
	else if (n == 1) puts("-1");
	else {
		if (a[n - 2] < a[n - 1]) puts("UP");
		else puts("DOWN");
	}
	return 0;
}