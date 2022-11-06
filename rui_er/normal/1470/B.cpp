//By: Luogu@rui_er(122461)
//virtual participation
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 3e5+5;

int T, n, a[N], q; ll w;
unordered_map<int, int> buc;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		buc.clear();
		scanf("%d", &n);
		int ans0 = 0, ans1 = 0;
		rep(i, 1, n) {
			scanf("%d", &a[i]);
			int qwq = a[i];
			rep(j, 2, qwq) {
				int now = j * j;
				if(a[i] < now) break;
				while(!(a[i] % now) && a[i] >= now) a[i] /= now;
			}
			++buc[a[i]];
		}
		for(unordered_map<int, int>::iterator it=buc.begin();it!=buc.end();it++) {
			chkmax(ans0, it->second);
			if(it->first == 1 || !(it->second & 1)) ans1 += it->second;
		}
		chkmax(ans1, ans0);
		for(scanf("%d", &q);q;q--) {
			scanf("%lld", &w);
			printf("%d\n", w?ans1:ans0);
		}
	}
	return 0;
}