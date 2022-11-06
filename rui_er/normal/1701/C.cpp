// Problem: C. Schedule Management
// Contest: Codeforces - Educational Codeforces Round 131 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1701/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const int N = 2e5+5;

int T, n, m, a[N], cnt[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
bool check(int M) {
	ll now = 0;
	rep(i, 1, n) {
		if(M >= cnt[i]) now += cnt[i] + (M - cnt[i]) / 2;
		else now += M;
	}
	return now >= m;
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, m) scanf("%d", &a[i]);
		rep(i, 1, n) cnt[i] = 0;
		rep(i, 1, m) ++cnt[a[i]];
		int L = 0, R = 2 * m + 1;
		while(L < R) {
			int M = (L + R) >> 1;
			if(check(M)) R = M;
			else L = M + 1;
		}
		printf("%d\n", L);
	}
	return 0;
}