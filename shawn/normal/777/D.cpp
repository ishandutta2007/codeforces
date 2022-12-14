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
const int maxn = 5e5 + 10;
string str[maxn];
int n, len, pos;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	cin >> n;
	For(i, 1, n) cin >> str[i];
	Rep(i, n - 1, 1) {
		len = str[i].length(), pos = len;
		For(j, 0, len - 1) {
			if (str[i][j] < str[i + 1][j]) break;
			if (str[i][j] > str[i + 1][j]) {
				pos = j;
				break;
			}
		}
		str[i].resize(pos);
	}
	For(i, 1, n) cout << str[i] << endl;
	return 0;
}