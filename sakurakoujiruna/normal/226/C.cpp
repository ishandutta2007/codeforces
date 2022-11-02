#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int mod;

struct Mat {
	ll num[2][2];
	ll* operator [](int i) {
		return num[i];
	}
	Mat operator *(Mat m) {
		Mat r;
		for(int i = 0; i < 2; i ++)
			for(int j = 0; j < 2; j ++) {
				r[i][j] = 0;
				for(int k = 0; k < 2; k ++)
					r[i][j] += (*this)[i][k] * m[k][j];
				r[i][j] %= mod;
			}
		return r;
	}
};

Mat qpow(Mat a, ll b) {
	Mat r = a; b --;
	for(; b > 0; b >>= 1) {
		if(b & 1)
			r = r * a;
		a = a * a;
	}
	return r;
}

int main() {
	ios :: sync_with_stdio(false);
	ll l, r, k; cin >> mod >> l >> r >> k;
	ll g = 1;
	
	auto solve = [&](ll n) {
		for(ll i = 1; ; i = n / (n / (i + 1))) {
			if(r / i - (l - 1) / i >= k)
				g = max(g, i);
			if(i == n)
				break;
		}
	};
	solve(r);
	if(l != 1) solve(l - 1);

	Mat f;
	f[0][0] = 0;
	f[0][1] = f[1][0] = f[1][1] = 1;
	f = qpow(f, g);
	cout << f[0][1] % mod << '\n';
	return 0;
}