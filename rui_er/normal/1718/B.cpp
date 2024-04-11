// Problem: B. Fibonacci Strings
// Contest: Codeforces - Codeforces Round #814 (Div. 1)
// URL: https://codeforces.com/contest/1718/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 105, inf = 0x3f3f3f3f3f3f3f3fll;

ll T, k, a[N], fib[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	fib[0] = fib[1] = 1;
	rep(i, 2, 44) fib[i] = fib[i-2] + fib[i-1];
	fib[45] = inf;
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld", &k);
		rep(i, 1, k) scanf("%lld", &a[i]);
		ll sum = accumulate(a+1, a+1+k, 0LL);
		priority_queue<tuple<ll, ll> > q;
		rep(i, 1, k) q.emplace(a[i], i);
		ll pos = -1, tmp = 0;
		rep(i, 0, 44) {
			tmp += fib[i];
			pos = i;
			if(tmp >= sum) break;
		}
		if(tmp != sum) puts("NO");
		else {
			ll now = 0;
			while(pos >= 0 && !q.empty()) {
				auto u = q.top(); q.pop();
				ll val = get<0>(u), id = get<1>(u);
				if(id == now || val < fib[pos]) {
					puts("NO");
					goto qwq;
				}
				q.emplace(val-fib[pos], --now);
				--pos;
			}
			puts("YES");
			qwq:;
		}
	}
	return 0;
}