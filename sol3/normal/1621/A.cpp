#include <bits/stdc++.h>
using namespace std;

#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;

inline int qread() {
	register char c = getchar();
	register int x = 0, f = 1;
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - 48;
		c = getchar();
	}
	return x * f;
}

int main() {
	std::ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		if (m * 2 > n + 1) {
			cout << -1 << endl;
			continue;
		}
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if (i == j && i % 2 && m) m--, cout << "R";
				else cout << ".";
			}
			cout << endl;
		}
	}
	#ifdef CFA_44
	while (1);
	#endif
	return 0;
}