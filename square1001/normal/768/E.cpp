#include <set>
#include <vector>
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;
int grundy[] = { 0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10 };
int n, x;
int main() {
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++) scanf("%d", &x), sum ^= grundy[x];
	printf(sum == 0 ? "YES\n" : "NO\n");
	return 0;
}