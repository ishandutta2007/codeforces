#include <bits/stdc++.h>
using namespace std;

int gas2, gas3, gas6, n, m;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; ; i ++) {
		if (i % 6 == 0) gas6 ++;
		else if (i % 2 == 0 && gas2 < n) gas2 ++;
		else if (i % 3 == 0 && gas3 < m) gas3 ++;
		if (gas2 + gas3 + gas6 == n + m) {
			printf("%d\n", i); return 0;
		}
	}
}