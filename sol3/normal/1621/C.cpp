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

int p[10005], n;
bool vis[10005];

inline int Query(int x) {
	cout << "? " << x << endl;
	int y;
	cin >> y;
	if (y == 0) exit(0);
	return y;
}

inline void FindCyc(int x) {
	vector <int> cyc;
	int y = Query(x);
	while (!vis[y]) {
		cyc.push_back(y);
		vis[y] = 1;
		y = Query(x);
	}
	cyc.push_back(y);
	int siz = cyc.size();
	//for (int i = 0;i < siz;i++) cout << cyc[i] << " "; cout << endl;
	for (int i = 0;i < siz - 1;i++) p[cyc[i]] = cyc[i + 1];
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1;i <= n;i++) vis[i] = 0;
		for (int i = 1;i <= n;i++) {
			if (!vis[i]) FindCyc(i);
		}
		cout << "! ";
		for (int i = 1;i <= n;i++) cout << p[i] << " ";
		cout << endl;
	}
	#ifdef CFA_44
	while (1);
	#endif
	return 0;
}