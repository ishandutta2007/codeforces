#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
typedef pair<int, char> i_c;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n, q; cin >> n >> q;
	map<int, i_c> m;
	string S; cin >> S;
	for (int i = 0; i < n; i++)
		m[i] = i_c(i + 1, S[i] - 'a');
	while (q--) {
		int l, r, k; cin >> l >> r >> k;
		l--;
		auto it = m.upper_bound(l); it--;
		int x = it->first, y = it->second.first;
		char c = it->second.second;
		if (x < l) {
			m.erase(it);
			m[x] = i_c(l, c);
			m[l] = i_c(y, c);
		}
		it = m.upper_bound(r); it--;
		x = it->first, y = it->second.first;
		c = it->second.second;
		if (x < r) {
			m.erase(it);
			m[x] = i_c(r, c);
			m[r] = i_c(y, c);
		}
		vector<int> a(26);
		for (auto it = m.lower_bound(l); it != m.end() && it->second.first <= r;) {
			int x = it->first, y = it->second.first;
			char c = it->second.second;
			a[c] += y - x;
			m.erase(it++);
		}
		if (k) {
			int sum = l;
			for (int c = 0; c < 26; c++)
				if (a[c]) {
					m[sum] = i_c(sum + a[c], c);
					sum += a[c];
				}
		}
		else {
			int sum = l;
			for (int c = 25; c >= 0; c--)
				if (a[c]) {
					m[sum] = i_c(sum + a[c], c);
					sum += a[c];
				}
		}
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		int x = it->first, y = it->second.first;
		char c = it->second.second;
		for (int i = 0; i < y - x; i++)
			cout << (char)('a' + c);
	}
	cout << endl;
}