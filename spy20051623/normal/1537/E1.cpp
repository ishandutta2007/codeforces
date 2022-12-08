#include <bits/stdc++.h>

using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int n, k;
	scanf("%d%d", &n, &k);
	char s[10005];
	scanf("%s", s);
	for (int i = 0; i < n; ++i)
		s[n + i] = s[i];
	s[n + n] = '\0';
	for (int i = 1; i < n; ++i) {
		for (int j = i; j <= n; ++j) {
			if (s[j % i] < s[j]) {
				for (int l = 0; l < k; ++l) {
					printf("%c", s[l % i]);
				}
				return 0;
			}
			if (s[j % i] > s[j])
				break;
		}
	}
	for (int i = 0; i < k; ++i) {
		printf("%c", s[i % n]);
	}
	return 0;
}