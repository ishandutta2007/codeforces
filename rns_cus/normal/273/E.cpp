#include <bits/stdc++.h>

using namespace std;

#define N 1010
#define mod 1000000007
typedef long long LL;

int a[N], val[N], cnt;
int flag[5], T;

inline void add(int &x, int y) { x += y; if(x >= mod) x -= mod; }

int calc(int x, int y) {
	flag[x] = ++ T;
	flag[y] = T;
	int rt = 0;
	while(flag[rt] == T) rt ++;
	return rt;
}

void init() {
	a[cnt ++] = 2;
	val[cnt] = 1; a[cnt ++] = 3;
	int cur = 4;
	while(1) {
		if(cur > mod) break;
		int x = cur / 3, y = cur - x;
		int lx = lower_bound(a, a + cnt, x) - a;
		int ly = lower_bound(a, a + cnt, y) - a;
		int t = calc(val[lx], val[ly]);
		LL tmp = min(a[lx] * 3LL + 2, 0LL + a[ly] + a[ly] / 2);
		if(tmp > mod) tmp = mod;
		int nxt = (int)tmp;
		if(t == val[cnt - 1]) {
			a[cnt - 1] = nxt;
		} else {
			val[cnt] = t;
			a[cnt ++] = nxt;
		}
		cur = nxt + 1;
	}
}

int n, p;
LL c[3];
int f[2][2][N];

void run() {
	for(int i = 0; i < cnt; i ++) {
		int en = min(a[i], p);
		int st = 0;
		if(i) st = a[i - 1];
		c[val[i]] += 1LL * (p - en + p - st - 1) * (en - st) / 2;
		if(a[i] >= p) break;
	}
	for(int i = 0; i < 3; i ++) c[i] %= mod;
	f[0][0][0] = 1;
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j < 2; j ++) for(int k = 0; k < 2; k ++) {
			add(f[j][k][i], c[0] * f[j][k][i - 1] % mod);
			add(f[j][k][i], c[1] * f[j ^ 1][k][i - 1] % mod);
			add(f[j][k][i], c[2] * f[j][k ^ 1][i - 1] % mod);
		}
	}
	int rt = 0;
	add(rt, f[0][1][n]);
	add(rt, f[1][0][n]);
	add(rt, f[1][1][n]);
	cout << rt << endl;
}

int main() {
	init();
	scanf("%d %d", &n, &p);
	run();
	return 0;
}