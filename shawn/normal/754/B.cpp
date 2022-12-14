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

char ch[10][10];
int sum;

bool chk(int i, int j) {
	if (i + 2 < 4) {
		if (ch[i + 1][j] != 'o' && ch[i + 2][j] != 'o')  {
			sum += ch[i + 1][j] == '.';
			sum += ch[i + 2][j] == '.';
			if (sum <= 1) return 1;
			sum -= ch[i + 1][j] == '.';
			sum -= ch[i + 2][j] == '.';
		}
	}
	if (j + 2 < 4) {
		if (ch[i][j + 1] != 'o' && ch[i][j + 2] != 'o')  {
			sum += ch[i][j + 1] == '.';
			sum += ch[i][j + 2] == '.';
			if (sum <= 1) return 1;
			sum -= ch[i][j + 1] == '.';
			sum -= ch[i][j + 2] == '.';
		}
	}
	if (i + 2 < 4 && j + 2 < 4) {
		if (ch[i + 1][j + 1] != 'o' && ch[i + 2][j + 2] != 'o') {
			sum += ch[i + 1][j + 1] == '.';
			sum += ch[i + 2][j + 2] == '.';
			if (sum <= 1) return 1;
			sum -= ch[i + 1][j + 1] == '.';
			sum -= ch[i + 2][j + 2] == '.';
		}
	}
	if (i + 2 < 4 && j - 2 >= 0) {
		if (ch[i + 1][j - 1] != 'o' && ch[i + 2][j - 2] != 'o') {
			sum += ch[i + 1][j - 1] == '.';
			sum += ch[i + 2][j - 2] == '.';
			if (sum <= 1) return 1;
			sum -= ch[i + 1][j - 1] == '.';
			sum -= ch[i + 2][j - 2] == '.';
		}
	}
	return 0;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	For(i, 0, 3) rds(ch[i]);
	For(i, 0, 3) {
		For(j, 0, 3) {
			if (ch[i][j] != 'o') {
				sum = ch[i][j] == '.';
				if (chk(i, j)) return puts("YES"), 0;
				sum = 0;
			}
		}
	}
	return puts("NO"), 0;
}