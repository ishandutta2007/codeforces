#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n;
int main() {
	scanf("%d", &n);
	printf("%d\n", n / 2);
	for (int i = 0; i < n / 2 - 1; i++) printf("2 ");
	printf("%d\n", n % 2 + 2);
	return 0;
}