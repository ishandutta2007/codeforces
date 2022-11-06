// Problem: C. Sum of Substrings
// Contest: Codeforces - CodeCraft-22 and Codeforces Round #795 (Div. 2)
// URL: https://codeforces.com/contest/1691/problem/C
// Memory Limit: 256 MB
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
const int N = 1e5+5;

int T, n, k;
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d%s", &n, &k, s+1);
		int cnt1 = 0, fst = 0, lst = 0;
		rep(i, 1, n) {
			if(s[i] == '1') {
				++cnt1;
				if(!fst) fst = i;
				lst = i;
			}
		}
		int ans = 0;
		if(cnt1 && k >= n - lst) {
			--cnt1;
			++ans;
			k -= n - lst;
		}
		if(cnt1 && k >= fst - 1) {
			--cnt1;
			ans += 10;
			k -= fst - 1;
		}
		ans += 11 * cnt1;
		printf("%d\n", ans);
	}
	return 0;
}