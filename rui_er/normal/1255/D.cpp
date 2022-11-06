//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 105;

int T, n, m, k, a[N][N], id[N], goal[N], totR;
char mp[N][N], ans[N][N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	rep(i, 1, 26) id[i] = 'A' + i - 1;
	rep(i, 1, 26) id[i+26] = 'a' + i - 1;
	rep(i, 1, 10) id[i+26+26] = '0' + i - 1;
	for(scanf("%d", &T);T;T--) {
		totR = 0;
		rep(i, 1, n+1) rep(j, 1, m+1) a[i][j] = 0, mp[i][j] = ans[i][j] = '\0';
		rep(i, 1, k) goal[i] = 0;
		scanf("%d%d%d", &n, &m, &k);
		rep(i, 1, n) {
			scanf("%s", mp[i]+1);
			rep(j, 1, m) {
				if(mp[i][j] == 'R') {
					a[i][j] = 1;
					++totR;
				}
				else a[i][j] = 0;
			}
		}
		rep(i, 1, k) goal[i] = totR / k + (i <= totR % k);
		int now = 1, flg = 0;
		rep(i, 1, n) {
			if(!flg) {
				rep(j, 1, m) {
					ans[i][j] = id[now];
					if(a[i][j]) --goal[now];
					if(!goal[now] && now < k) ++now;
				}
			}
			else {
				per(j, m, 1) {
					ans[i][j] = id[now];
					if(a[i][j]) --goal[now];
					if(!goal[now] && now < k) ++now;
				}
			}
			flg ^= 1;
			ans[n+1][m+1] = '\0';
		}
		rep(i, 1, n) printf("%s\n", ans[i]+1);
	}
	return 0;
}