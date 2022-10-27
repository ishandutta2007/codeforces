#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		int len = 3 * n;
		int c = len / 4;
		//printf("c = %d\n", c);
		for (int i = 1; i <= c; i ++) printf("9");
		for (int i = 1; i <= n - c; i ++) printf("8");
		printf("\n");
	}
}