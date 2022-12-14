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

vector < pii > ans;
int sum[1000], a[1000], n, last, flag;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi();
	For(i, 1, n) sum[i] = sum[i - 1] + (a[i] = rdi()), flag |= a[i];
	if (!flag) return puts("NO"), 0;
	last = n;
	For(i, 1, last) if (sum[i] != 0) ans.pb(mk(1, i)), last = i; 
	For(i, last + 1, n) {
		if (a[i] != 0) ans.pb(mk(i, i));
		if (a[i] == 0) ans[ans.size() - 1].se = i;
	}
	puts("YES");
	write(ans.size()), putchar(10);
	For(i, 0, ans.size() - 1) write(ans[i].fi), putchar(32), write(ans[i].se), putchar(10);
	return 0;
}