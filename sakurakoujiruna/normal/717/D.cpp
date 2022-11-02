#include <bits/stdc++.h>
using namespace std;

vector <double> mul(vector <double> a, vector <double> b) {
	vector <double> r(128, 0);
	for(int i = 0; i < 128; i ++)
		for(int j = 0; j < 128; j ++)
			r[i ^ j] += a[i] * b[j];
	return r;
}

vector <double> qpow(vector <double> v, int b) {
	vector <double> r(128, 0); r[0] = 1;
	for(; b; b /= 2) {
		if(b & 1)
			r = mul(r, v);
		v = mul(v, v);
	}
	return r;
}

int main() {
	ios :: sync_with_stdio(false);
	int n, x; cin >> n >> x;
	vector <double> v(128, 0);
	for(int i = 0; i <= x; i ++)
		cin >> v[i];
	auto u = qpow(v, n);
	cout << fixed << setprecision(9);
	cout << 1 - u[0] << '\n';
}