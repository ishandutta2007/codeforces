///	B : Coded by Choe Kwang

#include <bits/stdc++.h>
using namespace std;

int n, m, x;

int calc(int x) {
	return (max(0, n - 2 * x) * max(0, m - 2 * x) + 1) / 2;
}

int main() {
	scanf("%d %d %d", &n, &m, &x);
	printf("%d\n", calc(x - 1) - calc(x));
	return 0;
}