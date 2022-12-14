#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 500005, P = 1000000007;
int n;
struct point {
	ll x, y;
} p[2 * N];

point operator+(const point &a, const point &b) {
	return (point){a.x + b.x, a.y + b.y};
}
point operator-(const point &a, const point &b) {
	return (point){a.x - b.x, a.y - b.y};
}
ll operator*(const point &a, const point &b) {
	return a.x * b.y - b.x * a.y;
}
ll det(const point &a, const point &b) {
	return (a.x % P) * (b.y % P) - (b.x % P) * (a.y % P);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld%lld", &p[i].x, &p[i].y);
	reverse(p + 1, p + 1 + n);
	copy(p + 1, p + n, p + 1 + n);
	ll all = 0, s0 = p[1] * p[2], s1 = p[1] * p[2], ans = 0, cnt = 0;
	point sump = p[2];
	for (int i = 1; i <= n; ++i) all += p[i] * p[i % n + 1];
	for (int i = 1, j = 2; i <= n; ++i) {
		while (j + 1 < i + n && s0 + p[j] * p[j + 1] + p[j + 1] * p[i] <= all / 2)
			s0 += p[j] * p[j + 1], s1 = (s1 + p[j] * p[j + 1] % P * j) % P, sump = sump + p[++j];
		cnt += j - i;
		ans = (ans + det(sump, p[i]) + s0 % P * j - s1) % P;
		s0 -= p[i] * p[i + 1];
		s1 = (s1 - p[i] * p[i + 1] % P * i) % P;
		sump = sump - p[i + 1];
	}
	cnt -= n;
	printf("%lld\n", ((all % P * (cnt % P) - 2 * ans) % P + P) % P);
	return 0;
}