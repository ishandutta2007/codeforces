#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

const long long mod = 1000000007;

long long get_res(int n) {
	long long ret = 1;
	for (int i = 0; i < n; ++i) {
		ret *= 26;
		ret %= mod;
	}
	return ret;
}

int get_emp(vector <int>& ps, int n, int len) {
	int ret = 0;
	int rbound = 0;
	for (int i = 0; i < ps.size(); ++i) {
		if (ps[i] > rbound) {
			ret += ps[i] - rbound;
		}
		rbound = ps[i] + len;
	}
	ret += n - rbound;
	return ret;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector <int> ps(m);
	for (int i = 0; i < m; ++i) {
		cin >> ps[i];
	}

	sort(ps.begin(), ps.end());

	vector <int> z = z_function(s);

	int emp = 0;
	for (int i = 1; i < ps.size(); ++i) {
		int diff = ps[i] - ps[i - 1];
		if (diff >= s.size()) {
			continue;
		}

		int pr = z[diff];
		if (pr != s.length() - diff) {
			cout << 0 << endl;
			return 0;
		}
	}

	cout << get_res(get_emp(ps, n, s.length())) << endl;

	return 0;
}