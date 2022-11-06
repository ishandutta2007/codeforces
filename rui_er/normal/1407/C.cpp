//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;

int n, a[N], ma = 1;

int ask(int x, int y) {
	int _;
	printf("? %d %d\n", x, y);
	fflush(stdout);
	scanf("%d", &_);
	return _;
}

int main() {
	scanf("%d", &n);
	for(int i=2;i<=n;i++) {
		int _1 = ask(ma, i);
		int _2 = ask(i, ma);
		if(_1 > _2) {
			a[ma] = _1;
			ma = i;
		}
		else a[i] = _2;
	}
	a[ma] = n;
	putchar('!');
	for(int i=1;i<=n;i++) printf(" %d", a[i]);
	return 0;
}