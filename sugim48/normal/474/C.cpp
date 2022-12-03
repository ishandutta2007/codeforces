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

void rotate(int& x, int& y, int a, int b) {
	x -= a; y -= b;
	int tmp = x;
	x = -y; y = tmp;
	x += a; y += b;
}

void hoge(int k, int& x, int& y, int a, int b) {
	while (k--) rotate(x, y, a, b);
}

bool check(vector<int>& x, vector<int>& y) {
	vector<ll> v;
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 4; j++) {
			ll dx = x[i] - x[j], dy = y[i] - y[j];
			v.push_back(dx * dx + dy * dy);
		}
	sort(v.begin(), v.end());
	ll l = v[0];
	if (l == 0) return false;
	return v[0]==l && v[1]==l && v[2]==l && v[3]==l && v[4]==l*2 && v[5]==l*2;
}

int main() {
	int n; cin >> n;
	while (n--) {
		vector<int> x(4), y(4), a(4), b(4);
		int ans = INT_MAX;
		for (int i = 0; i < 4; i++)
			cin >> x[i] >> y[i] >> a[i] >> b[i];
		for (int k = 0; k < 256; k++) {
			vector<int> X = x, Y = y;
			int K = k, cnt = 0;
			for (int i = 0; i < 4; i++) {
				cnt += K % 4;
				hoge(K % 4, X[i], Y[i], a[i], b[i]);
				K /= 4;
			}
			if (check(X, Y)) ans = min(ans, cnt);
		}
		cout << (ans < INT_MAX ? ans : -1) << endl;
	}
}