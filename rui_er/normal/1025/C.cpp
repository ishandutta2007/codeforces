// Problem: CF1025C Plasticine zebra
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1025C
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
const int N = 2e5+5;

int n;
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%s", s);
	n = strlen(s);
	rep(i, n, n+n-1) s[i] = s[i-n];
	int now = 1, ans = 0;
	rep(i, 1, n+n-1) {
		if(s[i] == s[i-1]) now = 1;
		else ++now;
		chkmax(ans, now);
	}
	chkmin(ans, n);
	printf("%d\n", ans);
	return 0;
}