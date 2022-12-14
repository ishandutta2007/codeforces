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

const int M1 = 1e7 + 7, M2 = 2333333; 
const int maxn = 2e5 + 10;

pair < pii, pii > h1[maxn], h2[maxn];
pair < pii, pii > b[maxn];
int k, n, w[maxn], p1, p2;
ll ans, res, f[2], g[2];
char a[maxn];
bool vis[maxn];

void nxt(){
	if (h1[p1].first < h2[p2].first) {
		if (vis[h2[p2].se.se]) p2 ++;
		else p1 ++;
	} else {
		if (vis[h1[p1].se.se]) p1 ++;
		else p2 ++;
	}
}

#define pal (b[h1[p1].se.se].fi == b[h1[p1].se.se].se && b[h2[p2].se.se].fi == b[h2[p2].se.se].se)

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	k = rdi(), n = rdi();
	For(i, 1, k) {
		rds(a + 1);
		w[i] = rdi();
		h1[i].se.fi = -w[i];
		h2[i].se.fi = h1[i].se.fi;
		h1[i].se.se = h2[i].se.se = i;
		int t1 = 0, t2 = 0; 
		For(j, 1, n) {
			t1 = (t1 * 29 + (int)a[j] - 'a') % M1;
			t2 = (t2 * 29 + (int)a[j] - 'a') % M2;
		}
		b[i].fi.fi = t1;
		b[i].fi.se = t2;
		h1[i].fi.fi = t1; 
		h1[i].fi.se = t2;
		t1 = 0, t2 = 0; 
		Rep(j, n, 1) {
			t1 = (t1 * 29 + (int)a[j] - 'a') % M1;
			t2 = (t2 * 29 + (int)a[j] - 'a') % M2;
		}
		b[i].se.fi = t1;
		b[i].se.se = t2;
		h2[i].fi.fi = t1; 
		h2[i].fi.se = t2;
	} 
	sort(h1 + 1, h1 + k + 1);
	sort(h2 + 1, h2 + k + 1);
	p1 = 1, p2 = 1;
	while (p1 <= k && p2 <= k) {
		if (h1[p1].fi == h2[p2].fi) {
			if (h1[p1].se.se != h2[p2].se.se && !vis[h1[p1].se.se] && !vis[h2[p2].se.se] 
			&& !pal) {
				int add = -(h1[p1].se.fi + h2[p2].se.fi);
				if (add > 0) {
					vis[h1[p1].se.se] = 1;
					vis[h2[p2].se.se] = 1;
					p1 ++, p2 ++;
					ans += 1ll * add;
				}
				else nxt();
			}else {
				if (pal) {
					//f[0] = max(f[0], f[])
					bool flag = 1;
					g[0] = g[1] = 0; 
					g[1] = max(g[1], g[0] - h1[p1].se.fi);
					p1 ++, p2 ++;
					while (p1 <= k && p2 <= k && pal && h1[p1].fi == h1[p1 - 1].fi && h2[p2].fi == h2[p2 - 1].fi) {
						flag ^= 1;
						g[flag] = max(g[flag], g[flag] - h1[p1].se.fi - h1[p1 - 1].se.fi);
						p1 ++, p2 ++;
					}
					f[1] = max(f[1], max(f[0] + g[1], f[1] + g[0]));
					f[0] = max(f[0], g[0] + f[0]);
				}
				else nxt();
			} 
		}else nxt();
	} 
	write(ans + max(f[0], f[1]));
	return 0; 
}

/*

*/