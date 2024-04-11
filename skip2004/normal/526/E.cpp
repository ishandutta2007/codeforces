#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;
const int N = 2002000;
int n, q;
ll a[N], pre[N];

int go[N];
int head[N], next[N];

int st[N], top, succ, ans;

inline void dfs0(int x) {
	st[++top] = x;
	if(top >= ans) succ = succ || st[top - (ans - 1)] >= x + n;
	for(int&i = head[x];i;i = next[i]) dfs0(i);
	-- top;
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> q;
	rep(i, 1, n) cin >> a[i], a[i + n] = a[i];
	rep(i, 1, n + n) pre[i] = pre[i - 1] + a[i];
	rep(i, 1, q) {
		ll w;
		cin >> w;
		for(int i = 1, p = 1;i <= n + n;++i) {
			for(;p <= n + n && pre[p] - pre[i - 1] <= w;) ++ p;
			go[i] = p;
			next[i] = head[p], head[p] = i;
		}
		succ = ans = 0;
		for(int x = 1;x <= n;x = go[x]) ++ ans;
		dfs0(n + n + 1);
		cout << ans - succ << '\n';
	}
}