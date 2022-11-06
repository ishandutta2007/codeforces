// Problem: CF222B Cosmic Tables
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF222B
// Memory Limit: 250 MB
// Time Limit: 3000 ms
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
const int N = 1e3+5;

int n, m, k, a[N][N], r[N], c[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, n) rep(j, 1, m) scanf("%d", &a[i][j]);
	rep(i, 1, n) r[i] = i;
	rep(j, 1, m) c[j] = j;
	while(k--) {
		char op[2];
		int x, y;
		scanf("%s%d%d", op, &x, &y);
		if(op[0] == 'r') swap(r[x], r[y]);
		else if(op[0] == 'c') swap(c[x], c[y]);
		else printf("%d\n", a[r[x]][c[y]]);
	}
	return 0;
}