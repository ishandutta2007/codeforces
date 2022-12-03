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

int a[6][3] = {{0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,0,1}, {2,1,0}};

vector<int> swp(vector<int>& v, int x) {
	vector<int> _v(3);
	for (int j = 0; j < 3; j++) _v[j] = v[a[x][j]];
	return _v;
}

bool check(vector<int>& x, vector<int>& y, vector<int>& z) {
	vector<ll> v;
	for (int i = 0; i < 8; i++)
		for (int j = i + 1; j < 8; j++) {
			ll dx = x[i] - x[j], dy = y[i] - y[j], dz = z[i] - z[j];
			v.push_back(dx * dx + dy * dy + dz * dz);
		}
	sort(v.begin(), v.end());
	ll l = v[0];
	if (l == 0) return false; // _d
	return v[0]==l && v[11]==l && v[12]==l*2 && v[23]==l*2 && v[24]==l*3 && v[27]==l*3;
}

int main() {
	vector< vector<int> > v(8, vector<int>(3));
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 3; j++) cin >> v[i][j];
	for (int x = 0; x < 279936; x++) {
		vector< vector<int> > _v(8);
		_v[0] = v[0];
		int _x = x;
		for (int i = 1; i < 8; i++) {
			_v[i] = swp(v[i], _x % 6);
			_x /= 6;
		}
		vector<int> x(8), y(8), z(8);
		for (int i = 0; i < 8; i++) {
			x[i] = _v[i][0];
			y[i] = _v[i][1];
			z[i] = _v[i][2];
		}
		if (check(x, y, z)) {
			cout << "YES" << endl;
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 3; j++)
					cout << _v[i][j] << ' ';
				cout << endl;
			}
			return 0;
		}
	}
	cout << "NO" << endl;
}