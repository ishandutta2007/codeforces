#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
#include <array>
#include <string>
#include <set>
#include <map>
#include <cassert>


using namespace std;


#define ll long long
#define ld long double
#define flt double
#define bp push_back
#define emb empalce_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define prcs cout << fixed << setprecision(10)
#define nlpt nullptr


mt19937_64 rnd(132123);

ll inf = 1e18;


int n;
vector<ll> a;


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; i += 1) {
			cin >> a[i];
		}
		if (n % 2 == 1) {
			cout << "NO" << "\n";
			continue;
		}
		sort(all(a));
		int m = n / 2;
		vector<ll> x, y;
		x.reserve(m);
		y.reserve(m);
		for (int i = 0; i < m; i += 1) {
			x.push_back(a[i]);
		}
		for (int i = m; i < n; i += 1) {
			y.push_back(a[i]);
		}
		int c1 = 0;
		int c2 = 0;
		for (int i = m - 1; i >= 0 && x[i] == x[m - 1]; i -= 1) {
			c1 += 1;
		}
		for (int i = 0; i < m && y[i] == x[m - 1]; i += 1) {
			c2 += 1;
		}
		if (c1 + c2 > m) {
			cout << "NO" << "\n";
			continue;
		}
		if (c1 + c2 == m) {
			if (c1 == m) {
				cout << "YES" << "\n";
				for (int i = 0; i < m; i += 1) {
					cout << x[i] << " " << y[i] << " ";
				}
				cout << "\n";
				continue;
			}
			cout << "NO" << "\n";
			continue;
		}
		cout << "YES" << "\n";
		for (int i = 0; i < m; i += 1) {
			cout << x[i] << " " << y[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}