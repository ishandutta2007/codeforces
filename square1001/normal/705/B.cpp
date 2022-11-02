#include <bits/stdc++.h>
using namespace std;
int n, x, sum;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x); sum ^= x - 1;
		printf("%d\n", 2 - (sum & 1));
	}
	return 0;
}