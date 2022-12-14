#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 1010

char text[N], s[N][N];

int main() {
//	freopen("b.in", "r", stdin);
	int n = 0;
	while (gets(text) > 0) {
		strcpy(s[n++], text);
	}
	int mx = 0, len;
	for (int i = 0; i < n; i ++) len = strlen(s[i]), mx = max(mx, len);
	for (int i = 0; i <= mx + 1; i ++) printf("*"); puts("");
	int cnt = 0;
	for (int i = 0; i < n; i ++) {
		printf("*");
		len = strlen(s[i]);
		int a = (mx - len) / 2, b = a;
		if ((mx - len) & 1) {
			if (cnt) a ++;
			else b ++;
			cnt = 1 - cnt;
		}
		for (int j = 0; j < a; j ++) printf(" ");
		printf("%s", s[i]);
		for (int j = 0; j < b; j ++) printf(" ");
		printf("*\n");
	}
	for (int i = 0; i <= mx + 1; i ++) printf("*"); puts("");
	return 0;
}