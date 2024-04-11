// LUOGU_RID: 96019813
// Problem: Doremy's Perfect Math Class
// Contest: Codeforces
// URL: https://m2.codeforces.com/contest/1764/problem/B
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
const int N = 1e5+5;

int T, n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		int gcd = 0;
		rep(i, 1, n) gcd = __gcd(gcd, a[i]);
		printf("%d\n", (*max_element(a+1, a+1+n))/gcd);
	}
	return 0;
}