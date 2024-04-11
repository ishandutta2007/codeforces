// LUOGU_RID: 93113992
// Problem: CF1545A AquaMoon and Strange Sort
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1545A
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
const int N = 1e5+5;

int T, n, a[N], bucO[N], bucE[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		rep(i, 1, n) {
			scanf("%d", &a[i]);
			if(i & 1) ++bucO[a[i]];
			else ++bucE[a[i]];
		}
		sort(a+1, a+1+n);
		rep(i, 1, n) {
			if(i & 1) --bucO[a[i]];
			else --bucE[a[i]];
		}
		int ok = 1;
		rep(i, 1, n) ok &= !bucO[a[i]] && !bucE[a[i]];
		puts(ok ? "YES" : "NO");
		rep(i, 1, n) bucO[a[i]] = bucE[a[i]] = 0;
	}
	return 0;
}