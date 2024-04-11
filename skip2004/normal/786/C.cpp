#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
const int N = maxn * 20;
typedef long long ll;
int a[maxn], last[maxn], rt[maxn], n, ans;
int ls[N], rs[N], s[N], tot;
inline int add(int rt, int pos, int v, int l = 0, int r = n) {
	int x= ++tot;
	s[x] = s[rt] + v;
	if(l == r) return x;
	int mid = l + r >> 1;
	if(pos <= mid) {
		ls[x] = add(ls[rt], pos, v, l, mid);
		rs[x] = rs[rt];
	} else {
		ls[x] = ls[rt];
		rs[x] = add(rs[rt], pos, v, mid + 1, r);
	}
	return x;
}
inline int bound(int rt, int k, int l = 0, int r = n) {
	if(l == r) return l;
	int mid = l + r >> 1;
	if(k < s[ls[rt]]) {
		return bound(rs[rt], k - s[ls[rt]], mid + 1, r);
	} else {
		return bound(ls[rt], k, l, mid);
	}
}
inline int ask(int rt, int v, int l = 0,int r = n) {
	if(l == r) return s[rt];
	int mid = l + r >> 1;
	return v <= mid ? ask(ls[rt], v, l, mid) : s[ls[rt]] + ask(rs[rt], v, mid + 1, r);
}
inline int qry(int l, int r) {
	return ask(rt[r], l - 1);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) {
		cin >> a[i];
		rt[i] = add(rt[i - 1], last[a[i]], 1);
		rt[i] = add(rt[i], i, -1);
		last[a[i]] = i;
	}
	rep(i, 1, n) {
		int now = n, cnt = 0;
		for(;now;) {
			now = bound(rt[now], i);
			++ cnt;
		}
		cout << cnt << " \n"[i == n];
	}
}