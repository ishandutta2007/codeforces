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

const int maxn = 5e5 + 10;
const int maxc = 1e6 + 10;

vector <int> w[maxn];
int l[maxn], r[maxn], cnt[maxc];
int c, n, sum;

void calc(int x, int y) {
	int idx = 0;
	while (idx < l[x] && idx < l[y]) {
		if (w[x][idx] != w[y][idx]) break;
		idx ++;
	}
	if (idx == l[x] && idx == l[y]) {
		cnt[0]++;
		cnt[c] --;
		return;
	}
	if (idx == l[x] && idx != l[y]) {
		cnt[0]++;
		cnt[c] --;
		return;
	}
	if (idx != l[x] && idx == l[y]) {
		puts("-1");
		exit(0);
		return;
	}
//	idx --;
	if (w[x][idx] < w[y][idx]) {
		cnt[0]++;
		cnt[c - w[y][idx] + 1] --;
		
		cnt[c - w[x][idx] + 1] ++;
		cnt[c]--;
		return;
	}
	
	if (w[x][idx] > w[y][idx]) {
		cnt[c - w[x][idx] + 1] ++;
		cnt[c - w[y][idx] + 1] --;
	}
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), c = rdi();
	For (i, 1, n) {
		l[i] = rdi();
		For(j, 1, l[i]) w[i].push_back(rdi());
	}
	For(i, 1, n - 1) {
		calc(i, i + 1);
	}
	For(i, 0, c - 1) {
		sum += cnt[i];
		if (sum == n - 1) {
			write(i);
			return 0;
		}
	}
	puts("-1");
	return 0;	
	                                                                                                                 
}

/*

*/