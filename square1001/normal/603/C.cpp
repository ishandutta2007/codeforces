#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int solve(int x) {
	if (x == 0 || x == 2 || (x >= 5 && x % 2 == 1)) return 0;
	if (x % 2 == 1) return 1;
	int p1 = solve(x - 1), p2 = solve(x / 2);
	return (p1 + p2 == 1 ? 2 : 1);
}
int n, m, x;
int main() {
	scanf("%d %d", &n, &m); m &= 1;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (m == 0) {
			if (x <= 2) ret ^= x;
			else ret ^= (x + 1) & 1;
		}
		else ret ^= solve(x);
	}
	printf(ret ? "Kevin\n" : "Nicky\n");
	return 0;
}