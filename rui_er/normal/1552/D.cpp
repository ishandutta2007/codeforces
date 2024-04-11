// Problem: CF1552D Array Differentiation
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1552D
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
const int N = 10;

int T, n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 0, n-1) scanf("%d", &a[i]);
		int ok = 0;
		rep(S1, 1, (1<<n)-1) {
			rep(S2, 0, (1<<n)-1) {
				int sum = 0;
				rep(i, 0, n-1) {
					if((S1 >> i) & 1) {
						if((S2 >> i) & 1) sum += a[i];
						else sum -= a[i];
					}
				}
				if(!sum) {
					ok = 1;
					break;
				}
			}
			if(ok) break;
		}
		puts(ok?"YES":"NO");
	}
	return 0;
}