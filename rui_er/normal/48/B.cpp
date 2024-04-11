// Problem: CF48B Land Lot
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF48B
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 55;

int n, m, t[N][N], s[N][N], a, b;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int S(int u, int l, int d, int r) {return s[d][r] - s[u-1][r] - s[d][l-1] + s[u-1][l-1];}
int calc(int a, int b) {
	int ans = a * b;
	rep(i, a, n) rep(j, b, m) chkmin(ans, S(i-a+1, j-b+1, i, j));
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) rep(j, 1, m) scanf("%d", &t[i][j]);
	scanf("%d%d", &a, &b);
	rep(i, 1, n) rep(j, 1, m) s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + t[i][j];
	printf("%d\n", min(calc(a, b), calc(b, a)));
	return 0;
}