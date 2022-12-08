#include<bits/stdc++.h>
#define int long long
using namespace std;
 
int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}
 
const int N = 105;
int n, a[N], f[N][N][N]; 
char s[N];
 
void qmax(int &x, int y) { x = x > y? x : y; }
 
main() {
	n = get(), scanf("%s", s + 1);
	for(int i = 1; i <= n; i++) a[i] = get();
	for(int i = n; i >= 1; i--)
		for(int j = i; j <= n; j++) {
			for(int k = 0; k <= n; k++)
				for(int l = i; l < j; l++)
					if(s[l] == s[j])
						qmax(f[i][j][k], f[l + 1][j - 1][0] + f[i][l][k + 1]);
			for(int k = 0; k <= n; k++) qmax(f[i][j][k], f[i][j - 1][0] + a[k + 1]);
		}
	cout << f[1][n][0];
	return 0;
}