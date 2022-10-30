#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[2509], op[2509], p[2509], cp[2509]; long long v[2509], vs[2509]; string s;
long long val(int l, int r) {
	if (cp[l] == cp[r - 1]) {
		long long res = 1;
		for (int i = l; i < r; i++) res *= a[i];
		return res;
	}
	long long exl = 1, exr = 1;
	for (int i = l; i < p[cp[l] + 1]; i++) exl *= a[i];
	for (int i = p[cp[r - 1]]; i < r; i++) exr *= a[i];
	return exl + exr + vs[cp[r - 1]] - vs[cp[l] + 1];
}
long long solve(int l, int r) {
	long long ret = val(l, r);
	for (int i = p[cp[l]]; i < l; i++) ret *= a[i];
	for (int i = r; i < p[cp[r - 1] + 1]; i++) ret *= a[i];
	ret += vs[cp[l]];
	ret += vs[m] - vs[cp[r - 1] + 1];
	return ret;
}
int main() {
	cin >> s;
	n = s.size() / 2 + 1;
	for (int i = 0; i < n; i++) a[i] = s[i * 2] - 48;
	for (int i = 0; i < n - 1; i++) op[i] = (s[i * 2 + 1] == '*' ? 1 : 0);
	long long mul = 1;
	for (int i = 0; i < n; i++) {
		cp[i] = m;
		mul *= a[i];
		if (i == n - 1 || op[i] == 0) {
			v[m] = mul;
			vs[m + 1] = v[m] + vs[m];
			p[++m] = i + 1;
			mul = 1;
		}
	}
	long long ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ret = max(ret, solve(i, j));
		}
	}
	cout << ret << endl;
	return 0;
}