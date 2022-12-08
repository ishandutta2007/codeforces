#include <bits/stdc++.h>

using namespace std;

char s[1000005];
int fast[1000005];

int main() {
//	freopen("in.txt", "r", stdin);
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	for (int i = 0; i < n; ++i)
		s[n + i] = s[i];
	s[n + n] = '\0';
	for (int i = 1; i < n; ++i) {
		int t = i;
		for (int j = 1; j <= sqrt(i); ++j) {
			if (i % j == 0) {
				t = max(t, fast[j]);
			}
		}
		for (int j = t; j < n + n; ++j) {
			if (s[j % i] < s[j]) {
				for (int l = 0; l < k; ++l) {
					printf("%c", s[l % i]);
				}
				return 0;
			}
			if (s[j % i] > s[j]) {
				fast[i] = j;
				break;
			}
			if (j == n + n - 1) {
				fast[i] = n + n - 1;
			}
		}
	}
	for (int i = 0; i < k; ++i) {
		printf("%c", s[i % n]);
	}
	return 0;
}