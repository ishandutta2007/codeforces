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

const int maxn = 1100;

struct Name{
	string x, y, ans;
	int id;
}s[maxn];

map <string, int> mp_a, mp_x, mp_y;
int n;


bool cmp(Name a, Name b) {
	return mp_x[a.x] > mp_x[b.x];
}

bool cmpid(Name a, Name b) {
	return a.id < b.id;
}

bool cmpa(Name a, Name b) {
	return mp_a[a.x] > mp_a[b.x];
}

int go(int x) {
	sort(s + x, s + n, cmpa);
	if (mp_a[s[x].x] == 0) return x;
	for (; x <= n; x ++) {
		if (mp_a[s[x].x] == 1) {
			if (mp_a[s[x].y] == 1) return -1;
			s[x].ans = s[x].y;
			mp_a[s[x].y] = 1;
		}else break;
	}
	return go(x);
}

bool solve() {
	int i = 0;
	for (; i < n; i ++) {
		if (mp_x[s[i].x] > 1) {
			if (mp_y[s[i].y] == 1) return 0;
			else {
				s[i].ans = s[i].y;
				mp_y[s[i].y] = 1;
				mp_a[s[i].y] = 1;
			}
		}else break;
	}
	i = go(i);
	if (i == -1) return 0;
	for (; i < n; i ++) s[i].ans = s[i].x;
	return 1;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi();
	For(i, 0, n - 1) {
		cin >> s[s[i].id = i].x >> s[i].y;
		s[i].y = s[i].x.substr(0, 2) + s[i].y[0];
		s[i].x = s[i].x.substr(0, 3);
		mp_x[s[i].x]++;
	}
	sort(s, s + n, cmp);
	
	bool F = solve();
	puts(F ? "YES" : "NO");
	if (F) {
		sort(s, s + n, cmpid);
		For(i, 0, n - 1) cout << s[i].ans << endl;
	}
	return 0;
}