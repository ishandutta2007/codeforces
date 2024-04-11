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

int n, l[100005], r[100005], c[100005];

inline void Read() {
	n = qread();
	for (int i = 1;i <= n;i++) {
		l[i] = qread(); r[i] = qread(); c[i] = qread();
	}
}

inline void Solve() {
	int lmn = 1, rmx = 1, cmn = 1, lenmx = 1;
	cout << c[1] << '\n';
	for (int i = 2;i <= n;i++) {
		if (r[i] > r[rmx] || (r[i] == r[rmx] && c[i] < c[rmx])) rmx = i;
		if (l[i] < l[lmn] || (l[i] == l[lmn] && c[i] < c[lmn])) lmn = i;
		if (r[i] - l[i] + 1 > r[lenmx] - l[lenmx] + 1 || (r[i] - l[i] + 1 == r[lenmx] - l[lenmx] + 1 && c[i] < c[lenmx])) lenmx = i;
		if (l[lmn] == l[lenmx] && r[rmx] == r[lenmx]) cout << min(c[lmn] + c[rmx], c[lenmx]) << '\n';
		else cout << c[lmn] + c[rmx] << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	int t = qread();
	while (t--) {
		Read();
		Solve();
	}
	cout.flush();
	#ifdef CFA_44
	while (1);
	#endif
	return 0;
}