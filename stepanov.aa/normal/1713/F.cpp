#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <random>
#include <set>
#include <map>
#include <deque>
#include <cassert>
#include <cstdlib>
#include <array>



using namespace std;


#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define emb emplace_back
#define ll long long
#define flt double


mt19937 rnd(1431243);
const ll inf = 1e18;


int n;
vector<ll> b;


vector<ll> solve(vector<ll>& b, int n) {
	if (n == 0) {
		return {};
	}
	int t1 = 0;
	while ((1ll << (t1 + 1)) <= n) {
		t1 += 1;
	}
	int m = (1 << t1);
	vector<ll> a(n, 0);
	a[0] = b[m - 1];
	for (int i = 0; i < m; i += 1) {
		a[i] = b[i ^ (m - 1)];
	}
	for (int i = 0; i < t1; i += 1) {
		for (int j = 0; j < m; j += 1) {
			if ((j >> i) & 1) {
				a[j] ^= a[j - (1 << i)];
			}
		}
	}
	if (m == n) {
		return a;
	}
	vector<ll> b1(b.begin() + m, b.end());
	int s = n - m;
	int t2 = 0;
	while ((1ll << (t2 + 1)) <= s) {
		t2 += 1;
	}
	for (int i = 0; i < s; i += 1) {
		b1[i] ^= b[i];
	}
	auto a1 = solve(b1, s);
	for (int i = 0; i < s; i += 1) {
		a[i] = a[i] ^ a1[i];
		a[i + m] = a1[i];
	}
	return a;
}



vector<ll> solve() {
	auto a = solve(b, n);
	reverse(all(a));
	return a;
}


int32_t main() {
	if (1) {
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	}
	cin >> n;
	b.resize(n);
	for (int i = 0; i < n; i += 1) {
		cin >> b[i];
	}
	auto a = solve();
	for (int i = 0; i < n; i += 1) {
		cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}