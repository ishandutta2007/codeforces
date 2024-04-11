#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
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

int main() {
	int n; cin >> n;
	vector<string> f(n), s(n);
	for (int i = 0; i < n; i++) cin >> f[i] >> s[i];
	vector<int> p(n);
	for (int i = 0; i < n; i++) cin >> p[i];
	string t("");
	bool flag = true;
	for (int i = 0; i < n; i++) {
		int j = p[i] - 1;
		if (f[j] > s[j]) swap(f[j], s[j]);
		if (t < f[j])
			t = f[j];
		else if (t < s[j])
			t = s[j];
		else {
			flag = false;
			break;
		}
	}
	cout << (flag ? "YES" : "NO") << endl;
}