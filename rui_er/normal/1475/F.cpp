// Problem: CF1475F Unusual Matrix
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1475F
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
const int N = 1e3+5;

int T, n, a[N][N];
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) {
			scanf("%s", s+1);
			rep(j, 1, n) a[i][j] ^= s[j] ^ 48;
		}
		rep(i, 1, n) {
			scanf("%s", s+1);
			rep(j, 1, n) a[i][j] ^= s[j] ^ 48;
		}
		rep(j, 1, n) if(a[1][j]) rep(i, 1, n) a[i][j] ^= 1;
		int ok = 1;
		rep(i, 1, n) {
			rep(j, 2, n) {
				if(a[i][j] != a[i][j-1]) {
					ok = 0;
					break;
				}
			}
			if(!ok) break;
		}
		puts(ok?"YES":"NO");
		rep(i, 1, n) rep(j, 1, n) a[i][j] = 0;
	}
	return 0;
}