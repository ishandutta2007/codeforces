// LUOGU_RID: 96164128
// Problem: CF1209A Paint the Numbers
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1209A
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
const int N = 105;

int n, a[N], vis[N], ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	rep(i, 1, n) {
		if(!vis[i]) {
			++ans;
			rep(j, i, n) if(!(a[j] % a[i])) vis[j] = 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}