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

int num[100], n, cnt, mx, need;
char A[1000];
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi();
	rds(A + 1);
	if (n % 4 != 0) return puts("==="), 0;
	mx = n / 4;
	For(i, 1, n) {
		if (A[i] == '?') {
			cnt ++;
			continue;
		}
		num[A[i] - 'A'] ++;
		if (num[A[i] - 'A'] > mx) return puts("==="), 0;
	}
	need = (mx - num[0]) + (mx - num['C' - 'A']) + (mx - num['G' - 'A']) + (mx - num['T' - 'A']);
	num[0] = (mx - num[0]);
	num['C' - 'A'] = (mx - num['C' - 'A']);
	num['G' - 'A'] = (mx - num['G' - 'A']);
	num['T' - 'A'] = (mx - num['T' - 'A']);
	if (need != cnt) return puts("==="), 0;
	For(i, 1, n) {
		if (A[i] != '?') putchar(A[i]);
		else {
			if (num[0]) num[0] --, putchar('A');
			else if (num['C' - 'A']) num['C' - 'A'] --, putchar('C');
			else if (num['G' - 'A']) num['G' - 'A'] --, putchar('G');
			else if (num['T' - 'A']) num['T' - 'A'] --, putchar('T');
		}
	}
	return 0;
}

/*

*/