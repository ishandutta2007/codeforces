//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T, x, y, z; 

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &x, &y, &z);
		int m = max(max(x, y), z);
		int p = (x == m), q = (y == m), r = (z == m);
		if(p + q + r >= 2) {
			puts("YES");
			int a, b, c;
			a = min(x, y);
			b = min(x, z);
			c = min(y, z);
			printf("%d %d %d\n", a, b, c);
		}
		else {
			puts("NO");
		}
	}
	return 0;
}