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
int m;
string s;


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> s;
		m = n + n;
		vector<ll> p(m + 1);
		p[0] = 0;
		bool ok = true;
		int l = m;
		int r = 0;
		for (int i = 0; i < m; i += 1) {
			ll x = 0;
			if (s[i] == '(') {
				x += 1;
			}
			else {
				x -= 1;
			}
			p[i + 1] = p[i] + x;
			if (p[i + 1] < 0) {
				ok = false;
				l = min(l, i + 1);
				r = max(r, i + 1);
			}
		}
		if (ok) {
			cout << 0 << "\n";
			continue;
		}
		l -= 1;
		r += 1;
		ll mx1 = -inf;
		int mx1i = -1;
		int mx3i = -1;
		ll mx2 = -inf;
		ll mx3 = -inf;
		for (int i = 0; i <= l; i += 1) {
			if (p[i] > mx1) {
				mx1 = p[i];
				mx1i = i;
			}
		}
		for(int i = l; i < r; i += 1) {
			if (p[i] > mx2) {
				mx2 = p[i];
			}
		}
		for (int i = r; i <= m; i += 1) {
			if (p[i] > mx3) {
				mx3 = p[i];
				mx3i = i;
			}
		}
		if (mx1 + mx3 >= mx2) {
			cout << "1" << "\n";
			cout << mx1i + 1 << " " << mx3i << "\n";
			continue;
		}
		ll mx = -inf;
		ll mxi = -1;
		for (int i = 0; i <= m; i += 1) {
			if (p[i] > mx) {
				mx = p[i];
				mxi = i;
			}
		}
		cout << 2 << "\n";
		cout << 1 << " " << mxi << "\n";
		cout << mxi + 1 << " " << m << "\n";
	}
	return 0;
}

/*
1
2 3 5 4
AABAABBABAAABABBABBBABB
*/