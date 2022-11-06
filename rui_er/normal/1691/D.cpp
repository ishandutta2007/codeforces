// Problem: D. Max GEQ Sum
// Contest: Codeforces - CodeCraft-22 and Codeforces Round #795 (Div. 2)
// URL: https://codeforces.com/contest/1691/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5, inf = 0x3f3f3f3f3f3f3f3fll;

ll T, n, a[N], L[N], R[N], pre[N], suf[N];
stack<ll> st;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Node {
	ll mx;
};
struct SegTree {
	Node t[N<<2];
	#define lc(u) (u << 1)
	#define rc(u) (u << 1 | 1)
	void pushup(ll u) {
		t[u].mx = max(t[lc(u)].mx, t[rc(u)].mx);
	}
	void build(ll* a, ll u, ll l, ll r) {
		if(l == r) {
			t[u].mx = a[l];
			return;
		}
		ll mid = (l + r) >> 1;
		build(a, lc(u), l, mid);
		build(a, rc(u), mid+1, r);
		pushup(u);
	}
	ll query(ll u, ll l, ll r, ll ql, ll qr) {
		if(ql > qr) return -inf;
		if(ql <= l && r <= qr) return t[u].mx;
		ll mid = (l + r) >> 1, ans = -inf;
		if(ql <= mid) chkmax(ans, query(lc(u), l, mid, ql, qr));
		if(qr > mid) chkmax(ans, query(rc(u), mid+1, r, ql, qr));
		return ans;
	}
	void clear(ll u, ll l, ll r) {
		t[u].mx = 0;
		if(l == r) return;
		ll mid = (l + r) >> 1;
		clear(lc(u), l, mid);
		clear(rc(u), mid+1, r);
	}
	#undef lc
	#undef rc
}Pre, Suf;

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld", &n);
		rep(i, 1, n) scanf("%lld", &a[i]);
		rep(i, 1, n) pre[i] = pre[i-1] + a[i];
		per(i, n, 1) suf[i] = suf[i+1] + a[i];
		Pre.build(pre, 1, 1, n);
		Suf.build(suf, 1, 1, n);
		rep(i, 1, n) L[i] = 0, R[i] = n + 1;
		while(!st.empty()) st.pop();
		rep(i, 1, n) {
			while(!st.empty() && a[st.top()] < a[i]) {
				R[st.top()] = i;
				st.pop();
			}
			st.push(i);
		}
		while(!st.empty()) st.pop();
		per(i, n, 1) {
			while(!st.empty() && a[st.top()] < a[i]) {
				L[st.top()] = i;
				st.pop();
			}
			st.push(i);
		}
		int ok = 1;
		rep(i, 1, n) {
			ok &= Pre.query(1, 1, n, i+1, R[i]-1) - pre[i] <= 0;
			ok &= Suf.query(1, 1, n, L[i]+1, i-1) - suf[i] <= 0;
			if(!ok) break;
		}
		puts(ok?"YES":"NO");
		rep(i, 0, n+1) pre[i] = suf[i] = 0;
		Pre.clear(1, 1, n);
		Suf.clear(1, 1, n);
	}
	return 0;
}