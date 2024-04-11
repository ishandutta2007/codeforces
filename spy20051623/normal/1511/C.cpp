#include <bits/stdc++.h>

using namespace std;

int p[55];

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
	int n, q, k;
	n=read();
	q=read();
	for (int i = 1; i <= n; ++i) {
		k=read();
		if (p[k] == 0)
			p[k] = i;
	}
	while (q--) {
		k=read();
		printf("%d ", p[k]);
		for (int i = 1; i <= 50; ++i) {
			if (i != k && p[i] != 0 && p[i] < p[k])
				++p[i];
		}
		p[k] = 1;
	}
	return 0;
}