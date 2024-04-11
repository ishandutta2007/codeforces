#include <bits/stdc++.h>

using namespace std;

char s[100005];
int c0[100005];
int c1[100005];

int main() {
//	freopen("in.txt", "r", stdin);
	s[0] = '#';
	long long x, y;
	scanf("%s", s + 1);
	int n = strlen(s + 1), m = 0;
	for (int i = 1; i <= n; ++i) {
		c0[i] = c0[i - 1], c1[i] = c1[i - 1];
		if (s[i] == '?')++m;
		if (s[i] == '0')++c0[i];
		if (s[i] == '1')++c1[i];
	}
	scanf("%lld%lld", &x, &y);
	long long ans = 0x7fffffffffffffff;
	long long sum;
	int pos;
	sum = 0;
	pos = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '?')sum += y * c1[i - 1], ++pos;
		if (s[i] == '0')sum += y * c1[i - 1];
		if (s[i] == '1')sum += x * (c0[i - 1] + pos);
	}
	ans = min(ans, sum);
	pos = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '?') {
			sum += (m - 1 - pos - pos) * y + (c0[n] - c0[i] - c1[i - 1]) * y - (c1[n] - c1[i] - c0[i - 1]) * x;
			++pos;
			ans = min(ans, sum);
		}
	}
	sum = 0;
	pos = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '?')sum += x * c0[i - 1], ++pos;
		if (s[i] == '0')sum += y * (c1[i - 1] + pos);
		if (s[i] == '1')sum += x * c0[i - 1];
	}
	ans = min(ans, sum);
	pos = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '?') {
			sum += (m - 1 - pos - pos) * x + (c1[n] - c1[i] - c0[i - 1]) * x - (c0[n] - c0[i] - c1[i - 1]) * y;
			++pos;
			ans = min(ans, sum);
		}
	}
	printf("%lld\n", ans);
	return 0;
}