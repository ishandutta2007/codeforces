#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e9 + 7;

typedef vector <vector <ll> > mat;

void add(ll &x, ll y) {
	x = (x + y) % INF;
}

mat mult(mat a, mat b) {
	ll n = a.size();
	mat c(n, vector <ll> (n, 0));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			for (ll k = 0; k < n; k++) {
				add(c[i][j], a[i][k] * b[k][j]);
			}
		}
	}
	return c;
}

mat ones;

void get_ones(ll n) {
	ones.resize(n, vector <ll> (n, 0));
	for (ll i = 0; i < n; i++) {
		ones[i][i] = 1;
	}
}

mat power(mat a, ll k) {
	if (!k) {
		return ones;
	}
	mat b = power(a, k / 2);
	b = mult(b, b);
	if (k % 2) {
		return mult(a, b);
	} else {
		return b;
	}
}

int main() {
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	if (n < m) {
		cout << "1\n";
		return 0;
	}
	get_ones(m + 1);
	mat a(m + 1, vector <ll> (m + 1, 0));
	mat per(m + 1, vector <ll> (m + 1, 0));	
	for (ll i = 0; i <= m; i++) {
		a[0][i] = 1;
	}
	a[0][m]++;
	for (int i = 0; i < m; i++) {
		per[i + 1][i] = 1;
	}
	per[1][m] = 1;
	per[m][m] = 1;
	mat res = mult(a, power(per, n - m));
	cout << res[0][m] << "\n";
}