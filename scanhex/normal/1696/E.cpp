#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

const int mod = 1e9 + 7;

int mu(int a, int b) {
	 return (nagai) a * b % mod;
}

void ad(int& a, int b) {
	if ((a += b) >= mod) a -= mod;
}

void sub(int& a, int b) {
	 if ((a -= b) < 0) a += mod;
}

int pw(int a, nagai b, int c = 1) {
	for(; b; a = mu(a, a), b /= 2) if (b & 1) c = mu(c, a);
	return c;
}

int dv(int a, int b) {
	return mu(a, pw(b, mod - 2)) ;
}

const int N=400400;
int fact[N];
int rfact[N];

int binom(int n, int k) {
	return mu(fact[n], mu(rfact[k], rfact[n - k]));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fact[0] = 1;
	for(int i = 0; i + 1 < N; ++i) 
		fact[i + 1] = mu(fact[i], i + 1);
	rfact[N - 1] = dv(1, fact[N-1]);
	for(int i = N - 1; i > 0; --i) 
		rfact[i - 1] = mu(rfact[i], i);
	int n;
	cin >> n;
	++n;
	vector<int>a(n);
	for(auto&x : a)
		cin >> x;
	int res = 0;
	for(int i = 0; i < n; ++i) {
		ad(res, binom(i + a[i], a[i] - 1));
	}
	cout << res << '\n';
}