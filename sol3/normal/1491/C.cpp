#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <set>
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

int n, s[5005];

inline void Read() {
	n = qread();
	for (int i = 1;i <= n;i++) s[i] = qread();
}

inline void Solve() {
	set <int> st;
	for (int i = 1;i <= n;i++) {
		if (s[i] != 1) st.insert(i);
	}
	st.insert(n + 1);
	long long ans = 0;
	for (;;) {
		// int mxid = 1;
		// for (int i = 2;i <= n;i++) {
		// 	if (s[i] > s[mxid]) mxid = i;
		// }
		// if (s[mxid] == 1) break;
		if (st.empty()) break;
		int mxid = *(st.begin());
		if (mxid == n + 1) break;
		//for (int i = 1;i <= n;i++) printf("%d ", s[i]); puts("");
		//printf("mxid=%d\n", mxid);
		if (mxid + s[mxid] > n) {
			if (mxid == n) {
				ans += s[mxid] - 1;
				s[mxid] = 1;
				st.erase(mxid);
				continue;
			}
			ans += s[mxid] + mxid - n;
			s[mxid] = n - mxid;
			if (s[mxid] == 1) st.erase(mxid);
		} else {
			ans++;
			for (int i = mxid;i <= n;) {
				int tmp = s[i];
				s[i]--;
				s[i] = Max(s[i], 1);
				if (s[i] == 1) st.erase(i);
				i += tmp;
				if (i > n) break;
				i = *(st.lower_bound(i));
			}
		}
	}
	printf("%lld\n", ans);
}

int main() {
	int t = qread();
	while (t--) {
		Read();
		Solve();
	}
	#ifdef CFA_44
	while (1);
	#endif
	return 0;
}