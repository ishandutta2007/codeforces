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

bool isprime(int x){
	for (int i = 2; i * i <= x; i ++) {
		if (x % i == 0) return 0; 
	}
	return 1;
}

int n;

int main() {
	n = read();
	if (isprime(n)) puts("1");
	else {
		if (n % 2 == 0) puts("2");
		else if (isprime(n)) puts("1");
		else if ((isprime(n - 2))) puts("2");
		else puts("3");
	}
	return 0;
}