// Problem: CF1349B Orac and Medians
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1349B
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
const int N = 1e5+5;

int T, n, k, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &k);
		int equal = 0;
		rep(i, 1, n) {
			scanf("%d", &a[i]);
			a[i] = a[i] > k ? 1 : a[i] < k ? -1 : 0;
			equal |= !a[i];
		}
		if(!equal) puts("no");
		else if(n == 1) puts("yes");
		else {
			int ok = 0;
			rep(i, 1, n-1) {
				ok |= a[i] >= 0 && a[i+1] >= 0;
				if(i < n - 1) ok |= a[i] >= 0 && a[i+2] >= 0;
			}
			puts(ok?"yes":"no");
		}
	}
	return 0;
}