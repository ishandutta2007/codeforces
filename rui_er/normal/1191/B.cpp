// LUOGU_RID: 96612477
// Problem: CF1191B Tokitsukaze and Mahjong
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1191B
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

int a, b, c, cnt[3][9], ans = 3;
char x, y, z;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%c %d%c %d%c", &a, &x, &b, &y, &c, &z);
	auto f = [](char x) {
		if(x == 's') return 0;
		if(x == 'm') return 1;
		return 2;
	};
	++cnt[f(x)][a-1];
	++cnt[f(y)][b-1];
	++cnt[f(z)][c-1];
	rep(i, 0, 2) {
		rep(j, 0, 8) {
			chkmin(ans, 3 - cnt[i][j]);
			if(j <= 6) chkmin(ans, (!cnt[i][j])+(!cnt[i][j+1])+(!cnt[i][j+2]));
		}
	}
	printf("%d\n", ans);
	return 0;
}