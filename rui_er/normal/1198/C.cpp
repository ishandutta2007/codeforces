//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 5e5+5;

int T, n, m, vis[N];
vector<int> sel;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, 3*n) vis[i] = 0;
		sel.clear();
		rep(i, 1, m) {
			int u, v;
			scanf("%d%d", &u, &v);
			if(vis[u] || vis[v]) continue;
			vis[u] = vis[v] = 1;
			sel.push_back(i);
		}
		int sz = sel.size();
		if(sz >= n) {
			puts("Matching");
			rep(i, 0, n-1) printf("%d%c", sel[i], " \n"[i==n-1]);
		}
		else {
			puts("IndSet");
			int tot = 0;
			rep(i, 1, 3*n) {
				if(!vis[i]) {
					printf("%d%c", i, " \n"[++tot==n]);
					if(tot == n) break;
				}
			}
		}
	}
	return 0;
}