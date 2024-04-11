#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
#define Rof(i, a, b) for (i = a; i >= b; i--)
#define Inc(x) for (; x <= n; x += x & -x)
#define Dec(x) for (; x; x -= x & -x)
using namespace std;
inline int read() {
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}
typedef long long ll; const int N = 1e6 + 5;
int n, a[N], T[N]; ll ans;
void change(int x, int v) {
	Inc(x) T[x] += v;
}
int ask(int x) {
	int res = 0; Dec(x) res += T[x]; return res;
}
int main() {
	int i; n = read(); For (i, 1, n) a[i] = read();
	Rof (i, n, 1) ans += ask(a[i] - 1), change(a[i], 1);
	puts(abs(ans - n * 3) & 1 ? "Um_nik" : "Petr");
	return 0;
}