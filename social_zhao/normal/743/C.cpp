#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

int main() {
	int n = get();
	if(n == 1) return printf("-1\n"), 0;
	printf("%d %d %d\n", n, n + 1, n * (n + 1));
	return 0;
}