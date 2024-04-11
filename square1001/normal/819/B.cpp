#include <cstdio>
int n, p; long long s[2000009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p); p--;
		s[n - i] += p;
		s[n - i + 1] -= p + 1;
		s[n - i + p + 1] += 2;
		s[2 * n - i] -= n - p;
		s[2 * n - i + 1] += n - p - 1;
	}
	for (int i = 0; i < 2 * n; i++) s[i + 1] += s[i];
	for (int i = 0; i < 2 * n; i++) s[i + 1] += s[i];
	int pos = 0; long long ret = s[0] + s[n];
	for (int i = 1; i < n; i++) {
		if (s[i] + s[i + n] < ret) pos = i, ret = s[i] + s[i + n];
	}
	printf("%lld %d\n", ret, pos);
	return 0;
}