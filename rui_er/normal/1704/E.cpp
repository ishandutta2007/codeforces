// Problem: E. Count Seconds
// Contest: Codeforces - CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef __int128 ll;
const ll N = 1e3+5, mod = 998244353;

ll T, n, m, a[N], b[N], indeg[N];
vector<ll> e[N], tpn;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll read() {
	ll x = 0, k = 1;
	char c = getchar();
	for(;!isdigit(c);c=getchar()) if(c == '-') k = -1;
	for(;isdigit(c);c=getchar()) x = x * 10 + c - 48;
	return x * k;
}
void write(ll x, char end = 0) {
	if(x < 0) {putchar('-'); x = -x;}
	if(x < 10) putchar(x+48);
	else {
		write(x/10);
		putchar(x%10+48);
	}
	if(end) putchar(end);
}
struct Segment {
	ll L, R;
	Segment(ll a=0, ll b=0) : L(a), R(b) {}
	friend bool operator < (const Segment& a, const Segment& b) {
		if(a.L != b.L) return a.L < b.L;
		return a.R < b.R;
	}
	friend Segment operator + (const Segment& a, const ll& k) {
		return Segment(a.L + k, a.R + k);
	}
	ll len() {return R - L + 1;}
};
vector<Segment> seg[N], nxt;
void toposort() {
	queue<ll> q;
	tpn.clear();
	rep(i, 1, n) if(!indeg[i]) q.push(i);
	while(!q.empty()) {
		ll u = q.front(); q.pop();
		tpn.push_back(u);
		for(ll v : e[u]) if(!--indeg[v]) q.push(v);
	}
}

int main() {
	for(T=read();T;T--) {
		n = read(); m = read();
		rep(i, 1, n) a[i] = read();
		rep(i, 1, m) {
			ll u, v;
			u = read(); v = read();
			e[u].push_back(v);
			++indeg[v];
		}
		toposort();
		ll ans = 0;
		for(ll u : tpn) {
			if(a[u]) seg[u].emplace_back(1, a[u]);
			ll sz = seg[u].size();
			if(!sz) continue;
			nxt.clear();
			sort(seg[u].begin(), seg[u].end());
			Segment now = seg[u][0];
			rep(i, 1, sz-1) {
				if(seg[u][i].L <= now.R + 1) now.R += seg[u][i].len();
				else {
					nxt.push_back(now);
					now = seg[u][i];
				}
			}
			if(now.R) nxt.push_back(now);
			for(ll v : e[u]) for(Segment sg : nxt) seg[v].push_back(sg+1);
			chkmax(ans, nxt.back().R);
		}
		write(ans%mod, '\n');
		rep(i, 1, n) {
			a[i] = b[i] = indeg[i] = 0;
			tpn.clear();
			e[i].clear();
			seg[i].clear();
			nxt.clear();
		}
	}
	return 0;
}//