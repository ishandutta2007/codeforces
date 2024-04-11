#define _USE_MATH_DEFINES
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
struct edge { int v, c; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n; cin >> n;
	vector<ll> v(n), d(n), p(n);
	for (int i = 0; i < n; i++)
		cin >> v[i] >> d[i] >> p[i];
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		a[i] = i;
	vector<int> ans;
	while (!a.empty()) {
		int i = a[0];
		ans.push_back(i);
		for (int j = 1; j < a.size() && j <= v[i]; j++)
			p[j] -= v[i] + 1 - j;
		ll x = 0;
		vector<int> _a;
		vector<ll> _p;
		for (int j = 1; j < a.size(); j++) {
			int i = a[j];
			p[j] -= x;
			if (p[j] < 0) x += d[i];
			else {
				_a.push_back(i);
				_p.push_back(p[j]);
			}
		}
		a = _a;
		p = _p;
	}
	cout << ans.size() << endl;
	for (int k = 0; k < ans.size(); k++)
		cout << ans[k] + 1 << ' ';
	cout << endl;
}