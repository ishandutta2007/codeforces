#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll mod = 1000000007LL;

struct Matrix {
	ll mat[16][16];
};

Matrix matMult(Matrix a, Matrix b) {
	Matrix ans;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			ans.mat[i][j] = 0LL;
			for (int k = 0; k < 16; k++) {
				ans.mat[i][j] = (ans.mat[i][j] + a.mat[i][k]*b.mat[k][j])%mod;
			}
		}
	}
	return ans;
}

Matrix matPow(Matrix base, ll p) {
	Matrix ans;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if (i == j) ans.mat[i][j] = 1LL;
			else ans.mat[i][j] = 0LL;
		}
	}
	while (p) {
		if (p & 1) {
			ans = matMult(ans, base);
		}
		base = matMult(base, base);
		p = p/2;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	ll k;
	cin >> n >> k;
	ll a, b;
	int c;
	ll pos[16];
	pos[0] = 1LL;
	for (int i = 1; i < 16; i++) {
		pos[i] = 0LL;
	}
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		b = min(b, k);
		Matrix base;
		for (int j = 0; j < 16; j++) {
			for (int k = 0; k < 16; k++) {
				base.mat[j][k] = 0LL;
			}
		}
		for (int j = 0; j <= c; j++) {
			if (j != c) {
				base.mat[j][j+1] = 1LL;
			}
			if (j != 0) {
				base.mat[j][j-1] = 1LL;
			}
			base.mat[j][j] = 1LL;
		}
		Matrix mc = matPow(base, b-a);
		ll pos2[16];
		for (int j  = 0; j < 16; j++) {
			pos2[j] = 0LL;
		}
		for (int j = 0; j < 16; j++) {
			for (int k = 0; k < 16; k++) {
				pos2[j] = (pos2[j] + mc.mat[j][k]*pos[k])%mod;
			}
		}
		for (int j = 0; j< 16; j++) {
			pos[j] = pos2[j];
		}
	}
	ll ans = pos[0];

	cout << ans << endl;
	cin >> ans;

}