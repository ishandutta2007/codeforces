#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
using LL = long long;
using pii = pair<int, int>;

const int N = 1e5+10;
int n;
pii p[N];
LL sum[N];

LL calc_sum(int cnt, int no) {
	if(cnt == 0) {
		return 0;
	}
	if(p[cnt].x <= no) {
		return sum[cnt] - no + p[cnt+1].x;
	}else {
		return sum[cnt];
	}
}

int calc(int a, int no) {
	int st = 0, ed = n+1, md;
	while(st+1<ed) {
		md = st+ed>>1;
		if(p[md].x >= a) {
			st = md;
		}else {
			ed = md;
		}
	}
	if(st == 0) return st;
	if(p[st].x <= no) st--;
	return st;
}

LL solve() {
	int m;
	scanf("%d", &m);
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d %d", &p[i].x, &p[i].y);
	}
	sort(p+1, p+n+1);
	reverse(p+1, p+n+1);
	for(int i=1; i<=n; i++) {
		sum[i] = sum[i-1] + p[i].x;
	}
	LL ans = 0;
	for(int i=1; i<=n; i++) {
		int cnt = min(calc(p[i].y, p[i].x), m-1);
		LL tmp = calc_sum(cnt, p[i].x) + p[i].x + (LL)(m-1-cnt)*p[i].y;
		ans = max(ans, tmp);
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("C.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while(T--) {
		printf("%I64d\n", solve());
	}
	return 0;
}