#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 200010;

char number[NMAX];

int main() {
	int n, k; scanf("%d %d", &n, &k);
	scanf("%s", number);
	int fvio = -1;
	for (int i = 0; i + k < n; ++i) {
		if (number[i] != number[i+k]) {
			fvio = i + k;
			break;
		}
	}
	printf("%d\n", n);
	if (fvio == -1) {
		printf("%s\n", number);
		return 0;
	}
	if (number[fvio] < number[fvio % k]) {
		for (int i = 0; i < n; ++i) printf("%c", number[i % k]);
		printf("\n");
	} else {
		++number[k-1];
		for (int i = k - 1; i >= 0; --i) {
			if (number[i] > '9') {
				number[i] = '0';
				number[i-1]++;
			}
		}
		for (int i = 0; i < n; ++i) printf("%c", number[i % k]);
		printf("\n");
	}
	return 0;
}