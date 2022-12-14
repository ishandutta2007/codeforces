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

int a[110], n, q, ave, sum, del, k, d, t, last;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), q = rdi();
	ave = n;
	For(j, 1, q) {
		t = rdi(), k = rdi(), d = rdi();
		if (j != 1) {
			del = t - last;
			For(i, 1, n) {
				if (a[i] == 0) continue; 
				a[i] -= del;
				if (a[i] <= 0) a[i] = 0, ave ++;
			}
		}
		if (ave >= k) {
			sum = 0;
			int ned = k;
			For(i, 1, n) {
				if (ned == 0) break;
				if (a[i] == 0) a[i] = d, ave --, sum += i, ned --;
			}
			write(sum), putchar(10);
		}else puts("-1");
		last = t;
	}
	return 0;
}

/*

*/