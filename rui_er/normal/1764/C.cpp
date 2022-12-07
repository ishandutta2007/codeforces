// LUOGU_RID: 96019824
// Problem: Doremy's City Construction
// Contest: Codeforces
// URL: https://m2.codeforces.com/contest/1764/problem/C
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
const int N = 2e5+5, K = 1e6+5;

int T, n, a[N], cnt[K];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		if(*min_element(a+1, a+1+n) == *max_element(a+1, a+1+n)) {
			printf("%d\n", n/2);
			continue;
		}
		rep(i, 1, n) ++cnt[a[i]];
		sort(a+1, a+1+n);
		int now = 0; ll ans = 0;
		for(int i = 1; i <= n; i += cnt[a[i]]) {
			chkmax(ans, 1LL * now * (n - now));
			now += cnt[a[i]];
		}
		printf("%lld\n", ans);
		rep(i, 1, n) --cnt[a[i]];
	}
	return 0;
}