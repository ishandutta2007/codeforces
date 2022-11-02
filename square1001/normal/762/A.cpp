#include <bits/stdc++.h>
using namespace std;
std::map<unsigned long long, unsigned> prime_factorize(unsigned long long x) {
	std::map<unsigned long long, unsigned> ret;
	for (unsigned i = 2; 1ULL * i * i <= x; i++) {
		while (x % i == 0) x /= i, ret[i]++;
	}
	if (x != 1) ret[x]++;
	return ret;
}
std::vector<unsigned long long> calc_divisors(unsigned long long x) {
	std::map<unsigned long long, unsigned> res = prime_factorize(x);
	std::vector<unsigned long long> ret; ret.push_back(1);
	for (std::pair<unsigned long long, unsigned> w : res) {
		int s = ret.size();
		unsigned long long mul = 1;
		for (int i = 0; i < w.second; i++) {
			mul *= w.first;
			for (int j = 0; j < s; j++) ret.push_back(ret[j] * mul);
		}
	}
	sort(ret.begin(), ret.end());
	return ret;
}
long long n; int m;
int main() {
	cin >> n >> m; m--;
	vector<unsigned long long> ret = calc_divisors(n);
	if(ret.size() <= m) cout << -1 << endl;
	else cout << ret[m] << endl;
	return 0;
}