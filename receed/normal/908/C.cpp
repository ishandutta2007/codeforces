#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, r;
	cin >> n >> r;
	vector<ll> x(n);
	vector<long double> y(n, (long double) r);
	cout << fixed << setprecision(10);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		for (int j = 0; j < i; j++) {
			if (abs(x[i] - x[j]) > 2 * r)
				continue;
			y[i] = max(y[i], y[j] + sqrt(4*r*r - (x[i] - x[j]) * (x[i] - x[j])));
		}
		cout << y[i] << ' ';
	}
}