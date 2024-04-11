#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n) - 1; i >= 0; i--)

bool pr(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	string s;
	cin >> s;
	int n = s.size();
	vector<int> a(1, 0);
	forn (i, n + 1) {
		if (2 * i > n && pr(i)) {
			a.push_back(i - 1);
		}
	}
	int m = a.size();
	int k[26];
	char c[26];
	forn (i, 26) {
		c[i] = 'a' + i;
		k[i] = 0;
		forn (j, n) {
			if (s[j] == c[i]) {
				k[i]++;
			}
		}
	}
	int q = 0;
	forn (i, 26) {
		if (k[i] > k[q]) {
			q = i;
		}
	}
	swap(c[q], c[25]);
	swap(k[q], k[25]);
	if (k[25] < n - m) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	int j = 0, w = 0, l = 0;
	forn (i, n) {
		while (j < 26 && w == k[j]) {
			w = 0;
			j++;
		}
		if (l < m && i == a[l]) {
			cout << c[j];
			l++;
			w++;
		} else {
			cout << c[25];
		}
	}
}