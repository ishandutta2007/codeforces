#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
struct T {
	int a; ll b;
} a[maxn];
inline ll cross(T a, T b) {
	return a.a * b.b - a.b * b.a;
}
inline T sub(T a, T b) {
	return {a.a - b.a, a.b - b.b};
}
inline ll cross(T a, T b, T c) {
	return cross(sub(b, a), sub(c, a));
}
inline bool cmp0(const T & x, const T & y) {
	return x.a == y.a ? x.b < y.b : x.a < y.a;
}
int x[maxn], y[maxn];
int n;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) {
		cin >> x[i] >> y[i];
		a[i] = {x[i], y[i] - (ll) x[i] * x[i]};
	}
	std::sort(a + 1, a + n + 1, cmp0);
	static T st[maxn]; int top = 0;
	rep(i, 1, n) if(a[i].a != a[i + 1].a || i == n) {
		for(;top > 1 && cross(st[top - 1], st[top], a[i]) >= 0;) -- top;
		st[++top] = a[i];
	}
	cout << top - 1 << '\n';
}