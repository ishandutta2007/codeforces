//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T, n, k, a[N], buc[N], col[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void split(int x, int y) {
	rep(i, 1, n+1) col[i] = 0;
	if(k == 1) rep(i, 1, n) col[i] = 1;
	else {
		int tot = 0, lst = 1, now = 0;
		rep(i, 1, n) {
			if(x <= a[i] && a[i] <= y) ++tot;
			else --tot;
			if(tot > 0) {
				rep(j, lst, i) col[j] = col[lst-1] + 1;
				lst = i + 1;
				++now;
				tot = 0;
				if(now == k - 1) {
					rep(j, i+1, n) {
						if(x <= a[j] && a[j] <= y) ++tot;
						else --tot;
						col[j] = col[i] + 1;
					}
					break;
				}
			}
		}
	}
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &k);
		rep(i, 1, n) {
			scanf("%d", &a[i]);
			++buc[a[i]];
		}
		int L = 1, R = 1, now = 0, l = 1, r = n;
		while(L <= n) {
			while(R <= n && now * 2 < n + k) now += buc[R++];
			if(now * 2 >= n + k && R - L < r - l + 1) {
				l = L; r = R - 1;
			}
			now -= buc[L++];
		}
		split(l, r);
		printf("%d %d\n", l, r);
//		rep(i, 1, n) printf("%d%c", col[i], " \n"[i==n]);
		int lst = 1;
		rep(i, 1, n+1) {
			if(col[i] != col[lst]) {
				printf("%d %d\n", lst, i-1);
				lst = i;
			}
		}
		rep(i, 1, n+1) buc[i] = 0;
	}
	return 0;
}