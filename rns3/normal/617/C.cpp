#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 3001

int a[M], b[M];
int vis[M];

ll sqr(int x) {
	return 1ll * x * x;
}

int main() {
    int n, x1, y1, x2, y2;
    scanf("%d %d %d %d %d", &n, &x1, &y1, &x2, &y2);
    for(int i = 1; i <= n; i ++) scanf("%d %d", &a[i], &b[i]);
    a[++n] = x1; b[n] = y1;
    a[++n] = x2; b[n] = y2;
    long long ans = (1ll << 62);
    for(int i = 1; i <= n; i ++) {
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
		for(int j = 1; j <= n; j ++) {
			ll x = sqr(x1 - a[j]) + sqr(y1 - b[j]);
			ll y = sqr(x1 - a[i]) + sqr(y1 - b[i]);
			if(x <= y) vis[j] = 1;
			cnt += vis[j];
		}
        ll st = -1, en = (1ll << 62);
		while(en > st + 1) {
            ll mid = (en + st) / 2;
            int j;
			for(j = 1; j <= n; j ++) if(!vis[j]){
                ll x = sqr(x2 - a[j]) + sqr(y2 - b[j]);
                if(x > mid) break;
			}
			if(j == n + 1) en = mid;
			else st = mid;
		}
        ans = min(ans, sqr(x1 - a[i]) + sqr(y1 - b[i]) + en);
    }
    cout << ans << endl;
}