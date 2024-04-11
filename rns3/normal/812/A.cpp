#include <bits/stdc++.h>
using namespace std;

int vis[4], car[4], a, b, c, d;

int main() {
	for (int i = 0; i < 4; i ++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		vis[i] += d;
		if (a || b || c) car[i] = 1;
		car[(i+2)%4] += b;
		car[(i+1)%4] += c;
		car[(i+3)%4] += a;
	}
	for (int i = 0; i < 4; i ++) if (car[i] && vis[i]) {
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}