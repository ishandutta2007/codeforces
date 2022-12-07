// LUOGU_RID: 96164517
// Problem: CF492B Vanya and Lanterns
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF492B
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
const int N = 1e3+5;

int n, L, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &L);
	rep(i, 1, n) scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	double ans = 0.0;
	chkmax(ans, a[1]-0.0);
	chkmax(ans, 1.0*L-a[n]);
	rep(i, 1, n-1) chkmax(ans, (a[i+1]-a[i])*0.5);
	printf("%.10f\n", ans);
	return 0;
}