// LUOGU_RID: 91301893
// Problem: A. Bestie
// Contest: Codeforces - Codeforces Round #830 (Div. 2)
// URL: https://codeforc.es/contest/1732/problem/A
// Memory Limit: 256 MB
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
const int N = 25;

int T, n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		int gcd = 0;
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) gcd = __gcd(gcd, a[i]);
		if(gcd == 1) puts("0");
		else if(__gcd(gcd, __gcd(a[n], n)) == 1) puts("1");
		else if(__gcd(gcd, __gcd(a[n-1], n-1)) == 1) puts("2");
		else puts("3");
	}
	return 0;
}