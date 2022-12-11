#include <cstdio>
#include <vector>
#include <algorithm>

char str[200];

int main() {
	int n, k; scanf("%d %d", &n, &k);
	scanf("%s", str);
	if (n == 1) {
		for (int i = 0; i < k; ++i) printf("%c", str[0]);
		printf("\n"); return 0;
	}
	int pStart = n;
	for (int v = 1; v < n; ++v) {
		bool validMatch = true;
		for (int i = v; i < n; ++i) {
			if (str[i] != str[i-v]) validMatch = false;
		}
		if (validMatch) {pStart = v; break;}
	}
	for (int i = 0; i < k; ++i) {
		for (int c = 0; c < pStart; ++c) printf("%c", str[c]); 
	}
	for (int c = pStart; c < n; ++c) printf("%c", str[c]);
	printf("\n");
	return 0;
}