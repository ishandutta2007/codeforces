#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <fstream>
#include <list>
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
struct edge { ll B, T, F, P; };

unsigned MOD = 1234567891;
ll _MOD = 1000000009;
double EPS = 1e-10;
int UNKO = INT_MAX;

ll f(int n, ll lb, ll ub) {
	if (n > ub - lb - 1) return UNKO;
	ll x = -n / 2;
	x = max(x, lb + 1);
	x = min(x, ub - n);
	return x;
}

int main() {
	int n, k; cin >> n >> k;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		if (s == "?") a[i] = UNKO;
		else {
			stringstream ss(s);
			ss >> a[i];
		}
	}
	for (int i = 0; i < k; i++) {
		ll lb = INT_MIN;
		for (int l = i; l < n; l += k) {
			if (a[l] != UNKO) {
				lb = a[l];
				continue;
			}
			int r = 0;
			for (r = l; r < n && a[r] == UNKO; r += k);
			ll ub = (r < n ? a[r] : INT_MAX);
			ll x = f((r - l) / k, lb, ub);
			if (x == UNKO) {
				cout << "Incorrect sequence" << endl;
				return 0;
			}
			for (r = l; r < n && a[r] == UNKO; r += k)
				a[r] = x++;
		}
	}
	for (int i = 0; i < k; i++)
		for (int l = i; l + k < n; l += k)
			if (a[l] >= a[l + k]) {
				cout << "Incorrect sequence" << endl;
				return 0;
			}
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}