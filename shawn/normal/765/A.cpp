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
typedef pair<int, int> PII;

const int inf = 0x7f7f7f7f;

#define rdi() read<int>()
#define rdl() read<ll>()
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

int n, m, k;
string home, str;
map <string, int> mp;
int head[1000], cnt, tot;
struct edge {
	int nxt, to;
}e[2000];

void insert(int u, int v) {
	e[++cnt].nxt = head[u], e[head[u] = cnt].to = v; 
} 

bool vis[1000];

void dfs(int u) {
	Edge(i, u) {
		if (vis[i]) continue;
		vis[i] = 1;
		int v = e[i].to;
		dfs(v);
	}
	if (u == mp[home]) cout << "home";
	else cout << "contest";
	exit(0);
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	cin >> n;
	cin >> home;
	For(i, 1, n) {
		cin >> str;
		m = str.length();
		For(j, 0, m - 1) {
			if(str[j] == '-') {
				k = j - 1;
				break;
			}
		}
		string u, v;
		u = str.substr(0, k + 1);
		v = str.substr(k + 3, m - k + 2);
	//	cout << u << " " << v << endl;
		if (mp[u] == 0) mp[u] = ++tot;
		if (mp[v] == 0) mp[v] = ++tot;
		insert(mp[u], mp[v]); 
	}
	dfs(mp[home]);
}