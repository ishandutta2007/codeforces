// LUOGU_RID: 95930245
// Problem: CF1760C Advantage
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1760C
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
const int N = 2e5+5;

int T, n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		int mx = 0, nx = 0;
		rep(i, 1, n) {
			if(a[i] > mx) {
				nx = mx;
				mx = a[i];
			}
			else if(a[i] > nx) nx = a[i];
		}
		rep(i, 1, n) printf("%d%c", a[i] - (a[i] == mx ? nx : mx), " \n"[i==n]);
	}
	return 0;
}