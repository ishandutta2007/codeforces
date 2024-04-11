#include <bits/stdc++.h>
using namespace std;

#define N 5050
#define M 2020
#define mod 1000000000

struct bigint {
	int len, num[70];

	bigint(int m = 0) {
		memset(num, 0, sizeof num);
		len = 1;
		num[1] = m;
	}
	bigint operator + (const bigint &b) {
		bigint c;
		c.len = max(len, b.len);
		int x = 0, y = 0;
		for (int i = 1; i <= c.len; i ++) {
			y = x;
			if (i <= len) y += num[i];
			if (i <= b.len) y += b.num[i];
			c.num[i] = y % mod;
			x = y / mod;
		}
		if (x) c.len ++, c.num[c.len] = x;
		return c;
	}
	void operator = (const bigint &b) {
		len = b.len;
		for (int i = 1; i <= len; i ++) num[i] = b.num[i];
	}
	bool operator < (const bigint &b) {
		if (len != b.len) return len < b.len;
		for (int i = len; i >= 1; i --) {
			if (num[i] != b.num[i]) return num[i] < b.num[i];
		}
		return 0;
	}
	void print() {
		printf("%d", num[len]);
		for (int i = len - 1; i; i --) printf("%09d", num[i]);
		puts("");
	}
} f[N], ex[M];

inline bigint max(bigint a, bigint b) {return a < b ? b : a;}

int n, x, last[M];
char s[11];

int main() {
//	freopen("d.in", "r", stdin);

	ex[0] = bigint(1);
	for (int i = 1; i <= 2000; i ++) ex[i] = ex[i-1] + ex[i-1];

	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%s %d", s, &x);
		f[i] = f[i-1];
		if (s[0] == 'w') last[x] = i;
		else if (last[x]) {
			f[i] = max(f[i], f[last[x]-1] + ex[x]);
		}
	}
	f[n].print();
	return 0;
}