#include <bits/stdc++.h>

using namespace std;

int q(int f, int x, int y) {
	if (f) printf("and %d %d\n", x, y);
	else printf("or %d %d\n", x, y);
	fflush(stdout);
	int d;
	scanf("%d", &d);
	return d;
}

int s[20000];

int main() {
//	freopen("in.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	int a = q(0, 1, 2), b = q(1, 1, 2);
	int c = q(0, 2, 3), d = q(1, 2, 3);
	int e = q(0, 1, 3), f = q(1, 1, 3);
	for (int i = 0; i < 31; ++i) {
		int x = -1, y = -1, z = -1;
		if (!(a & 1 << i)) x = y = 0;
		if (!(c & 1 << i)) y = z = 0;
		if (!(e & 1 << i)) z = x = 0;
		if (b & 1 << i) x = y = 1;
		if (d & 1 << i) y = z = 1;
		if (f & 1 << i) z = x = 1;
		if (a & 1 << i && !(b & 1 << i)) {
			if (x == 0) y = 1;
			if (x == 1) y = 0;
			if (y == 0) x = 1;
			if (y == 1) x = 0;
		}
		if (c & 1 << i && !(d & 1 << i)) {
			if (y == 0) z = 1;
			if (y == 1) z = 0;
			if (z == 0) y = 1;
			if (z == 1) y = 0;
		}
		if (e & 1 << i && !(f & 1 << i)) {
			if (x == 0) z = 1;
			if (x == 1) z = 0;
			if (z == 0) x = 1;
			if (z == 1) x = 0;
		}
		s[1] |= x << i, s[2] |= y << i, s[3] |= z << i;
	}
//	cout<<s[1]<<' '<<s[2]<<' '<<s[3]<<endl;
	for (int i = 4; i <= n; ++i) {
		a = q(0, 1, i), b = q(1, 1, i);
		for (int j = 0; j < 31; ++j) {
			if (!(s[1] & 1 << j)) {
				if (!(a & 1 << j)) s[i] |= 0 << j;
				else s[i] |= 1 << j;
			} else {
				if (b & 1 << j) s[i] |= 1 << j;
				else s[i] |= 0 << j;
			}
		}
	}
//	for(int i=1;i<=n;++i)cout<<s[i]<<' ';
//	cout<<endl;
	sort(s + 1, s + n + 1);
//	for(int i=1;i<=n;++i)cout<<s[i]<<' ';
//	cout<<endl;
	printf("finish %d\n", s[m]);
	fflush(stdout);
	return 0;
}