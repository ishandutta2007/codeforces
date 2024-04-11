#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

const int mod=998244353;
int mu(int a, int b) {
	return (nagai) a * b % mod;
}
int pw(int a, int b, int c = 1) {
	for (;b; a = mu(a, a), b >>= 1) if (b & 1) c = mu(c, a);
	return c;
}
int dv(int a, int b) {
	return mu(a, pw(b, mod - 2));
}

int C(int n, int k) {
	int res = 1;
	for(int i = n; i >= n - k + 1; --i) 
		res = mu(res, i);
	int rofl = 1;
	for(int i = 1; i <= k; ++i) 
		rofl = mu(rofl, i);
	return dv(res, rofl);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
	int t;
	cin >> t;
	/*
	for(int i = 0; i < 20; ++i) 
		for(int j = 0;j  < 20; ++j)
			if (C(i, j) == 1287) 
				cout << i << ' ' << j << '\n';
				*/

	while (t--) {
		int n; 
		cin >> n;
		string s;
		cin >> s;
		vector<int> c(2), tot(2);
		int codd = 0;
		int cur = 0;
		int cone = 0;
		char curchar = 0;
		for(int i =0;i < n; ++i) {
			if (s[i] == '1') {
				++cone;
				++cur;
				curchar = '1';
			}
			else {
				codd += cur % 2;
				cur = 0;
				curchar = 0;
			}
			if (s[i] == '0') 
				c[i % 2]++;
			tot[i % 2]++;
		}
		codd += cur % 2;
//		cerr << cone << ' ' << codd << '\n';
		cout << C(n - cone + (cone - codd) / 2, (cone - codd) / 2) << '\n';
//		cout << mu(C(tot[0], c[0]), C(tot[1], c[1])) << '\n';
	}
  return 0;
}