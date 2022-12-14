#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

const int inf = 1e9 + 7;

int n, x, y, X, Y, A1 = inf, A2 = -inf, A3 = inf, A4 = -inf, A5 = inf, A6 = -inf, A7 = inf, A8 = -inf;

char str[5], B1, B2, B3, B4, B5, B6, B7, B8;

int main() {
	n = read(), x = read(), y = read();
	for (int i=1; i<=n; i++) {
		scanf("%s",str);
		X = read(), Y = read();
		if (X==x) {
			if (Y>y && Y<A1) A1=Y,B1=str[0];
			if (Y<y && Y>A2) A2=Y,B2=str[0];
		}
		if (Y==y) {
			if (X>x && X<A3) A3=X,B3=str[0];
			if (X<x && X>A4) A4=X,B4=str[0];
		}
		if (X+Y==x+y) {
			if (X>x && X<A5) A5=X,B5=str[0];
			if (X<x && X>A6) A6=X,B6=str[0];
		}
		if (X-Y==x-y) {
			if (X>x && X<A7) A7=X,B7=str[0];
			if (X<x && X>A8) A8=X,B8=str[0];
		}
	}
	if (B1=='Q' || B2=='Q' ||B3=='Q' ||B4=='Q' ||B5=='Q' ||B6=='Q' ||B7=='Q' || B8=='Q' ) puts("YES");
	else if (B1=='R' || B2=='R' || B3=='R' || B4=='R') puts("YES");
	else if (B5=='B' || B6=='B' || B7=='B' || B8=='B') puts("YES");
	else puts("NO");
	return 0;
}