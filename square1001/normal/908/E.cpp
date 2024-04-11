#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int mod = 1000000007;
int main() {
	int n, m;
	cin >> m >> n;
	vector<vector<int> > stirling(m + 1, vector<int>(m + 1, 0));
	stirling[1][1] = 1;
	for (int i = 2; i <= m; ++i) {
		for (int j = 1; j <= i; ++j) {
			stirling[i][j] = (1LL * stirling[i - 1][j] * j + stirling[i - 1][j - 1]) % mod;
		}
	}
	vector<int> bell(m + 1);
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= i; ++j) {
			bell[i] = (bell[i] + stirling[i][j]) % mod;
		}
	}
	vector<long long> v(m, 0);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == '1') v[j] |= 1LL << i;
		}
	}
	map<int, int> d;
	for (int i = 0; i < m; ++i) {
		++d[v[i]];
	}
	int mul = 1;
	for (pair<int, int> i : d) {
		mul = 1LL * mul * bell[i.second] % mod;
	}
	cout << mul << '\n';
	return 0;
}