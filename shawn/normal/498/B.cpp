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

DB quick_power(DB a, int b) {
	DB ret = 1.;
	while (b) {
		if (b & 1) ret *= a;
		a *= a;
		b >>= 1;
	}
	return ret;
}

DB f[5010][5010], p[5010], ans; 
int t[5010], n, m;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi(), m = rdi();
	For(i, 1, n) p[i] = rdi(), p[i] /=  100, t[i] = rdi();
	f[0][0] = 1; 
	For(i, 1, n) {
		double pow = quick_power(1 - p[i], t[i]), sum = 0;		
		For(j, 1, m) {
			sum += f[i - 1][j - 1];
			if (j - 1 >= t[i]) sum -= f[i - 1][j - t[i] - 1] * pow;
			f[i][j] = sum * p[i];
			if (j >= t[i]) f[i][j] += f[i - 1][j - t[i]] * pow;
			sum *= (1 - p[i]);
			ans += f[i][j];
		}
	}
	printf("%.10lf", ans); 
	return 0;
}