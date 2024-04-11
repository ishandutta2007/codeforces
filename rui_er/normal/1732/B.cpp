// LUOGU_RID: 91301917
// Problem: B. Ugu
// Contest: Codeforces - Codeforces Round #830 (Div. 2)
// URL: https://codeforc.es/contest/1732/problem/B
// Memory Limit: 256 MB
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

int T, n;
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%s", &n, s+1);
		int ans = 0;
		rep(i, 1, n-1) ans += s[i] != s[i+1];
		if(s[1] == '0') --ans;
		printf("%d\n", max(ans, 0));
	}
	return 0;
}