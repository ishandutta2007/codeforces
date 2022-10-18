#include <stdio.h>
#include <string.h>
int n;
char inp[110][110];
char ls[210][210];
int inb(int x) {
	return x >= 0 && x < n;
}
int main() {
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%s", inp[i]);
	memset(ls, 'x', sizeof(ls));
	for (int di=-n+1; di<n; di++) {
		for (int dj=-n+1; dj <n; dj++) {
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					if (inp[i][j] == 'o')
					if (inb(i+di) && inb(j+dj) && inp[i+di][j+dj] == '.') ls[di+n-1][dj+n-1] = '.';
				}
			}
		}
	}
	for (int di=-n+1; di<n; di++) {
		for (int dj=-n+1; dj <n; dj++) {
			if (ls[di+n-1][dj+n-1] == 'x') {
				for (int i=0; i<n; i++) {
					for (int j=0; j<n; j++) {
						if (inp[i][j] == 'o') {
					if (inb(i+di) && inb(j+dj) && inp[i+di][j+dj] == 'x') inp[i+di][j+dj] = '.';
						}
					}
				}
			}
		}
	}
	int ans = 1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (inp[i][j] == 'x') ans = 0;
		}
	}
	for (int i=0; i<2*n-1; i++) ls[i][2*n-1] = 0;
	ls[n-1][n-1] = 'o';
	if (ans) {
		puts("YES");
		for (int i=0; i<2*n-1; i++) puts(ls[i]);
	}else puts("NO");
	return 0;
}