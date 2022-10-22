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

int cnt[100005], n, q, a[100005];
multiset <int> st;

inline void Read() {
	n = qread();
	for (register int i = 1;i <= n;i++) {
		a[i] = qread();
		if (cnt[a[i]]) st.erase(st.find(cnt[a[i]]));
		cnt[a[i]]++;
		st.insert(cnt[a[i]]);
	}
}

inline void Solve() {
	register int q = qread();
	while (q--) {
		register char opt = getchar();
		while (opt != '+' && opt != '-') opt = getchar();
		register int x = qread();
		if (opt == '+') {
			if (cnt[x]) st.erase(st.find(cnt[x]));
			cnt[x]++;
			st.insert(cnt[x]);
		} else if (opt == '-') {
			st.erase(st.find(cnt[x]));
			cnt[x]--;
			if (cnt[x]) st.insert(cnt[x]);
		}
		if (st.empty()) {
			puts("NO");
			continue;
		}
		register int tmp1 = *(--st.end());
		if (tmp1 >= 4) {
			st.erase(--st.end());
			st.insert(tmp1 - 4);
			register int tmp2 = *(--st.end());
			if (tmp2 >= 2) {
				st.erase(--st.end());
				st.insert(tmp2 - 2);
				register int tmp3 = *(--st.end());
				if (tmp3 >= 2) {
					puts("YES");
				} else {
					puts("NO");
				}
				st.erase(st.find(tmp2 - 2));
				st.insert(tmp2);
			} else puts("NO");
			st.erase(st.find(tmp1 - 4));
			st.insert(tmp1);
		} else puts("NO");
	}
}

int main() {
	Read();
	Solve();
	#ifndef ONLINE_JUDGE
	while (1);
	#endif
	return 0;
}