#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;

int top, top_op;
char s[505], st_op[505];
array<int, 65536> st[505];

auto operator+(array<int, 65536> a, const array<int, 65536> &b) {
	for (int i = 0; i < 65536; ++i)
		a[i] = (a[i] + b[i]) % P;
	return a;
}
void fmt(array<int, 65536> &a) {
	for (int d = 1; d < 65536; d <<= 1)
		for (int i = 0; i < 65536; i += d << 1)
			for (int j = 0; j < d; ++j)
				a[i + d + j] = (a[i + d + j] + a[i + j]) % P;
}
void ifmt(array<int, 65536> &a) {
	for (int d = 1; d < 65536; d <<= 1)
		for (int i = 65536 - (d << 1); i >= 0; i -= d << 1)
			for (int j = d - 1; j >= 0; --j)
				a[i + d + j] = (a[i + d + j] + P - a[i + j]) % P;
}
auto merge_or(array<int, 65536> a, array<int, 65536> b) {
	fmt(a), fmt(b);
	for (int i = 0; i < 65536; ++i)
		a[i] = 1ll * a[i] * b[i] % P;
	ifmt(a);
	return a;
}
auto merge_and(array<int, 65536> a, array<int, 65536> b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	a = merge_or(a, b);
	reverse(a.begin(), a.end());
	return a;
}

int get(int x) {
	int res = 0;
	for (int s = 0; s < 16; ++s)
		if (s >> x & 1) res |= 1 << s;
	return res;
}

int main() {
	scanf("%s", s + 1);
	s[0] = '(';
	s[strlen(s)] = ')';
	for (int i = 0; s[i]; ++i) {
		if (s[i] == '(')
			st_op[++top_op] = '(';
		else if ((s[i] >= 'A' && s[i] <= 'D') || (s[i] >= 'a' && s[i] <= 'd') || (s[i] == '?' && s[i - 1] == '(')) {
			st_op[++top_op] = 'x';
			++top;
			fill(st[top].begin(), st[top].end(), 0);
			if (s[i] == '?') {
				for (int i = 0; i < 4; ++i)
					st[top][get(i)] = st[top][65535 - get(i)] = 1;
			} else if (s[i] >= 'A' && s[i] <= 'D') {
				st[top][get(s[i] - 'A')] = 1;
			} else {
				st[top][65535 - get(s[i] - 'a')] = 1;
			}
		} else if (s[i] == '&' || s[i] == '|' || s[i] == '?')
			st_op[++top_op] = s[i];
		else {
			if (st_op[top_op] == '&')
				st[top - 1] = merge_and(st[top - 1], st[top]), --top;
			else if (st_op[top_op] == '|')
				st[top - 1] = merge_or(st[top - 1], st[top]), --top;
			else if (st_op[top_op] == '?')
				st[top - 1] = merge_and(st[top - 1], st[top]) + merge_or(st[top - 1], st[top]), --top;
			top_op -= 2;
		}
	}
	int n, x = 0, y = 0;
	scanf("%d", &n);
	for (int i = 0, a, b, c, d, e; i < n; ++i) {
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
		if (!e) x |= 1 << a + b * 2 + c * 4 + d * 8;
		else y |= 1 << a + b * 2 + c * 4 + d * 8;
	}
	int ans = 0;
	for (int s = 0; s < 65536; ++s)
		if ((65535 - s & x) == x && (s & y) == y)
			ans = (ans + st[1][s]) % P;
	printf("%d\n", ans);
	return 0;
}