#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 55;
int n;
char s[N], ans[N][N];
int bin[N], top;

void solve() {
	n = get();
	scanf("%s", s + 1);
	memset(ans, 0, sizeof(ans));
	for(int i = 1; i <= n; i++) ans[i][i] = 'X';
	top = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '2') bin[++top] = i;
	}
	if(top && top <= 2) { printf("NO\n"); return; }
	bin[++top] = bin[1];
	for(int i = 1; i < top; i++) {
		int u = bin[i], v = bin[i + 1];
		ans[u][v] = '+', ans[v][u] = '-';
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(!ans[i][j]) ans[i][j] = '=';
	printf("YES\n");
	for(int i = 1; i <= n; i++) printf("%s\n", ans[i] + 1);
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}