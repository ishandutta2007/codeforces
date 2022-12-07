// LUOGU_RID: 96209093
// Problem: CF1722G Even-Odd XOR
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1722G
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

int T, n;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		int now = 0;
		rep(i, 1, n-3) printf("%d ", i), now ^= i;
		printf("%d ", 1 << 29), now ^= 1 << 29;
		printf("%d ", 1 << 30), now ^= 1 << 30;
		printf("%d\n", now);
	}
	return 0;
}