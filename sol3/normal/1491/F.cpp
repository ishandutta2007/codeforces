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

int n;
bool flag[2005];

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		int i = 2;
		for (;i <= n;i++) {
			cout << "? " << i - 1 << " " << 1 << endl;
			for (int j = 1;j < i;j++) cout << j << " ";
			cout << endl;
			cout << i << endl;
			cout.flush();
			int f;
			cin >> f;
			if (f != 0) break;
		}
		int l = 0, r = i;
		while (l < r - 1) {
			int mid = l + r >> 1;
			cout << "? " << mid << " " << i - mid << endl;
			for (int j = 1;j <= mid;j++) cout << j << " ";
			cout << endl;
			for (int j = mid + 1;j <= i;j++) cout << j << " ";
			cout << endl;
			cout.flush();
			int f;
			cin >> f;
			if (f) r = mid;
			else l = mid;
		}
		memset(flag, 0, sizeof(flag));
		for (int j = 1;j < i;j++) {
			if (j != r) flag[j] = 1;
		}
		for (int j = i + 1;j <= n;j++) {
			cout << "? " << 1 << " " << 1 << endl << i << endl << j << endl;
			cout.flush();
			int f;
			cin >> f;
			if (!f) flag[j] = 1;
		}
		int cnt = 0;
		for (int j = 1;j <= n;j++) cnt += flag[j];
		cout << "! " << cnt;
		for (int j = 1;j <= n;j++) {
			if (flag[j]) cout << " " << j;
		}
		cout << endl;
		cout.flush();
	}
	#ifdef CFA_44
	while (1);
	#endif
	return 0;
}