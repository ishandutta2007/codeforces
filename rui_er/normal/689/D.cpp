//By: Luogu@rui_er(122461).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+5;

ll n, a[N], b[N], ans;
deque<ll> q1, q2;

int main() {
	scanf("%lld", &n);
	for(ll i=1;i<=n;i++) scanf("%lld", &a[i]);
	for(ll i=1;i<=n;i++) scanf("%lld", &b[i]);
	for(ll r=1,l=1;r<=n;r++) {
		while(!q1.empty() && a[q1.back()] <= a[r]) q1.pop_back(); q1.push_back(r);
		while(!q2.empty() && b[q2.back()] >= b[r]) q2.pop_back(); q2.push_back(r);
		while(!q1.empty() && !q2.empty() && l <= r && a[q1.front()] > b[q2.front()]) {
			++l;
			while(!q1.empty() && q1.front() < l) q1.pop_front();
			while(!q2.empty() && q2.front() < l) q2.pop_front();
		}
		if(!q1.empty() && !q2.empty() && a[q1.front()] == b[q2.front()]) ans += min(q1.front(), q2.front()) - l + 1;
	}
	printf("%lld\n", ans);
	return 0;
}