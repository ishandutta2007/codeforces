//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 2e5+5, K = 505;

int n, m, x[N], y[N], lst[N], s[K+5][K+5], diff[N], blk[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void modify(int k, int delta) {
	if(x[k] + y[k] <= K) {
		int from = lst[k] + x[k];
		int to = from + y[k] - 1;
		rep(i, from, to) s[x[k]+y[k]][i%(x[k]+y[k])] += delta;
	}
	else {
		for(int i=0;;i++) {
			int now = lst[k] + x[k] + i * (x[k] + y[k]);
			int nxt = lst[k] + (i + 1) * (x[k] + y[k]);
			if(now > m) break;
			diff[now] += delta;
			blk[now/K] += delta;
			if(nxt > m) continue;
			diff[nxt] -= delta;
			blk[nxt/K] -= delta;
		}
	}
}
int query(int now) {
	int ans = 0;
	rep(i, 1, K) ans += s[i][now%i];
	for(int i=0;i<=now;i+=K) {
		if(i + K <= now) ans += blk[i/K];
		else rep(j, i, now) ans += diff[j];
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d%d", &x[i], &y[i]);
	rep(i, 1, m) {
		int op, k;
		scanf("%d%d", &op, &k);
		if(op == 1) lst[k] = i;
		modify(k, op==1?1:-1);
		printf("%d\n", query(i));
	}
    return 0;
}