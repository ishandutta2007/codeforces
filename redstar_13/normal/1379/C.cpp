#include <bits/stdc++.h>

#define x first
#define y second
using namespace std;
using pii = pair<int, int>;
const int NN = 100011;
struct point{
	int x, y;
	point(int x=0, int y=0) : x(x), y(y) {}
	bool operator < (const point &p) const {
		if(x != p.x) return x < p.x;
		return y < p.y;
	}
};
point p[NN];
using INT = long long;
INT sum[NN];

	INT n, m;
inline INT calc(int id) {
	int b = p[id].y;
	int a = p[id].x;
	int pos = lower_bound(p, p+m, point{b, 0}) - p;
	INT cnt = m - pos;
	if(a >= b) cnt --;
	if(cnt >= n) return 0;
	INT ans;
	if(a < b) ans = sum[m-cnt]+a;
	else ans = sum[m-cnt-1];
	cnt = n-cnt-1;
	if(cnt) ans += (INT)b*cnt;
	return ans;
}

inline void smax(INT &u, INT v) {if(u<v) u =v ;}

int solve() {
	cin >> n >> m;
	for(int i=0; i<m; i++) scanf("%d %d", &p[i].x, &p[i].y);
	sort(p, p+m);
	INT ans = 0;
	sum[m]  =0;
	for(int i=m-1; i>=0; i--) sum[i] = sum[i+1] + p[i].x;
	for(int i=0; i<m; i++) {
		smax(ans, calc(i));
	}
	if(m>=n) smax(ans, sum[m-n]);
	printf("%I64d\n", ans);
}

int main (){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	int T;
	cin >> T;
	while(T--) solve();

	  return 0;
}