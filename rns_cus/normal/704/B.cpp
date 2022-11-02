#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

#define N 100010

int n, s, e;
int nxt[N], cur, idx;
const LL INF = 1ll << 61;
int x[N], a[N], b[N], c[N], d[N];
LL ans, diff, tmp;

LL dif(int u, int v){
	if(u < v) return (LL)x[v] - x[u] + d[u] + a[v];
	return (LL)x[u] - x[v] + c[u] + b[v];
}

int main(){
//	freopen("b.in", "r", stdin);
	scanf("%d %d %d", &n, &s, &e);
	for(int i = 1; i <= n; i ++) scanf("%d", x + i);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	for(int i = 1; i <= n; i ++) scanf("%d", b + i);
	for(int i = 1; i <= n; i ++) scanf("%d", c + i);
	for(int i = 1; i <= n; i ++) scanf("%d", d + i);
	nxt[s] = e;
	ans = dif(s, e);
	for(int i = 1; i <= n; i ++) if(i != s && i != e){
		for( cur = s, diff = INF; cur != e; cur = nxt[cur]){
			tmp = dif(cur, i) + dif(i, nxt[cur]) - dif(cur, nxt[cur]);
			if(diff > tmp){ diff = tmp; idx = cur; }
			if(cur == 0) return 0;
		}
		ans += diff;
		nxt[i] = nxt[idx];
		nxt[idx] = i;
	}
	cout << ans << endl;
}