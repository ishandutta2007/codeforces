#include <bits/stdc++.h>

using namespace std;

int read() {
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

long long f[200];

int main() {
	int i;
	f[1]=1, f[2]=3, f[3]=5;
	for(i=4; i<92; i++) f[i]=f[i-1]+f[i-2];
	long long  n;
	scanf("%I64d",&n);
	for(i=0; i<92; i++) {
		if(n<f[i]) break;
	}
	write(i - 1);
	return 0;
}