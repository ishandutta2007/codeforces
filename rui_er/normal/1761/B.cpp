// LUOGU_RID: 95055892
// Problem: Elimination of a Ring
// Contest: Codeforces
// URL: https://m2.codeforces.com/contest/1761/problem/B
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
const int N = 105;

int T, n, a[N], L[N], R[N], ok[N], cnt[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		if(n <= 3) {printf("%d\n", n); continue;}
		int ans = 0;
		auto inc = [&](int i) {return i % n + 1;};
		auto dec = [&](int i) {return (i + n - 2) % n + 1;};
		rep(i, 1, n) L[i] = dec(i), R[i] = inc(i), ok[i] = 1, ++cnt[a[i]];
		while(true) {
			int c = 0;
			rep(i, 1, n) {
				if(ok[i] && cnt[a[i]] >= 2 && a[L[i]] != a[R[i]]) {
					// printf("ERASE 1 %d\n", i);
					R[L[i]] = R[i];
					L[R[i]] = L[i];
					ok[i] = 0;
					--cnt[a[i]];
					++ans;
					c = 1;
				}
			}
			if(!c) break;
		}
		while(true) {
			int c = 0;
			rep(i, 1, n) {
				if(ok[i] && cnt[a[i]] >= 2 && a[L[i]] == a[R[i]]) {
					// printf("ERASE 2 %d\n", i);
					R[L[i]] = R[R[i]];
					L[R[R[i]]] = L[i];
					ok[i] = ok[R[i]] = 0;
					--cnt[a[i]]; --cnt[a[R[i]]];
					++ans;
					c = 1;
				}
			}
			if(!c) break;
		}
		ans += accumulate(ok+1, ok+1+n, 0);
		printf("%d\n", ans);
		rep(i, 1, n) a[i] = L[i] = R[i] = ok[i] = cnt[i] = 0;
	}
	return 0;
}