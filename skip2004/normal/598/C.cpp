#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef __float128 f128;
typedef long double db;
typedef long long ll;
typedef unsigned u32;
const int N = 100100;
const db pi = acosl(-1);
int n;
struct pt {
	int a, b, id;
	inline ll abs() const { return (ll) a * a + (ll) b * b; }
};
pt a[N];
inline f128 sqr(f128 x) {
	return x >= 0 ? x * x : - x * x;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	rep(i, 1, n) {
		cin >> a[i].a >> a[i].b;
		a[i].id = i;
	}
	std::sort(a + 1, a + n + 1, [](const pt & x, const pt & y) {
		return atan2l(x.b, x.a) < atan2l(y.b, y.a);
	});
	f128 max = -1. / 0;
	int A = 1, B = 2;
	rep(i, 1, n) {
		const pt x = a[i], y = a[i % n + 1];
		f128 delt = sqr((ll) x.a * y.a + (ll) x.b * y.b) / x.abs() / y.abs();
		if(delt > max) {
			max = delt;
			A = x.id;
			B = y.id;
		}
	}
	cout << A << ' ' << B << '\n';
}