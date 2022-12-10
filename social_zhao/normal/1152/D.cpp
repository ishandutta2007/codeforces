#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1005, P = 1e9 + 7;
int n, ans;
int C[N][N];

int main() {
	n = get();
	for(int i = 1; i <= n; i++) C[i][0] = 1, (i & 1)? ans = (ans + 1) % P : 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j] + C[i][j - 1]) % P, ((i + j) & 1)? ans = (ans + C[i][j]) % P : 1;
	printf("%d\n", ans);
	return 0;
}