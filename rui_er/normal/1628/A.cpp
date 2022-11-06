//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T, n, a[N];
vector<int> v[N], ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) {
			scanf("%d", &a[i]);
			v[a[i]].push_back(i);
		}
		int now = 1, lst = n;
		while(now <= n) {
			int mex = 0, pos = now;
			rep(i, 0, lst) {
				if(v[i].size() > 0) {
					mex = i + 1;
					chkmax(pos, v[i][0]);
				}
				else break;
			}
			ans.push_back(mex);
			rep(i, now, pos) v[a[i]].erase(v[a[i]].begin(), v[a[i]].begin()+1);
			now = pos + 1;
			lst = mex - 1;
		}
		int sz = ans.size();
		printf("%d\n", sz);
		for(auto i : ans) printf("%d ", i);
		puts("");
		ans.clear();
		rep(i, 0, n) v[i].clear();
	}
	return 0;
}