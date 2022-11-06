//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T, n, k;
pair<int, int> a[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &k);
		rep(i, 1, n) {
			scanf("%d", &a[i].first);
			a[i].second = i;
		}
		sort(a+1, a+1+n);
		int qwq = 1;
		rep(i, 2, n) if(a[i].second != a[i-1].second + 1) ++qwq;
		puts(k>=qwq?"YES":"NO");
	}
	return 0;
}