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
struct edge { int u, v; ll w; };

ll MOD = 1000000007;

bool is_prime(int x) {
	if (x == 1) return false;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int main() {
	int n; cin >> n;
	vector<int> v;
	if (n <= 5) v.push_back(n);
	else {
		int x;
		for (x = 4; !is_prime(n - x); x += 2);
		v.push_back(n - x);
		int y;
		for (y = 2; !is_prime(y) || !is_prime(x - y); y++);
		v.push_back(y);
		v.push_back(x - y);
	}
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;
}