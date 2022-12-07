// LUOGU_RID: 96165386
// Problem: CF546B Soldier and Badges
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF546B
// Memory Limit: 250 MB
// Time Limit: 3000 ms
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
const int N = 3e3+5;

int n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	int now = 0, ans = 0;
	rep(i, 1, n) {
		if(a[i] < now) {
			ans += now - a[i];
			++now;
		}
		else now = a[i] + 1;
	}
	printf("%d\n", ans);
	return 0;
}