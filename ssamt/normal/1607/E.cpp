#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &m);
		char s[1000001];
		scanf("%s", s);
		int x = 0, y = 0;
		int left = 0, right = 0, up = 0, down = 0;
		for(i=0; s[i]; i++) {
			if(s[i] == 'L') {
				x--;
				left = min(left, x);
				if(right-left+1 > m) {
					left++;
					break;
				}
			} else if(s[i] == 'R') {
				x++;
				right = max(right, x);
				if(right-left+1 > m) {
					right--;
					break;
				}
			} else if(s[i] == 'D') {
				y++;
				down = max(down, y);
				if(down-up+1 > n) {
					down--;
					break;
				}
			} else {
				y--;
				up = min(up, y);
				if(down-up+1 > n) {
					up++;
					break;
				}
			}
		}
		printf("%d %d\n", -up+1, -left+1);
	}
}