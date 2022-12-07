// LUOGU_RID: 96192978
// Problem: CF401C Team
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF401C
// Memory Limit: 250 MB
// Time Limit: 1000 ms
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

int n, m;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &m);
	if(m + 1 < n || 2 * n + 2 < m) puts("-1");
	else {
		if(m == 2 * n + 2) putchar('1'), --m;
		if(m == 2 * n + 1) putchar('1'), --m;
		while(n--) {
			putchar('0');
			if(m) {
				if(2 * n + 2 <= m) putchar('1'), --m;
				putchar('1'), --m;
			}
		}
	}
	return 0;
}