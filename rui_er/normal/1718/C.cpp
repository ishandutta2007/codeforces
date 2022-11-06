// Problem: C. Tonya and Burenka-179
// Contest: Codeforces - Codeforces Round #814 (Div. 1)
// URL: https://codeforces.com/contest/1718/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
const ll N = 2e5+5;

ll T, n, q, a[N];
vector<ll> divisors, sum[N];
priority_queue<ll> heap, del;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld", &n, &q);
		rep(i, 1, n) scanf("%lld", &a[i]);
		per(i, n-1, 1) {
			if(!(n % i)) {
				ll ok = 1;
				for(ll d : divisors) if(!(d % i)) {ok = 0; break;}
				if(!ok) continue;
				divisors.push_back(i);
				sum[i].resize(i);
			}
		}
		for(ll d : divisors) {
			rep(i, 1, n) sum[d][i%d] += a[i] * d;
			rep(i, 0, d-1) heap.push(sum[d][i]);
		}
		printf("%lld\n", heap.top());
		while(q--) {
			ll p, x;
			scanf("%lld%lld", &p, &x);
			ll diff = x - a[p];
			a[p] = x;
			for(auto d : divisors) {
				del.push(sum[d][p%d]);
				sum[d][p%d] += diff * d;
				heap.push(sum[d][p%d]);
			}
			while(!del.empty() && heap.top() == del.top()) {heap.pop(); del.pop();}
			printf("%lld\n", heap.top());
		}
		for(ll d : divisors) sum[d].clear();
		divisors.clear();
		while(!heap.empty()) heap.pop();
		while(!del.empty()) del.pop();
	}
	return 0;
}