#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int N = 4e4L + 11;
int n;

const int mxv = 2e6L + 11;
#define nil mem // Get/Setll
struct Node { Node *l, *r; int val; }
	mem[mxv] = {{nil, nil}}; int sz; using ptr = Node*;
#define NEW(arg...) new(mem + ++sz)Node{arg}
#define COPY(x) new(mem + ++sz)Node(*(x))
#define m (l + r >> 1)
ptr renew(ptr x) { x->val=x->l->val+x->r->val; return x; }
ptr build(int l, int r) {
	if (l == r) return NEW(nil, nil, 0);
	return renew(NEW(build(l, m), build(m + 1, r)));
}
int Get(ptr x, int l, int r, int sl, int sr) {
	if (sl <= l && r <= sr) return x->val;
	if (sr <= m) return Get(x->l, l,m, sl,sr);
	if (m < sl) return Get(x->r, m+1,r, sl,sr);
	return Get(x->l, l,m, sl,sr) + Get(x->r, m+1,r, sl,sr);
}
ptr Set(ptr x, int l, int r, int s, int ope) {
	x = COPY(x); // : if (x == nil) x = NEW(nil,nil);
	if (l == r) { x->val += ope; return x; }
	if (s <= m) x->l = Set(x->l, l, m, s, ope);
	else x->r = Set(x->r, m + 1, r, s, ope);
	return renew(x);
}
#undef m
ptr root[N];

int dp[2][N];

int a[N], c[N], p[N];
int nxt[N];

void trans(int *f, int fl, int fr, int *g, int gl, int gr) {
	if(gl >= gr) return;
	int m = (gl + gr) / 2;
	int cnt = 0;
	int j = -1, k = -1;
	int b = Get(root[m + 1], 0, n, fl, m);
	for(int i = fl; i < min(fr, m); i ++) {
		if(i && p[i] > m) b --;
		int t = f[i] + b;
		if(t > k) {
			j = i; k = t;
		}
	}
	g[m] = k;
	trans(f, fl, j + 1, g, gl, m);
	trans(f, j, fr, g, m + 1, gr);
}

vector <int> v[N];

int main() {
	ios :: sync_with_stdio(0);
	int k; cin >> n >> k;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++)
		nxt[i] = n + 1;
	for(int i = n; i >= 1; i --) {
		p[i] = nxt[a[i]];
		nxt[a[i]] = i;
		v[p[i]].pb(i);
	}
	ptr q = build(0, n);
	for(int i = n + 1; i >= 1; i --) {
		for(int x : v[i])
			q = Set(q, 0, n, x, 1);
		root[i] = q;
	}

	for(int i = 0; i < k; i ++)
		trans(dp[i & 1], i, n + 1, dp[i & 1 ^ 1], i + 1, n + 1);
	cout << dp[k & 1][n] << '\n';
}