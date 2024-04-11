#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, a, b) for (int i = a; i < b; i ++)
template <class T> void chkmax(T &a, T b) {if (a < b) a = b;}

#define N 1000005

int n, fs;
ll f[100], ans;

void func(ll x, ll y) {
	if (!y) return;
    ll d = __gcd(x, y);
    x /= d, y /= d;
    ll res = 0;
    f0(i, 0, fs) if (x % f[i]) swap(f[i --], f[-- fs]);
    f0(i, 0, fs) chkmax(res, y / f[i] * f[i]);
    ans += y - res;
    return func(x, res);
}

int main() {
	ll x, y, ox;
    scanf("%I64d %I64d", &x, &y);
    ox = x;
    for (int i = 2; 1ll * i * i <= x; i ++) {
        if (x % i) continue;
		f[fs ++] = i;
        while (x % i == 0) x /= i;
    }
    if (x > 1) f[fs ++] = x;
    x = ox;
    func(x, y);
	printf("%I64d\n", ans);
	return 0;
}