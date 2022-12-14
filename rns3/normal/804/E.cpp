#include <bits/stdc++.h>
using namespace std;

int n;

void put(int i, int j) {
	printf("%d %d\n", i, j);
}

int main() {
	scanf("%d", &n);
	if (n % 4 == 2 || n % 4 == 3) {
		puts("NO");
		return 0;
	}
	puts("YES");
	for (int i = 1; i < n; i += 2) {
		for (int j = i + 2; j < n; j += 2) put(i, j), put(i + 1, j + 1), put(i, j + 1), put(i + 1, j);
		if (n % 4) put(i, n), put(i, i + 1), put(i + 1, n);
		else put(i, i + 1);
	}

	return 0;
}