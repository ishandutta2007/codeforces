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

set <string> ans;
string s;
int n;
bool vis[10100];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	cin >> s;
	n = s.size();
	vis[n] = 1;
	Rep(i, n - 1, 5) {
		if (vis[i + 2]) {
			string t = s.substr(i, 2);
			if (s.find(t, i + 2) != i + 2 || vis[i + 5]) {
				vis[i] = 1;
				ans.insert(t);
			}
		}
		if (vis[i + 3]) {
			string t = s.substr(i, 3);
			if (s.find(t, i + 3) != i + 3 || vis[i + 5]) {
				vis[i] = 1;
				ans.insert(t);
			}
		}
	}
	cout << ans.size() << endl;
	for (auto &ite : ans) cout << ite << endl;
	return 0;
}