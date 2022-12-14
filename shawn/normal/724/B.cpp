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

int n, m, a[30][30];
bool f;

bool chk(int i) {
	int cnt = 0;
	For(j, 1, m) {
		if (a[i][j] != j) cnt ++;
	}
	return cnt <= 2;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), m = rdi();
	For(i, 1, n) For(j, 1, m) a[i][j] = rdi();
	For(i, 1, n) {
		if (!chk(i)) {
			f = 1;
			break;
		}
	}
	if (!f) return puts("YES"), 0;
	For(i, 1, m) {
		For(j, i + 1, m) {
			f = 0;
			For(k, 1, n) {
				swap(a[k][i], a[k][j]);
			}
			For(k, 1, n) {
				if (!chk(k)) {
					f = 1;
					break;
				}		
			}
			if (!f) return puts("YES"), 0;
			For(k, 1, n) {
				swap(a[k][i], a[k][j]);
			}
		}
	} 
	return puts("NO"), 0; 
}

/*

*/