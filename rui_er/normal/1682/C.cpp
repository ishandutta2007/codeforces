// Problem: CF1682C LIS or Reverse LIS?
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1682C
// Memory Limit: 250 MB
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
const int N = 2e5+5;

int T, n, a[N];
map<int, int> buc;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		buc.clear();
		rep(i, 1, n) ++buc[a[i]];
		int cnt1 = 0, cnt2 = 0;
		for(auto it : buc) {
			if(it.second >= 2) ++cnt2;
			else ++cnt1;
		}
		printf("%d\n", cnt2+(cnt1+1)/2);
	}
	return 0;
}