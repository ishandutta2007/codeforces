#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	if (n & 1) puts("0");
	else {
		n >>= 1; printf("%d\n", (n - 1) / 2);
	}
}