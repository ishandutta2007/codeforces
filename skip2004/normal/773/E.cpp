#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 500200;
typedef long long ll;
const int mod = 998244353;
std::mt19937 rd(time(0));
int ls[maxn], rs[maxn], p[maxn], size[maxn];
int min[maxn], val[maxn], left[maxn], right[maxn];
inline void down(int & x, int y) {
	if(x > y) {
		x = y;
	}
}
inline void update(int x) {
	size[x] = size[ls[x]] + size[rs[x]] + 1;
	min[x] = val[x] + size[rs[x]];
	left[x] = val[x];
	right[x] = val[x];
	if(ls[x]) down(min[x], min[ls[x]] + size[rs[x]] + 1), left[x] = left[ls[x]];
	if(rs[x]) down(min[x], min[rs[x]]), right[x] = right[rs[x]];
}
inline void rrs(int &rt){ int x = rs[rt]; rs[rt] = ls[x]; ls[x] = rt; update(rt); rt = x; }
inline void rls(int &rt){ int x = ls[rt]; ls[rt] = rs[x]; rs[x] = rt; update(rt); rt = x; }
inline void ins(int & rt, int v) {
	if(!rt) {
		p[v] = rd();
		update(rt = v);
		return ;
	}
	if(val[rt] < val[v]) {
		ins(rs[rt], v);
		if(p[rs[rt]] >= p[rt]) rrs(rt);
	} else {
		ins(ls[rt], v);
		if(p[ls[rt]] >= p[rt]) rls(rt);
	}
	update(rt);
}

int n;
inline int go(int x, int now) {
	if(now - size[x] >= right[x]) return now - size[x];
	if(now <= left[x]) return std::min(now + size[x], min[x]);
	if(!x) return now;
	int v = go(ls[x], now);
	if(v != val[x]) v += v < val[x] ? 1 : -1;
	return go(rs[x], v);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int rt = 0;
	cin >> n;
	rep(i, 1, n) {
		cin >> val[i], ins(rt, i);
		cout << go(rt, 0) << '\n';
	}
}