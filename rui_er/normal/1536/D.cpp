//LG@rui_er 
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T, n, a[N], b[N], c[N];
int lowbit(int x) {return x&(-x);}
void add(int x, int k) {for(int i=x;i<=n;i+=lowbit(i)) b[i] += k;}
int ask(int x) {int ans = 0; for(int i=x;i;i-=lowbit(i)) ans += b[i]; return ans;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]), c[i] = a[i];
		sort(c+1, c+1+n);
		int cnt = unique(c+1, c+1+n) - c - 1;
		rep(i, 1, n) a[i] = lower_bound(c+1, c+1+cnt, a[i]) - c;
//		rep(i, 1, n) fprintf(stderr, "%d%c", a[i], " \n"[i==n]);
		add(a[1], 1);
		int ans = 1;
		rep(i, 2, n) {
			int x = max(a[i], a[i-1]), y = min(a[i], a[i-1]);
			if(x - y > 1) {
				int qwq = ask(x-1) - ask(y);
//				fprintf(stderr, "i=%d [%d, %d] : %d\n", i, y, x-1, qwq);
				if(qwq > 0) ans = 0;
			}
			add(a[i], 1);
		}
		puts(ans?"YES":"NO");
		rep(i, 1, n) add(a[i], -1);
	}
	return 0;
}