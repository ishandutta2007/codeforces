#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
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
struct edge { int u, v; char c; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

string f(string s, int l) {
	int n = s.length(), r = 0;
	vector<int> z(n);
	for (int i = 0, j = n - 1; i <= j; i++, j--) {
		int a = s[i] - '0', b = s[j] - '0';
		int x;
		for (x = 0; x <= 18; x++)
			if (l*10+a - 1 <= x && x <= l*10+a && (x + r) % 10 == b)
				break;
		if (x == 19) return "";
		l = l*10+a - x;
		if (i == j && (l ^ r)) return "";
		r = (x + r) / 10;
		z[i] = x;
	}
	if (n % 2 == 0 && (l ^ r)) return "";
	string t(n, ' ');
	for (int i = 0, j = n - 1; i <= j; i++, j--) {
		t[i] = '0' + (z[i] + 1) / 2;
		t[j] = '0' + z[i] / 2;
		if (i == j && z[i] % 2) return "";
	}
	if (t[0] == '0') return "";
	return t;
}

int main() {
	string s; cin >> s;
	int n = s.length();
	string t = f(s, 0);
	if (t != "") {
		cout << t << endl;
		return 0;
	}
	if (s[0] == '1') {
		t = f(s.substr(1), 1);
		if (t != "") {
			cout << t << endl;
			return 0;
		}
	}
	cout << "0" << endl;
}