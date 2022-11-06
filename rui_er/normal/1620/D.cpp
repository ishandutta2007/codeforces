// Problem: CF1620D Exact Change
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1620D
// Memory Limit: 250 MB
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
const int N = 105, inf = 0x3f3f3f3f;

int T, n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		int ans = inf;
		rep(i, 0, 2) {
			rep(j, 0, 2) {
				int nd = 0;
				rep(k, 1, n) {
					int tmp = inf;
					rep(l, 0, i) {
						rep(m, 0, j) {
							int qwq = a[k] - l - 2 * m;
							if(qwq < 0 || qwq % 3) continue;
							chkmin(tmp, qwq / 3);
						}
					}
					chkmax(nd, tmp);
				}
				chkmin(ans, i + j + nd);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}