#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> par;
typedef pair <ll, ll> parll;
int const INF = 1e9 + 7;
ll const LLINF = 1e18 + 7;
ld const eps = 1e-8;
ld const PI = acos(-1);
ll const PH = 257;
ll const mod = 65536;
bool operator == (par a, par b) {
	return (a.first == b.first && a.second == b.second);
}
par operator + (par a, par b) {
	return{ a.first + b.first, a.second + b.second };
}
par operator - (par a, par b) {
	return{ a.first - b.first, a.second - b.second };
}
bool operator < (par const& a, par const& b) {
	return a.first < b.first || (a.first == b.first && a.second < b.second);
	return false;
}
istream& operator >> (istream& in, par & a) {
	return (in >> a.first >> a.second);
}
ostream& operator << (ostream& ou, par a) {
	return (ou << a.first << " " << a.second << endl);
}

namespace std {
	template <>
	struct hash <par> {
		std::size_t operator ()(const par& a) const {
			using std::size_t;
			using std::hash;
			return size_t(1LL * hash<int>()(a.first) * PH + 1LL * hash<int>()(a.second)) % mod;
		}
	};
}

inline ll randll() {
	ll res = rand();
	for (int i = 0; i < 3; i++) {
		res <<= 16;
		res += rand();
	}
	return res;
}
inline ll log(ll a, ll b) {
	return ll(log2(a) / log2(b));
}

int a[300100];

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
//	freopen("quack.in", "r", stdin);
//	freopen("quack.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	if (n % 2 || n < 6) cout << 0; else cout << (n / 2 - 1) / 2;
	return 0;
}