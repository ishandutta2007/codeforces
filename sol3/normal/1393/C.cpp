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

int n, a[100005], tmp[100005], cnt[100005], b[100005];

inline void Read() {
	n = qread();
	for (register int i = 1;i <= n;i++) tmp[a[i] = qread()]++;
}

inline bool Check(int x) {
	for (register int i = 1;i <= n;i++) cnt[i] = tmp[i];
	set <pair <int, int> > st;
	for (register int i = 1;i <= n;i++) {
		if (cnt[i]) st.insert(make_pair(cnt[i], i));
	}
	//printf("siz=%d\n", st.size());
	for (register int i = 1;i <= n;i++) {
		if (st.empty()) return 0;
		pair <int, int> cur = *(--st.end());
		st.erase(cur);
		b[i] = cur.second;
		cnt[b[i]]--;
		if (i > x && cnt[b[i - x]]) st.insert(make_pair(cnt[b[i - x]], b[i - x]));
	}
	//for (register int i = 1;i <= n;i++) printf("%d ", b[i]);
	//puts("");
	return 1;
}

inline void Solve() {
	register int l = -1, r = n + 1;
	while (l < r - 1) {
		register int mid = l + r >> 1;
		if (Check(mid)) l = mid;
		else r = mid; 
	}
	printf("%d\n", l);
	for (register int i = 1;i <= n;i++) tmp[i] = 0;
}

int main() {
	register int t = qread();
	while (t--) {
		Read();
		Solve();
	}
	#ifndef ONLINE_JUDGE
	while (1);
	#endif
	return 0;
}