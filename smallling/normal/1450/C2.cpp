#include <bits/stdc++.h>

using namespace std;

int n, cnt[4][2];
char a[330][330];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%s", a[i] + 1);
		memset(cnt, 0, sizeof(cnt));
		int tot = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(a[i][j] != '.') {
					if(a[i][j] == 'X')cnt[(i + j) % 3][0]++;
					else cnt[(i + j) % 3][1]++;
					tot++;
				}
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				if(i != j && cnt[i][0] + cnt[j][1] <= tot / 3) {
					for(int x = 1; x <= n; x++) {
						for(int y = 1; y <= n; y++) {
							if((x + y) % 3 == i && a[x][y] == 'X')putchar('O');
							else if((x + y) % 3 == j && a[x][y] == 'O')putchar('X');
							else putchar(a[x][y]);
						}
						puts("");
					}
					goto la;
				}
		la:;
	}
}