//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+5;

ll n, c, a[N], mi[N], s[N], dp[N];
deque<ll> q;

int main() {
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	scanf("%lld%lld", &n, &c);
	for(ll i=1;i<=n;i++) scanf("%lld", &a[i]), s[i] = s[i-1] + a[i];
	for(ll i=1;i<=n;i++) {
		while(!q.empty() && i - q.front() >= c) q.pop_front();
		while(!q.empty() && a[q.back()] >= a[i]) q.pop_back();
		q.push_back(i);
		mi[i] = a[q.front()];
	}
	for(ll i=1;i<=n;i++) {
		if(i >= c) dp[i] = dp[i-c] + s[i] - s[i-c] - mi[i];
		dp[i] = min(dp[i], dp[i-1]+a[i]);
	}
	printf("%lld\n", dp[n]);
	return 0;
}