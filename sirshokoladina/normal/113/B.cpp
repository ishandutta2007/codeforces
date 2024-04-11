#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)

long long m1 = 1000000007;
long long m2 = 1000000009;
long long p = 239;

long long h1[2010][2010], h2[2010][2010];
long long h1b, h2b, h1c, h2c;

vector<pair<long long, long long> > q;

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	string a, b, c;
	cin >> a >> b >> c;
	forn (i, a.size()) {
		h1[i][i] = h2[i][i] = 0;
		for (int j = i + 1; j <= a.size(); j++) {
			h1[i][j] = (h1[i][j - 1] * p + a[j - 1]) % m1;
			h2[i][j] = (h2[i][j - 1] * p + a[j - 1]) % m2;
		}
	}
	h1c = h2c = h1b = h2b = 0;
	forn (i, b.size()) {
		h1b = (h1b * p + b[i]) % m1;
		h2b = (h2b * p + b[i]) % m2;
	}
	forn (i, c.size()) {
		h1c = (h1c * p + c[i]) % m1;
		h2c = (h2c * p + c[i]) % m2;
	}
	forn (i, a.size()) {
		forn (j, a.size() + 1) {
			if (j - i >= (int)max(b.size(), c.size())) {
				if (h1[i][i + b.size()] == h1b && h2[i][i + b.size()] == h2b) {
					if (h1[j - c.size()][j] == h1c && h2[j - c.size()][j] == h2c) {
						q.push_back(make_pair(h1[i][j], h2[i][j]));
					}
				}
			}
		}
	}
	sort(q.begin(), q.end());
	int k = 0;
	forn(i, q.size()) {
		if (k == 0 || q[k - 1] != q[i]) {
			q[k] = q[i];
			k++;
		}
	}
	cout << k;
	return 0;
}