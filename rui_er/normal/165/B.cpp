//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;

int n, k;
bool check(int v) {
	int tot = 0, qwq = 1;
	while(v / qwq && tot < n) {
		tot += v / qwq;
		qwq *= k;
	}
	return tot >= n;
}

int main() {
	scanf("%d%d", &n, &k);
	int l = 0, r = 1e9, ans = 1e9;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {ans = mid; r = mid - 1;}
		else l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}