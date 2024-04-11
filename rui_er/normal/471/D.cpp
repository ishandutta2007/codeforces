// LUOGU_RID: 96369468
// Problem: CF471D MUH and Cube Walls
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF471D
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

int n, m, a[N], b[N], s[N<<1], nxt[N<<1];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, m) scanf("%d", &b[i]);
	if(m == 1) return printf("%d\n", n)&0;
	rep(i, 1, m-1) s[i] = b[i+1] - b[i];
	s[m] = 2147483647;
	rep(i, 1, n-1) s[i+m] = a[i+1] - a[i];
	int k = n + m - 1, ans = 0;
	rep(i, 2, k) {
		int j = nxt[i-1];
		while(j && s[j+1] != s[i]) j = nxt[j];
		if(s[j+1] == s[i]) ++j;
		nxt[i] = j;
		if(nxt[i] == m - 1) ++ans;
	}
	printf("%d\n", ans);
	return 0;
}