// LUOGU_RID: 96193284
// Problem: CF545C Woodcutters
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF545C
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

int n, p[N], h[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d%d", &p[i], &h[i]);
	if(n <= 2) return printf("%d\n", n)&0;
	int ans = 2;
	rep(i, 2, n-1) {
		if(p[i] - p[i-1] > h[i]) ++ans;
		else if(p[i+1] - p[i] > h[i]) ++ans, p[i] += h[i];
	}
	printf("%d\n", ans);
	return 0;
}