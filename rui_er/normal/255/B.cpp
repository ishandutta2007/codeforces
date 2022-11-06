// Problem: CF255B Code Parsing
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF255B
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
const int N = 1e6+5;

int n, x, y;
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%s", s+1);
	n = strlen(s+1);
	rep(i, 1, n) {
		if(s[i] == 'x') ++x;
		else ++y;
	}
	if(x >= y) rep(i, y+1, x) putchar('x');
	else rep(i, x+1, y) putchar('y');
	return 0;
}