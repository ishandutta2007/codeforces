#include <bits/stdc++.h>
using namespace std;
long long x, y, l, r;
int main() {
	cin >> x >> y >> l >> r;
	double lx = log(x), ly = log(y), lim = log(1000000000000000000) + 0.1;
	vector<long long> vx = { 1 }, vy = { 1 };
	for(int i = 1; lx * i <= lim; i++) vx.push_back(vx.back() * x);
	for(int i = 1; ly * i <= lim; i++) vy.push_back(vy.back() * y);
	vector<long long> v = { l - 1, r + 1 };
	for(long long i : vx) {
		for(long long j : vy) {
			if(l <= i + j && i + j <= r) v.push_back(i + j);
		}
	}
	sort(v.begin(), v.end());
	long long ret = 0;
	for(int i = 1; i < v.size(); i++) ret = max(ret, v[i] - v[i - 1] - 1);
	cout << ret << endl;
	return 0;
}