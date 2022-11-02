#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 11;
using ll = long long;
int Mod;

struct Mat {
	ll a[2][2];
	ll* operator [](int i) {
		return a[i];
	}
	Mat operator *(Mat m) {
		Mat r;
		for(int i = 0; i < 2; i ++)
			for(int j = 0; j < 2; j ++) {
				r[i][j] = 0;
				for(int k = 0; k < 2; k ++) {
					r[i][j] += (*this)[i][k] * m[k][j];
					r[i][j] %= Mod;
				}
			}
		return r;
	}
}e;

Mat qpow(Mat a, ll b) {
	Mat r = e;
	for(; b; b /= 2) {
		if(b & 1)
			r = r * a;
		a = a * a;
	}
	return r;
}

ll fib(ll n) {
	Mat m;
	m[0][0] = 0;
	m[0][1] = m[1][0] = m[1][1] = 1;
	m = qpow(m, n);
	return m[0][1];
}

ll f(ll n) {
	Mat m;
	m[0][0] = 1; m[0][1] = 0;
	m[1][0] = -1; m[1][1] = 3;
	m = qpow(m, n);
	return (m[1][0] + m[1][1]) % Mod;
}

ll solve(ll sum, ll mi, ll ma, ll n) {
	ll mid = sum - mi - ma;
	return ((sum + mid) * f(n) - mid) % Mod;
}

int a[N];

int main() {
	e[0][0] = e[1][1] = 1;
	e[0][1] = e[1][0] = 0;
	
	int n; ll x, y;
	cin >> n >> x >> y >> Mod;
	for(int i = 0; i < n; i ++)
		scanf("%d", a + i);
	if(n == 1) {
		cout << a[0] % Mod << '\n';
		return 0;
	}

	ll sum = solve(accumulate(a, a + n, 0LL) % Mod, a[0], a[n - 1], x);
	ll ma = (fib(x) * a[n - 2] + fib(x + 1) * a[n - 1]) % Mod;
	ll ans = solve(sum, a[0], ma, y);
	cout << (ans + Mod) % Mod << '\n';
	return 0;
}