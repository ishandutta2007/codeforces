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

const int maxn = 1200000;

double p, q;
bool pri[maxn];
int ans, pr, rub;

void getpri() {
	memset(pri, 1, sizeof pri);
    pri[1] = 0;
	For(i, 2, maxn - 1) {
    	if (!pri[i]) continue;
    	pri[i] = 1;
		for (int j = 2; j * i < maxn; j ++) pri[i * j] = 0;
	}
}

bool getrub(int x) {
	int rex = 0, t = x;
	while (t) {
		rex *= 10;
		rex += t % 10;
		t /= 10;
	}
	return rex == x;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	p = rdi(), q = rdi(); getpri();
	For(i, 1, maxn - 1) {
		pr += pri[i];
		rub += getrub(i);
		if (pr <= rub * p / q) ans = i;
	}
	if (ans) write(ans);
	else puts("Palindromic tree is better than splay tree");
	return 0;
}