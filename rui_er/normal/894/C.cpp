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
const int N = 1e3+5;

int n, a[N];
vector<int> ans;

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		if(__gcd(a[1], a[i]) != a[1]) return puts("-1"), 0;
		ans.push_back(a[1]); ans.push_back(a[i]);
	}
	int qwq = ans.size();
	printf("%d\n", qwq);
	rep(i, 0, qwq-1) printf("%d%c", ans[i], " \n"[i==qwq-1]);
	return 0;
}