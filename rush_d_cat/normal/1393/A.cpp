#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		if (n % 2 == 1) {
			printf("%d\n", (n+1)/2);
		} else {
			printf("%d\n", n/2+1);
		}
	}
}