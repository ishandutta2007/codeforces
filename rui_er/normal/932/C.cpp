//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;

int n, a, b, l, k;
vector<int> ans;

int main() {
	scanf("%d%d%d", &n, &a, &b);
	if(a < b) swap(a, b);
	k = n; l = 1;
	while(k % b) {
		k -= a;
		if(k < 0) return puts("-1"), 0;
		rep(i, 0, a-2) ans.push_back(l+i+1);
		ans.push_back(l);
		l += a;
	}
	while(k) {
		k -= b;
		rep(i, 0, b-2) ans.push_back(l+i+1);
		ans.push_back(l);
		l += b;
	}
	rep(i, 0, n-1) printf("%d ", ans[i]);
	puts("");
	return 0;
}