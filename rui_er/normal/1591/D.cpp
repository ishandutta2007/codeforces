// Problem: CF1591D Yet Another Sorting Problem
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1591D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 5e5+5;

int T, n, a[N], buc[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct BIT {
	int c[N];
	int lowbit(int x) {return x & (-x);}
	void add(int x, int k) {for(;x<=n;x+=lowbit(x)) c[x] += k;}
	int ask(int x) {int k = 0; for(;x;x-=lowbit(x)) k += c[x]; return k;}
}bit;

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		int same = 0;
		rep(i, 1, n) {
			same |= buc[a[i]];
			buc[a[i]] = 1;
		}
		if(same) puts("YES");
		else {
			int cnt = 0;
			rep(i, 1, n) {
				cnt ^= ((i - 1) - bit.ask(a[i])) & 1;
				bit.add(a[i], 1);
			}
			puts(cnt?"NO":"YES");
		}
		rep(i, 1, n) buc[i] = bit.c[i] = 0;
	}
	return 0;
}