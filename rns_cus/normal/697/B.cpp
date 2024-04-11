#include <bits/stdc++.h>
using namespace std;
#define N 1001001

char s[N], a[N], d[N], prt[N];
int al, dl, b;

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%s", s);
	int len = strlen(s);
	bool com = 0, e = 0;
	for (int i = 0; i < len; i ++) {
		if (!com) {
			if (s[i] != '.') a[al++] = s[i];
			else a[al] = 0, com = 1;
		}
		else if (!e) {
			if (s[i] != 'e') d[dl++] = s[i];
			else d[dl] = 0, e = 1;
		}
		else b = b * 10 + s[i] - '0';
	}
	if (!b) {
		if (strcmp(d, "0") == 0) {
			printf("%s\n", a); return 0;
		}
		printf("%s.%s\n", a, d); return 0;
	}
	if (b < dl) {
		strcpy(prt, a);
		strcat(prt, d);
		int len = al + b;
		prt[len] = 0;
		int st = -1;
		for (int i = 0; i < len; i ++) {
			if (prt[i] != '0' || i == len - 1) {
				st = i; break;
			}
		}
		for (int i = st; i < len; i ++) printf("%c", prt[i]);
		printf(".");
		for (int i = b; i < dl; i ++) printf("%c", d[i]);
		puts("");
	}
	else {
		strcpy(prt, a);
		strcat(prt, d);
		int len = al + dl;
		for (int i = 0; i < b - dl; i ++) prt[len++] = '0';
		prt[len] = 0;
		int st = -1;
		for (int i = 0; i < len; i ++) {
			if (prt[i] != '0' || i == len - 1) {
				st = i; break;
			}
		}
		for (int i = st; i < len; i ++) printf("%c", prt[i]);
		puts("");
	}
	return 0;
}