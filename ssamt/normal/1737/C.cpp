#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d", &n);
		vector<int> r(3), c(3);
		for(i=0; i<3; i++) {
			scanf("%d %d", &r[i], &c[i]);
		}
		int x, y;
		scanf("%d %d", &x, &y);
		int cx, cy;
		for(i=0; i<3; i++) {
			if(r[i] == r[(i+1)%3]) {
				cx = r[i];
			}
			if(c[i] == c[(i+1)%3]) {
				cy = c[i];
			}
		}
		if((cx == 1 || cx == n) && (cy == 1 || cy == n)) {
			if(x == cx || y == cy) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		} else {
			int check = 0;
			for(i=0; i<3; i++) {
				if(abs(x-r[i])%2 == 0 && abs(y-c[i])%2 == 0) {
					check = 1;
				}
			}
			printf(check?"YES\n":"NO\n");
		}
	}
}