#include <bits/stdc++.h>
using namespace std;
int n; string s;
int main() {
	cin >> n >> s;
	vector<int> a(n), f, invf(n);
	for(int i = 0; i < n; i++) a[i] = i;
	for(int i = 0; i < n; i++) {
		f.push_back(a[(a.size() - 1) / 2]);
		a.erase(a.begin() + (a.size() - 1) / 2);
	}
	for(int i = 0; i < n; i++) invf[f[i]] = i;
	string ret;
	for(int i = 0; i < n; i++) ret += s[invf[i]];
	cout << ret << endl;
	return 0;
}