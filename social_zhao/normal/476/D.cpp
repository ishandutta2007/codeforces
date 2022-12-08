#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

int n, k;

int main() {
	n = get(), k = get();
	printf("%d\n", k * (6 * n - 1));
	for(int i = 1; i <= n; i++) 
		printf("%d %d %d %d\n", k * (6 * i - 5), k * (6 * i - 4), k * (6 * i - 3), k * (6 * i - 1));
	return 0;
}