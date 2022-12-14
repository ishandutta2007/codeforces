#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

void write(int x) {
	if (x < 0) putchar('-'), write(-x);
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

char s[100];

int n, num[10];

int main() {
	n = read();
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i ++) {
		if (s[i] == '0' || s[i] == '1') continue;
		if (s[i] == '2') num[2] ++;
		else if (s[i] == '3') num[3] ++;
		else if (s[i] == '4') num[2] += 2, num[3] ++;
		else if (s[i] == '5') num[5] ++;
		else if (s[i] == '6') num[5] ++, num[3] ++;
		else if (s[i] == '7') num[7] ++;
		else if (s[i] == '8') num[7] ++, num[2] += 3;
		else num[7] ++, num[3] += 2, num[2] ++;
	}
	for (int i = 7; i > 1; i --) {
		if (num[i]) for (int j = 0; j < num[i]; j ++) write(i);
	}
	return 0;
}