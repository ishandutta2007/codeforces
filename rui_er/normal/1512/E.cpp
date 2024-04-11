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
const int N = 505;

int n, l, r, s, a[N], ok[N];

int main() {
	mulT0 {
		scanf("%d%d%d%d", &n, &l, &r, &s);
		rep(i, 1, n) a[i] = ok[i] = 0;
		int k = r - l + 1, now = 0, lst = r;
		if(s < k * (k + 1) / 2 || s > n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2) {puts("-1"); continue;}
		rep(i, l, r) a[i] = i - l + 1, now += a[i]; a[r+1] = n + 1;
		while(now < s) {
			if(a[lst] + 1 < a[lst+1]) ++a[lst], ++now;
			else --lst;
		}
		rep(i, l, r) ok[a[i]] = 1;
		now = 1;
		rep(i, 1, l-1) {
			while(ok[now]) ++now;
			a[i] = now; ok[now] = 1;
		}
		rep(i, r+1, n) {
			while(ok[now]) ++now;
			a[i] = now; ok[now] = 1;
		}
		rep(i, 1, n) printf("%d%c", a[i], " \n"[i==n]);
	}
	return 0;
}