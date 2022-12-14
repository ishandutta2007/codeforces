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

#define rdi() read<int>()
#define rdl() read<ll>()
#define rds(a) scanf("%s", a + 1)
#define mk(i, j) make_pair(i, j)
#define fi first
#define se second
#define For(i, j, k) for (int i = j; i <= k; i ++)
#define Rep(i, j, k) for (int i = j; i >= k; i --)

template<typename t> t read() {
	t x = 0; int f = 1 , c = getchar();
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

const int maxn = 300;

int to[maxn], L;
ll ans;
bool vis[maxn];


ll lcm(ll a, ll b) {
	return a / __gcd(a, b) * b;
}

bool cycle(int u, int s) {
	while (u != to[u]) {
		u = to[u];
		if (u == s) break;
	}
	return u == s;
}

void update(int u, int s) {
	while (u != to[u]) {
		vis[u] = 1;
		u = to[u];
		if (u == s) {
			if (L != 1) L ++;
			break;	
		}
		L++;
	}
	if (!L) L = 1;
}

int n;
bool f;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi();
	For(i, 1, n) {
		to[i] = rdi();	
		if (!vis[to[i]]) ans++;
		vis[to[i]] = 1;
	}
	if (ans != n) return puts("-1"), 0;
	ans = 1;
	memset(vis, 0, sizeof vis);
	For(i, 1, n) {
		if (!vis[i]) {
			if (cycle(i, i)){
				L = 0;
				update(i, i);
				if ((L & 1) == 0) L >>= 1;
				ans = lcm(ans, L);
			}
			else f = 1;	
		}
	}
	if (f) ans = -1;
	write(ans);
}

/*

*/