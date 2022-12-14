#include <bits/stdc++.h>

using namespace std;

int read(){
	int x = 0, f = 1, c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

void write(int x) {
	if (x < 0) puts("-"), write(-x);
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

char s[1000010];

int main() {
	scanf("%s", s);
	printf("%s",s);
	int l = strlen(s);
	for (int i = l - 1; i >= 0; i --) putchar(s[i]);
	return 0;
}