//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, a[N], s[N][2], ans;

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		int _ = i & 1;
		s[i][_] = s[i-1][_] + a[i];
		s[i][_^1] = s[i-1][_^1];
	}
	rep(i, 1, n) ans += (s[n][0] - s[i][0] + s[i-1][1]) == (s[n][1] - s[i][1] + s[i-1][0]);
	printf("%d\n", ans);
	return 0;
}