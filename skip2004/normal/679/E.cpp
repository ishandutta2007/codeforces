#include<bits/stdc++.h>
const int mod = 1e9 + 7;
const int maxn = 500100;
typedef long long ll;
const int sz = 10;
const ll o[sz] = { 1,o[0] * 42,o[1] * 42,o[2] * 42,o[3] * 42,o[4] * 42,o[5] * 42,o[6] * 42,o[7] * 42,o[8] * 42 };
inline ll gonxt(ll x){ return x - *std::lower_bound(o, o + sz,x); }
std::mt19937 rd(time(0));
int ls[maxn], rs[maxn], len[maxn], size[maxn], p[maxn];
ll max[maxn], val[maxn], ad[maxn];
inline int node(ll x,int cnt = 1) {
	static int tot = 0;
	val[++tot] = x, max[tot] = gonxt(x);
	len[tot] = size[tot] = cnt, p[tot] = rd();
	return tot;
}
inline void put(int x,ll v) { if(x) max[x] += v,val[x] += v,ad[x] += v; }
inline void down(int x) {
	if(ad[x]) put(ls[x], ad[x]), put(rs[x], ad[x]), ad[x] = 0;
}
inline void up(int x) {
	size[x] = size[ls[x]] + size[rs[x]] + len[x];
	max[x] = gonxt(val[x]);
	if(ls[x] && max[ls[x]] > max[x]) max[x] = max[ls[x]];
	if(rs[x] && max[rs[x]] > max[x]) max[x] = max[rs[x]];
}
inline int merge(int x,int y) {
	if(!x || !y) return x | y;
	if(p[x] > p[y]) {
		down(x), rs[x] = merge(rs[x], y), up(x);
		return x;
	} else {
		down(y), ls[y] = merge(x, ls[y]), up(y);
		return y;
	}
}
inline void split(int rt,int k,int & x,int & y) {
	if(!rt) x = y = 0;
	else {
		down(rt);
		if(size[ls[rt]] >= k) {
			split(ls[rt], k, x, ls[rt]), up(y = rt);
		} else if(size[ls[rt]] + len[rt] > k) {
			len[rt] -= k - size[ls[rt]];
			x = merge(ls[rt],node(val[rt], k - size[ls[rt]]));
			ls[rt] = 0;
			up(y = rt);
		} else {
			split(rs[rt], k - size[ls[rt]] - len[rt], rs[rt], y), up(x = rt);
		}
	}
}
inline void solve(int rt,int v) {
	if(max[rt] + v <= 0) return put(rt, v);
	down(rt);
	if(ls[rt]) solve(ls[rt],v);
	if(rs[rt]) solve(rs[rt],v);
	val[rt] += v, up(rt);
}
inline void split(int rt,int l,int r,int & a,int & b,int & c) {
	split(rt,r,a,c);
	split(a,l - 1,a,b);
}
int a[maxn];
int n, q, rt;
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> q;
	for(int i = 1, x;i <= n;++i) std::cin >> x, rt = merge(rt, node(x));
	for(int i = 1, type, a, b, v;i <= q;++i) {
		int x, y, z;
		std::cin >> type;
		if(type == 1) {
			std::cin >> a;
			split(rt, a, a, x, y, z);
			std::cout << val[y] << '\n';
			rt = merge(merge(x,y),z);
		}
		if(type == 2) {
			std::cin >> a >> b >> v;
			split(rt, a, b, x, y, z);
			rt = merge(merge(x, node(v, b - a + 1)), z);
		}
		if(type == 3) {
			std::cin >> a >> b >> v;
			split(rt, a, b, x, y, z);
			do solve(y, v); while(max[y] == 0);
			rt = merge(merge(x, y), z);
		}
	}
}