#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
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

inline int Abs(const int& x) {return (x > 0 ? x : -x);}
inline int Max(const int& x, const int& y) {return (x > y ? x : y);}
inline int Min(const int& x, const int& y) {return (x < y ? x : y);}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		register int ans = 0;
		for (register int i = 1;i < n;i++) {
			string s;
			cin >> s;
			if (s[m - 1] == 'R') ans++;
		}
		string s;
		cin >> s;
		for (register int i = 0;i < m - 1;i++) {
			if (s[i] == 'D') ans++;
		}
		printf("%d\n", ans);
	}
	#ifndef ONLINE_JUDGE
	while (1);
	#endif
	return 0;
}