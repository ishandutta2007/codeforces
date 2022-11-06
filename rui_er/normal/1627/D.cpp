// LUOGU_RID: 92000378
// Problem: CF1627D Not Adding
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1627D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
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
const int N = 1e6+5, K = 1e6;

int n, a[N], buc[N], ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		++buc[a[i]];
	}
	per(d, K, 1) {
		if(buc[d]) continue;
		int gcd = 0;
		for(int i = d; i <= K; i += d) if(buc[i]) gcd = __gcd(gcd, i);
		if(gcd == d) ++ans, buc[d] = 1;
	}
	printf("%d\n", ans);
	return 0;
}