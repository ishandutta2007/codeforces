#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
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

const int N = 150005;
int A, B, C, D, a[N], b[N], c[N], d[N];
int dA[N], dB[N], dC[N], dD[N];
vector <int> ba[N], cb[N], dc[N];

inline void Read() {
	A = qread(); B = qread(); C = qread(); D = qread();
	for (int i = 1;i <= A;i++) a[i] = qread();
	for (int i = 1;i <= B;i++) b[i] = qread();
	for (int i = 1;i <= C;i++) c[i] = qread();
	for (int i = 1;i <= D;i++) d[i] = qread();
	int m = qread();
	for (int i = 1;i <= m;i++) {
		int x = qread(), y = qread();
		ba[y].push_back(x);
	}
	m = qread();
	for (int i = 1;i <= m;i++) {
		int x = qread(), y = qread();
		cb[y].push_back(x);
	}
	m = qread();
	for (int i = 1;i <= m;i++) {
		int x = qread(), y = qread();
		dc[y].push_back(x);
	}
}

inline void Solve() {
	multiset <int> st;
	for (int i = 1;i <= A;i++) st.insert(dA[i] = a[i]);
	for (int i = 1;i <= B;i++) {
		int siz = ba[i].size();
		for (int j = 0;j < siz;j++) st.erase(st.find(dA[ba[i][j]]));
		if (st.empty() || *(st.begin()) == 0x3f3f3f3f) dB[i] = 0x3f3f3f3f;
		else dB[i] = *(st.begin()) + b[i];
		for (int j = 0;j < siz;j++) st.insert(dA[ba[i][j]]);
	}
	st.clear();
	for (int i = 1;i <= B;i++) st.insert(dB[i]);
	for (int i = 1;i <= C;i++) {
		int siz = cb[i].size();
		for (int j = 0;j < siz;j++) st.erase(st.find(dB[cb[i][j]]));
		if (st.empty() || *(st.begin()) == 0x3f3f3f3f) dC[i] = 0x3f3f3f3f;
		else dC[i] = *(st.begin()) + c[i];
		for (int j = 0;j < siz;j++) st.insert(dB[cb[i][j]]);
	}
	st.clear();
	for (int i = 1;i <= C;i++) st.insert(dC[i]);
	for (int i = 1;i <= D;i++) {
		int siz = dc[i].size();
		for (int j = 0;j < siz;j++) st.erase(st.find(dC[dc[i][j]]));
		if (st.empty() || *(st.begin()) == 0x3f3f3f3f) dD[i] = 0x3f3f3f3f;
		else dD[i] = *(st.begin()) + d[i];
		for (int j = 0;j < siz;j++) st.insert(dC[dc[i][j]]);
	}
	st.clear();
	int ans = 0x3f3f3f3f;
	for (int i = 1;i <= D;i++) ans = Min(ans, dD[i]);
	if (ans == 0x3f3f3f3f) puts("-1");
	else printf("%d", ans);
}

int main() {
	Read();
	Solve();
	#ifndef ONLINE_JUDGE
	while (1);
	#endif
	return 0;
}