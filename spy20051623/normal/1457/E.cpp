#include <bits/stdc++.h>

using namespace std;

int c[500005];

inline int read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, k;
	n = read();
	k = read();
	for (int i = 0; i < n; ++i) {
		c[i] = read();
	}
	sort(c, c + n, greater<int>());
	long long s = 0;
	int mk = 0;
	while (s >= 0 && mk < n) {
		s += c[mk++];
	}
	long long sum = 0;
	for (int i = 0; i < n - mk; ++i) {
		sum += 1LL * c[n - 1 - i] * (i / (k + 1));
	}
	--mk;
	int t = (n - 1 - mk) / (k + 1);
	while (mk >= 0) {
		sum += 1LL * c[mk] * (t++);
		--mk;
	}
	printf("%lld\n", sum);
	return 0;
}