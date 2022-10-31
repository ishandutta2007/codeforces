#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <random>
#include <set>
#include <map>
#include <deque>
#include <string>
#include <array>
#include <cassert>



using namespace std;


#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define rall(a). a.rbegin(), a.rend()



int32_t main() {
	if (1) {
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	}
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for (int i = 0; i < n; i += 1) {
			char c;
			cin >> c;
			a[i] = c - '0';
		}
		for (int i = 0; i < m; i += 1) {
			char c;
			cin >> c;
			b[i] = c - '0';
		}
		bool ok = false;
		for (int i = 0; i <= n - m; i += 1) {
			if (a[i] == b[0]) {
				ok = true;
				break;
			}
		}
		for (int i = 1; i < m; i += 1) {
			if (a[n - i] != b[m - i]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << "Yes" << "\n";
		}
		else {
			cout << "No" << "\n";
		}
	}
	return 0;
}