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

void output(vector< vector<int> >& v) {
	for (int h = 1; h <= 2000; h++) {
		for (int i = 0; i < v[h].size(); i++)
			cout << v[h][i] << ' ';
	}
	cout << endl;
}

int main() {
	vector< vector<int> > v(2001);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int h; cin >> h;
		v[h].push_back(i);
	}
	for (int h = 1; h <= 2000; h++) {
		if (v[h].size() < 3) continue;
		cout << "YES" << endl;
		output(v);
		swap(v[h][0], v[h][1]);
		output(v);
		swap(v[h][1], v[h][2]);
		output(v);
		return 0;
	}
	int _h = 0;
	for (int h = 1; h <= 2000; h++) {
		if (v[h].size() < 2) continue;
		if (_h == 0) {
			_h = h;
			continue;
		}
		cout << "YES" << endl;
		output(v);
		swap(v[_h][0], v[_h][1]);
		output(v);
		swap(v[h][0], v[h][1]);
		output(v);
		return 0;
	}
	cout << "NO" << endl;
}