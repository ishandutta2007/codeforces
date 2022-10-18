#include <stdio.h>
#include <string.h>
char inp[110];
char mat[] = "CODEFORCES";
int main() {
	scanf("%s", inp);
	int n= strlen(inp), m = strlen(mat);
	int ans = 0;
	if (n >= m) {
		for (int i=0; i<=m; i++) {
			int flag = 1;
			for (int j=0; j<i; j++) {
				if (mat[j] != inp[j]) flag = 0;
			}
			for (int j=i; j<m; j++) {
				if (mat[j] != inp[n-m+j]) flag = 0;
			}
			if (flag) ans = 1;
		}
	}
	puts(ans ? "YES" : "NO");
	return 0;
}