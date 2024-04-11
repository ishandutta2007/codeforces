// LUOGU_RID: 90659780
// Problem: B. Rebellion
// Contest: Codeforces - Codeforces Global Round 23
// URL: https://codeforces.com/contest/1746/problem/B
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

int T, n, a[N], zero[N], one[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) {
			zero[i] = zero[i-1];
			one[i] = one[i-1];
			if(a[i]) ++one[i];
			else ++zero[i];
		}
		int ans = n;
		rep(i, 0, n) if(one[i] >= zero[n] - zero[i]) chkmin(ans, one[i]);
		printf("%d\n", ans);
	}
	return 0;
}