#include<bits/stdc++.h>
const int maxn = 500005;
const int N = maxn * 22;
int ls[N], rs[N], t[N], q[N], tot;
struct vector {
	int bak[62], size;
	inline void push(int x){ if(x) bak[size++] = x; }
} to[maxn];
int a[maxn];
int n;
inline int build(int l, int r) {
	if(l == r) return l;
	int mid = l + r >> 1, x = ++ tot;
	ls[x] = build(l, mid);
	rs[x] = build(mid + 1, r);
	return x;
}
inline int rm(int rt, int pos, int l, int r) {
	if(l == r) return 0;
	int x = ++ tot, mid = l + r >> 1;
	if(pos <= mid) ls[x] = rm(ls[rt], pos, l, mid), rs[x] = rs[rt];
	else ls[x] = ls[rt], rs[x] = rm(rs[rt], pos, mid + 1, r);
	return x;
}
inline void push(vector & vc, int rt, int pos, int out, int l, int r) {
	if((out < l || out > r) && r <= pos) return vc.push(rt);
	if(l == r) return ;
	int mid = l + r >> 1;
	push(vc, ls[rt], pos, out, l, mid);
	if(pos > mid) push(vc, rs[rt], pos, out, mid + 1, r); 
}
int ans[maxn];
inline bool topo() {
	for(int i = 1;i <= tot;++i) {
		if(ls[i]) ++ t[ls[i]];
		if(rs[i]) ++ t[rs[i]];
		if(i <= n) for(int j = 0;j < to[i].size;++j) ++ t[to[i].bak[j]];
	}
	int l = 1, r = 0;
	for(int i = 1;i <= tot;++i) if(!t[i]) q[++r] = i;
	const auto test = [&](int x) { if(--t[x] == 0) q[++r] = x; };
	for(;l <= r;) {
		int x = q[l++];
		if(ls[x]) test(ls[x]);
		if(rs[x]) test(rs[x]);
		if(x <= n) {
			for(int j = 0;j < to[x].size;++j) test(to[x].bak[j]);
			static int idx = n;
			ans[x] = idx--;
		}
	}
	return r == tot;
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	using std::cin;
	using std::cout;
	cin >> n, tot = n;
	int root = build(1, n);
	for(int i = 1, a;i <= n;++i) {
		cin >> a;
		if(a != -1) {
			root = rm(root, a, 1, n);
			to[a].push(i);
			push(to[i], root, a, i, 1, n);
		} else {
			push(to[i], root, n, i, 1, n);
		}
	}
	if(topo()) {
		for(int i = 1;i <= n;++i) {
			cout << ans[i] << " \n"[i == n];
		}
	} else {
		exit(1);
	}
}