//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;

ll n, k, now;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
priority_queue<ll> q, q1;
priority_queue<ll, vector<ll>, greater<ll> > q2;
ll bottleNeck() {
	rep(i, 1, k-now) {
		ll u = q.top(); q.pop();
		q.push(u-1); q.push(u-1);
	}
	return q.top();
}

int main() {
	scanf("%lld%lld", &n, &k);
	per(i, 60, 0) if((n >> i) & 1) {q.push(i); q1.push(i); ++now;}
	if(now > k) return puts("No")&0;
	puts("Yes");
	ll qwq = bottleNeck();
	while(true) {
		if(now == k) break;
		ll u = q1.top();
		if(u == qwq) break; q1.pop();
		q1.push(u-1); q1.push(u-1);
		++now;
	}
	while(!q1.empty()) {
		q2.push(q1.top());
		q1.pop();
	}
	while(now < k) {
		ll u = q2.top(); q2.pop();
		q2.push(u-1); q2.push(u-1);
		++now;
	}
	while(!q2.empty()) {
		q1.push(q2.top());
		q2.pop();
	}
	while(!q1.empty()) {
		printf("%lld ", q1.top());
		q1.pop();
	}
	puts("");
    return 0;
}