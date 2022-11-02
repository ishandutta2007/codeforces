#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n; bool prime[100009];
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n + 1; i++) prime[i] = true;
	for (int i = 2; i * i <= n + 1; i++) {
		if (!prime[i]) continue;
		for (int j = i * i; j <= n + 1; j += i) prime[j] = false;
	}
	printf("%d\n", n <= 2 ? 1 : 2);
	for (int i = 2; i <= n + 1; i++) {
		printf(i >= 3 ? " %d" : "%d", prime[i] ? 1 : 2);
	}
	return 0;
}