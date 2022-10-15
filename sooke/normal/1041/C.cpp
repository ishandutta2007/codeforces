#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

typedef long long lol;
typedef long double lod;

inline char readLetter() {
	char c = getchar();
	while ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) { c = getchar(); }
	return c;
}
inline int read() {
	char c = getchar(); int n = 0, f = 0;
	while (c < '0' || c > '9') { if (c == '-') { f = 1; } c = getchar(); }
	while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
	return f ? -n : n;
}

const int maxInt = 2147483647;
const lol maxLongLong = 9223372036854775807ll;
const int maxN = 200005;

std::priority_queue< std::pair<int, int> > q;
int n, m, d, ans;

struct Time { int id, k, ans; } s[maxN];
bool cmpK(Time x, Time y) { return x.k < y.k; }
bool cmpID(Time x, Time y) { return x.id < y.id; }

int main() {
	n = read(), m = read(), d = read();
	for (int i = 1; i <= n; i++) { s[i] = (Time) { i, read(), 0 }; }
	std::sort(s + 1, s + n + 1, cmpK);
	ans = s[1].ans = 1, q.push(std::make_pair(-s[1].k, 1));
	for (int i = 2; i <= n; i++) {
		if (s[i].k + q.top().first > d) { s[i].ans = q.top().second, q.pop(); }
		else { s[i].ans = ++ans; }
		q.push(std::make_pair(-s[i].k, s[i].ans));
	}
	std::sort(s + 1, s + n + 1, cmpID);
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) { printf("%d ", s[i].ans); }
	return 0;
}