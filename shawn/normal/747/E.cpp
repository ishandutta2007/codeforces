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

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 0x7f7f7f7f;

#define rdi() read<int>()
#define rdl() read<ll>()
#define rds(a) scanf("%s", a)
#define mk(i, j) make_pair(i, j)
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

const int maxn = 1e6 + 10;

int pos, n, son[maxn], id, dep[maxn], mx;
string s, name[maxn];
vector <int> ans[maxn];

void gs(string &a) {
	for (;pos <= n; pos ++) {
		if (s[pos] == ',') {
			pos ++;
			return;
		}
		a += s[pos];
	}
}

void gn(int &a) {
	for (;pos <= n; pos ++) {
		if (s[pos] == ',') {
			pos ++;
			return;
		}
		a = a * 10 + (s[pos] - 48);
	}
}

void dfs(int u) {
	for(int i = 1; i <= son[u]; i ++) {
		gs(name[++id]), gn(son[id]);
		dep[id] = dep[u] + 1;
		mx = max(mx, dep[id]);
		ans[dep[id]].push_back(id);
		dfs(id);
	}
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	cin >> s;
	n = s.length();
	mx = 1;
	while (pos <= n) {
		++id;
		gs(name[id]);
		ans[1].push_back(id);
		gn(son[id]);
		dep[id] = 1;
		dfs(id);
	}
	write(mx), putchar(10);
	For(i, 1, mx) {
		int ed = ans[i].size() - 1;
		For(j, 0, ed) {
			cout << name[ans[i][j]] << ' ';
		}
		cout << endl;
	}
	return 0;
}

/*

*/