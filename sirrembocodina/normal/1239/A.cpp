#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

#define pb push_back

const int mod = 1000000007;

int f(int n) {
	vector<vector<int>> d(n, vector<int>(2, 0));
	d[0][0] = d[0][1] = 1;
	for (int i = 1; i < n; ++i) {
		forn (j, 2) {
			d[i][j] += d[i - 1][1 - j];
			d[i][j] %= mod;
			if (i > 1) {
				d[i][j] += d[i - 2][1 - j];
				d[i][j] %= mod;
			} else {
				d[i][j] += 1;
				d[i][j] %= mod;
			}
//			cerr <<d[i][j] << " ";
		}
//		cerr<< endl;
	}
	return (d[n - 1][0] + d[n - 1][1]) % mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n, m;
    cin >> n >> m;
    cout << ((f(n) + f(m)) % mod - 2 + mod) % mod << endl;
//    cerr << f(n) << " " << f(m) << endl;
}