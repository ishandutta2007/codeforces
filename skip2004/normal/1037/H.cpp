#include<bits/stdc++.h>
const int maxn = 100010;
int n, q;
using std::cin;
using std::cout;
namespace tree
{
	const int N = maxn * 40;
	int ls[N], rs[N], tot;
	inline void add(int & rt, int pos, int l = 1, int r = n)
	{
		if(!rt) rt = ++tot;
		if(l == r) return ;
		int mid = l + r >> 1;
		if(pos <= mid) {
			add(ls[rt], pos, l, mid);
		} else {
			add(rs[rt], pos, mid + 1, r);
		}
	}
	inline int merge(int x, int y)
	{
		if(!x || !y)
			return x | y;
		int p = ++tot;
		ls[p] = merge(ls[x], ls[y]);
		rs[p] = merge(rs[x], rs[y]);
		return p;
	}
	inline bool ask(int rt, int ql, int qr, int l = 1, int r = n) {
		if(ql <= l && r <= qr) return rt;
		int mid = l + r >> 1;
		if(ql <= mid && ask(ls[rt], ql, qr, l, mid)) return 1;
		if(mid < qr && ask(rs[rt], ql, qr, mid + 1, r)) return 1;
		return 0;
	}
	inline int test(int rt, int l, int r, int len)
	{
		if(len > r - l + 1)
			return 0;
		return ask(rt, l + len - 1, r);
	}
}
const int N = maxn * 2;
int c[N][26], fa[N], mx[N], right[N], rt[N], la, tot;
int head[N], next[N];
inline void link(int fa, int x)
{
	next[x] = head[fa], head[fa] = x;
}
inline void append(int w, int n)
{
	int p = la, now = la = ++tot;
	mx[now] = mx[p] + 1;
	right[now] = n;
	for(;p && !c[p][w];p = fa[p])
		c[p][w] = now;
	if(!p) {
		fa[now] = 1;
	} else {
		int q = c[p][w];
		if(mx[q] == mx[p] + 1) {
			fa[now] = q;
		} else {
			int x = ++ tot;
			mx[x] = mx[p] + 1;
			memcpy(c[x], c[q], sizeof c[x]);
			fa[x] = fa[q], fa[q] = fa[now] = x;
			for(;p && c[p][w] == q;p = fa[p]) 
				c[p][w] = x;
		}
	}
}
char s[maxn];
inline void dfs0(int x)
{
	if(right[x])
		tree::add(rt[x], right[x]);
	for(int i = head[x];i;i = next[i])
	{
		dfs0(i);
		rt[x] = tree::merge(rt[x], rt[i]);
	}
}
std::string str;
static char buf[maxn];
int lol, l, r, len;
inline bool dfs(int x, int p, int low)
{
	if(low == 0 || x > len)
	{
		lol = 1;
		cout << str << '\n';
		return 1;
	}
	for(int i = std::max(low ? buf[x] - 'a' : 0, 0);i < 26;++i)
		if(c[p][i] && tree::test(rt[c[p][i]], l, r, x + 1))
		{
			str += char(i + 'a');
			if(dfs(x + 1, c[p][i], low && i == buf[x] - 'a'))
				return 1;
			str.pop_back();
		}
	return 0;
}
inline void solve(const char * ch) 
{
	len = strlen(ch);
	lol = 0, str = "";
	dfs(0, 1, 1);
	if(!lol) 
	{
		cout << -1 << '\n';
	}
}
int main()
{
//	freopen("1.in", "r", stdin);
	la = tot = 1;
	cin >> s + 1;
	n = strlen(s + 1);
	for(int i = 1;i <= n;++i)
	{
		append(s[i] - 'a', i);
	}
	for(int i = 2;i <= tot;++i)
	{
		link(fa[i], i);
	}
	dfs0(1);
	cin >> q;
	for(int i = 0;i < q;++i)
	{
		cin >> l >> r >> buf;
//		std::swap(l = n - l + 1, r = n - r + 1);
		solve(buf);
	}
}