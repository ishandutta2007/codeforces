#include<bits/stdc++.h>
using namespace std;
 
int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}
 
const int N = 505;
int n, m, a[N][N];
char s[N];
 
int main() {
	n = get(), m = get();
	for(int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		for(int j = 1; j <= m; j++) a[i][j] = s[j] == 'W'? 0 : 1;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] = a[i][j] ^ a[i][j + 1] ^ a[i + 1][j] ^ a[i + 1][j + 1];
	int ans = 0, flag = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			ans += a[i][j], flag |= (i < n && j < m && a[i][j] && a[n][j] && a[i][m] && a[n][m]);
	cout << ans - flag;
	return 0;
}