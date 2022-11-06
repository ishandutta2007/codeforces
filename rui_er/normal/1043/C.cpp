// Problem: CF1043C Smallest Word
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1043C
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e3+5;

int n;
char s[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%s", s+1);
	n = strlen(s+1);
	s[n+1] = 'b';
	rep(i, 1, n) {
		putchar("01"[s[i]!=s[i+1]]);
		putchar(' ');
	}
	return 0;
}