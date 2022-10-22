#include<bits/stdc++.h>
const int maxn = 200200;
const int mod = 998244353;
typedef long long ll;
inline ll pow(ll a,int b,ll ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1) ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
inline void reduce(int & x){ x += x >> 31 & mod; }
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
typedef double db;
int n;
db ans[maxn << 2];
db min[maxn << 2];
db max[maxn << 2];
inline void update(int o) {
	ans[o] = ans[o << 1] + ans[o << 1 | 1];
	min[o] = std::min(min[o << 1],min[o << 1 | 1]);
	max[o] = std::max(max[o << 1],max[o << 1 | 1]);
}
inline int find(int o,db * x,int l = 1,int r = n) {
	if(l == r) return l;
	int mid = l + r >> 1;
	return x[o] == x[o << 1] ? find(o << 1,x,l,mid) : find(o << 1 | 1,x,mid + 1,r);
}
inline db get(int l,int x) { return x < 0 || x > l ? -1 / 0. : (db) x / (x + l);}
inline db calc(int l,int x) { return x > l ? -1. / 0 : get(l, x) - get(l, x - 1); }
template<typename _Tp>
inline _Tp get(){ static _Tp x; return std::cin >> x, x; }
db p[maxn];
int cnt[maxn], l[maxn], t, q;
inline void mdf(int o,int pos,int l = 1,int r = n) {
	if(l == r) {
		max[o] = p[pos] * calc(::l[pos], cnt[pos] + 1);
		min[o] = p[pos] * calc(::l[pos], cnt[pos]);
		ans[o] = p[pos] * get(::l[pos], cnt[pos]);
		return ;
	}
	int mid = l + r >> 1;
	if(pos <= mid) mdf(o << 1,pos,l,mid);
	else mdf(o << 1 | 1,pos,mid + 1,r);
	update(o);
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
 	std::cin >> n >> t >> q;
	for(int i = 1;i <= n;++i) p[i] = get<int>();
	for(int i = 1;i <= n;++i) std::cin >> l[i];
	l[++n] = 1e9, p[n] = 1e-20;
	for(int i = 1;i <= n;++i) mdf(1,i);
	for(;t--;) {
		int u = find(1, max);
		++ cnt[u], mdf(1, u);
	}
	for(int i = 1, t, k;i <= q;++i) {
		std::cin >> t >> k, l[k] += t == 1 ? 1 : - 1;
		mdf(1,k);
		for(;max[1] > min[1];) {
			int u = find(1, max), v = find(1, min);
			++ cnt[u], -- cnt[v];
			mdf(1, u), mdf(1, v);
		}
		printf("%.10lf\n",ans[1]);
	}
}