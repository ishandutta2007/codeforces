// Problem: CF710C Magic Odd Square
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF710C
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 49;

int n, a[N][N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int inc(int x) {return (x + 1) % n;}
int dec(int x) {return (x + n - 1) % n;}

int main() {
	scanf("%d", &n);
	int x = 0, y = n / 2;
	rep(i, 1, n*n) {
		a[x][y] = i;
		if(a[dec(x)][inc(y)]) x = inc(x);
		else x = dec(x), y = inc(y);
	}
	rep(i, 0, n-1) rep(j, 0, n-1) printf("%d%c", a[i][j], " \n"[j==n-1]);
	return 0;
}