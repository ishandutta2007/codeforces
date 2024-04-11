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

map<string, int> w;
int a, b, c;
string s1, s2;	

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	w["monday"] = 0;
	w["tuesday"] = 1;
	w["wednesday"] = 2;
	w["thursday"] = 3;
	w["friday"] = 4;
	w["saturday"] = 5;
	w["sunday"] = 6;
	cin >> s1 >> s2;
	a = w[s1], b = w[s2];
	c = (b + 7 - a) % 7;
	if (c == 0 || c == 2 || c == 3) puts("YES");
	else puts("NO");
	return 0;
}

/*

*/