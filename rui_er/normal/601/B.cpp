//By: Luogu@rui_er(122461).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, q, a[N], dis[N], l[N], r[N];
stack<int> s; 

int main() {
	scanf("%d%d", &n, &q);
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i]);
		dis[i] = abs(a[i] - a[i-1]);
	}
	for(int i=2;i<=n;i++) {
		while(!s.empty() && dis[s.top()] <= dis[i]) r[s.top()] = i - 1, s.pop();
		l[i] = (s.empty() ? 0 : s.top()) + 1;
		s.push(i);
	}
	while(!s.empty()) r[s.top()] = n, s.pop();
	while(q--) {
		int ql, qr; ll ans = 0;
		scanf("%d%d", &ql, &qr);
		for(int i=ql+1;i<=qr;i++) {
			int _l = max(l[i]-1, ql), _r = min(r[i], qr);
			ans += 1LL * dis[i] * (i - _l) * (_r - i + 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}