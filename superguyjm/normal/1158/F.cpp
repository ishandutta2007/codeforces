#include <bits/stdc++.h>

#define LL long long
#define pii pair<int,int>
using namespace std;
const int inf = 2147483647;
const int mod = 998244353;
const int N = 3001;

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

int n, c, a[N], f[N][N], s[N][N], bin[N], inv[N], ans[N];

int add(int x, int y) {return x + y >= mod ? x + y - mod : x + y;}
int dec(int x, int y) {return x - y < 0 ? x - y + mod : x - y;}
int pow_mod(int a, int k) {
	int ans = 1;
	while(k) {
		if(k & 1) ans = (LL)ans * a % mod;
		a = (LL)a * a % mod, k /= 2;
	} return ans;
}

void solve1() {
	f[0][0] = 1; int S = bin[c] - 1;
	for(int i = 1; i <= n; i++) {
		for(int j = n / c; j >= 0; j--) {
			for(int k = S; k >= 0; k--) if(f[j][k]){
				if((k | bin[a[i]]) == S) f[j + 1][0] = add(f[j + 1][0], f[j][k]);
				else f[j][k | bin[a[i]]] = add(f[j][k | bin[a[i]]], f[j][k]);
			}
		}
	} for(int i = 0; i <= n; i++) {
		int ans = i == 0 ? ans = mod - 1 : 0;
		for(int j = 0; j <= S; j++) ans = add(ans, f[i][j]);
		put(ans), putchar(' ');
	}
}

void solve2() {
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < c; j++) s[i][j] = s[i - 1][j];
		s[i][a[i]]++;
	} f[0][0] = 1;
	for(int i = 0; i <= n; i++) {
		int tot = 0, k = 1, lst = bin[n - i];
		for(int j = i + 1; j <= n; j++) {
			int uu = s[j][a[j]] - s[i][a[j]];
			if(uu > 1) k = (LL)k * inv[uu - 1] % mod * (bin[uu] - 1) % mod;
			else tot++;
			if(tot == c) {
				k = (LL)k * inv[uu] % mod;
				lst = dec(lst, (LL)bin[n - j] * k % mod);
				for(int h = i / c; h >= 0; h--) if(f[i][h]) f[j][h + 1] = add(f[j][h + 1], (LL)f[i][h] * k % mod);
				k = (LL)k * (bin[uu] - 1) % mod;
			}
		} for(int h = i / c; h >= 0; h--) ans[h] = add(ans[h], (LL)f[i][h] * lst % mod);
	} ans[0] = dec(ans[0], 1);
	for(int i = 0; i <= n; i++) put(ans[i]), putchar(' ');
}

int main() {
	n = read(), c = read();
	for(int i = 1; i <= n; i++) a[i] = read() - 1;
	bin[0] = 1; for(int i = 1; i <= _max(n, c); i++) bin[i] = 2LL * bin[i - 1] % mod, inv[i] = pow_mod(bin[i] - 1, mod - 2);
	return c <= 9 ? solve1() : solve2(), 0;
}