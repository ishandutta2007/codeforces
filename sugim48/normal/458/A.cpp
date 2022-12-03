#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <deque>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ll_i;
struct edge { int u, v; ll w; };

ll a[100000], b[100000], c[100000], sum[100001];

int main() {
	string s, t; cin >> s >> t;
	int S = s.length(), T = t.length();
	for (int i = 0; i < 100000; i++) {
		if (i + S - 100000 >= 0)
			a[i] = (s[i + S - 100000] == '0') ? 0 : 1;
		if (i + T - 100000 >= 0)
			b[i] = (t[i + T - 100000] == '0') ? 0 : 1;
		c[i] = a[i] - b[i];
		sum[0] += c[i];
	}
	for (int i = 1; i <= 100000; i++) sum[i] = sum[i - 1] - c[i - 1];
	char ans = '?';
	for (int i = 0; i < 99998; i++) {
		if (c[i] > 0 && c[i] > -c[i + 1] && c[i] + c[i + 1] + sum[i + 2] > 0) {
			ans = '>';
			break;
		}
		if (c[i] < 0 && c[i] < -c[i + 1] && c[i] + c[i + 1] + sum[i + 2] < 0) {
			ans = '<';
			break;
		}
		c[i + 1] += c[i];
		c[i + 2] += c[i];
	}
	if (ans != '?') {
		cout << ans << endl;
		return 0;
	}
	double x = c[99998] * 1.61803398874989484820 + c[99999];
	if (x < 0) ans = '<';
	else if (x > 0) ans = '>';
	else ans = '=';
	cout << ans << endl;
}