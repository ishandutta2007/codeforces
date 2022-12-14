#include <bits/stdc++.h>

/*
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <set>
*/

using namespace std;

typedef long long LL;
typedef double DB;
typedef unsigned int UI;
typedef pair<int, int> PII;

const int inf = 0x7f7f7f7f;

#define rdi() read<int>()
#define rdl() read<LL>()
#define rds(a) scanf("%s", a)
#define mk(i, j) make_pair(i, j)
#define pb push_back
#define fi first
#define se second
#define For(i, j, k) for (int i = j; i <= k; i ++)
#define Rep(i, j, k) for (int i = j; i >= k; i --)
#define Edge(i, u) for (int i = head[u]; i; i = e[i].nxt)

template<typename t> t read() {
	t x = 0; int f = 1; char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

template<typename t> void write(t x) {
	if (x < 0){
		putchar('-'), write(-x);
		return;
	}
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int N = 3e5 + 10;

struct pt {
	int s;
	vector <int> q;
}a[N];
int n, m, col[N], st[N], head[N], cnt, ans;
struct edge {
	int nxt, to;
}e[N << 1];

void insert(int u, int v) {
	e[++cnt].nxt = head[u], e[head[u] = cnt].to = v;
}

void dfs(int u, int p) {
	set <int> s;
	int c = 1;
	for (int i = 0; i < a[u].s; i ++) if (col[a[u].q[i]]) s.insert(col[a[u].q[i]]);
	for (int i = 0; i < a[u].s; i ++) if (!col[a[u].q[i]]) {
		while (s.find(c) != s.end()) c ++;
		col[a[u].q[i]] = c;
		s.insert(c);
	}
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (v == p) continue;
		dfs(v, u);
	}
}
   
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), m = rdi();
	for (int i = 1; i <= n; i ++) {
		a[i].s = rdi();
		ans = max(a[i].s, ans);
		for (int j = 1; j <= a[i].s; j ++) {
			int x = rdi();
			a[i].q.pb(x);
		} 
	}
	for (int i = 1; i < n; i ++) {
		int u = rdi(), v = rdi();
		insert(u, v), insert(v, u);
	} 
	write(ans = max(ans, 1)); putchar(10);
	if (ans == 1) for (int i = 1; i <= m; i ++) col[i] = 1;
	else dfs(1, 0);
	for (int i = 1; i <= m; i ++) write(!col[i] ? 1 : col[i]), putchar(32);	
	return 0;
}