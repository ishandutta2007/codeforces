// Problem: CF1442A Extreme Subtraction
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1442A
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
const int N = 3e4+5;

int T, n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		int L = a[1], R = 0, ok = 1;
		rep(i, 2, n) {
			chkmin(L, a[i]-R);
			if(L < 0) {ok = 0; break;}
			a[i] -= L;
			R = a[i];
		}
		puts(ok?"YES":"NO");
	}
	return 0;
}