#include <bits/stdc++.h>

#define LL long long
#define pii pair<int,int>
using namespace std;
const int inf = 2147483647;
const int mod = 1e9 + 7;
const int N = 5001;

int _max(int x, int y) {return x > y ? x : y;}
int _min(int x, int y) {return x < y ? x : y;}
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
void put(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

int add(int x, int y) {
	x += y;
	return x >= mod ? x - mod : x;
}
int dec(int x, int y) {
	x -= y;
	return x < 0 ? x + mod : x;
}

int pow_mod(int a, int k) {
	int ans = 1;
	while(k) {
		if(k & 1) ans = (LL)ans * a % mod;
		a = (LL)a * a % mod, k /= 2;
	} return ans;
}

int a[N], f[N][N];

int main() {
	int n = read(), k = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	f[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) f[i][j] = dec((LL)f[i - 1][j] * a[i] % mod, f[i - 1][j - 1]);
		f[i][0] = (LL)f[i - 1][0] * a[i] % mod;
	} int ans = 0;
	for(int i = 0; i <= _min(n, k); i++) {
		int hh = 1; for(int j = k; j >= k - i + 1; j--) hh = (LL)hh * j % mod;
		ans = add(ans, (LL)f[n][i] * hh % mod * pow_mod(n, mod - 1 - i) % mod);
	} int hh = 1; for(int i = 1; i <= n; i++) hh = (LL)hh * a[i] % mod;
	hh = dec(hh, ans);
	put(hh), puts("");
	return 0;
}