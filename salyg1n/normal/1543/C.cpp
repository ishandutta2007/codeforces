#include <iostream>
#include <iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include <deque>
#include <string>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define range(i, n) for(ll i = 0; i < n; ++i)
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define print(a) for (auto& i : a) cout << i << " ";
#define input(a) for (auto& i : a) cin >> i;

//#define _GLIBCXX_DEBUG
//#define DEBUG

using namespace std;

ld eps = 1e-7;

ld f(ld c, ld m, ld p, ld v, int k = 0, ld ver = 1) {
	if (p <= eps)
		return 0;
	ld res = 0;
	//berem c
	if (c > eps) {
		if (c <= v) {
			if (m > eps)
				res += f(0, m + c / 2, p + c / 2, v, k + 1, ver * c);
			else
				res += f(0, 0, 1, v, k + 1, ver * c);
		}
		else {
			if (m > eps)
				res += f(c - v, m + v / 2, p + v / 2, v, k + 1, ver * c);
			else
				res += f(c - v, 0, p + v, v, k + 1, ver * c);
		}
	}

	//berem m
	if (m > eps) {
		if (m <= v) {
			if (c > eps)
				res += f(c + m / 2, 0, p + m / 2, v, k + 1, ver * m);
			else
				res += f(0, 0, 1, v, k + 1, ver * m);
		}
		else {
			if (c > eps)
				res += f(c + v / 2, m - v, p + v / 2, v, k + 1, ver * m);
			else
				res += f(0, m - v, p + v, v, k + 1, ver * m);
		}
	}

	//berem p
	res += ver * p * (k + 1);
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ld c, m, p, v;
		cin >> c >> m >> p >> v;
		cout << setprecision(20) << fixed;
		cout << f(c, m, p, v) << "\n";
	}
	return 0;
}