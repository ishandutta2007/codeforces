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

string a, b, ans[1010][2];
int n;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	cin >> ans[0][0] >> ans[0][1];
	cin >> n;
	For(i, 1, n) {
		cin >> a >> b;
		if (ans[i - 1][0] == a) {
			ans[i][0] = b;
			ans[i][1] = ans[i - 1][1];
		}
		else {
			ans[i][1] = b;
			ans[i][0] = ans[i - 1][0];
		}
	}
	For(i, 0, n) cout << ans[i][0] << " " <<ans[i][1] << endl;
}