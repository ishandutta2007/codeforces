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
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

bool check(string& s, string& t) {
	if (s[0] == '0') return false;
	if (s.length() > t.length()) return true;
	if (s.length() < t.length()) return false;
	return s > t;
}

string nine(string s) {
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '?') s[i] = '9';
	return s;
}

int main() {
	int n; cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	string prev = "0";
	for (int i = 0; i < n; i++) {
		string s = nine(a[i]);
		if (!check(s, prev)) {
			cout << "NO" << endl;
			return 0;
		}
		for (int j = 0; j < a[i].length(); j++) {
			if (a[i][j] != '?') continue;
			for (char c = '0'; c <= '9'; c++) {
				a[i][j] = c;
				string s = nine(a[i]);
				if (check(s, prev)) break;
				if (c == '9') {
					cout << "NO" << endl;
					return 0;
				}
			}
		}
		prev = a[i];
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) cout << a[i] << endl;
}