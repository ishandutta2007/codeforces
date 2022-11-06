// Problem: CF1634D Finding Zero
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1634D
// Memory Limit: 250 MB
// Time Limit: 1000 ms
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

int T, n;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int ask(int x, int y, int z) {
	printf("? %d %d %d\n", x, y, z);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}
void give(int x, int y) {
	printf("! %d %d\n", x, y);
	fflush(stdout);
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		int a123 = ask(1, 2, 3);
		int a124 = ask(1, 2, 4);
		int a134 = ask(1, 3, 4);
		int a234 = ask(2, 3, 4);
		int mx = max(a123, max(a124, max(a134, a234)));
		int x = 0, y = 0, z = 0;
		if(a123 == mx) {
			if(a124 == mx) x = 1, y = 2;
			else if(a134 == mx) x = 1, y = 3;
			else x = 2, y = 3;
			z = 4;
		}
		else if(a124 == mx) {
			if(a134 == mx) x = 1, y = 4;
			else x = 2, y = 4;
			z = 3;
		}
		else x = 3, y = 4, z = 2;
		rep(i, 5, n) {
			int d1 = ask(x, z, i);
			int d2 = ask(y, z, i);
			if(d1 >= d2 && d1 > mx) y = i, mx = d1;
			if(d2 >= d1 && d2 > mx) x = i, mx = d2;
		}
		give(x, y);
	}
	return 0;
}