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
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n = 2000000;
	vector<bool> pr(n, true);
	pr[0] = pr[1] = false;
	for (int i = 2; i < n; i++)
		if (pr[i])
			for (int j = i * 2; j < n; j += i)
				pr[j] = false;
	vector<int> pi(n);
	for (int i = 1; i < n; i++)
		pi[i] = pi[i - 1] + pr[i];
	vector<int> rub(n);
	for (int i = 1; i < n; i++) {
		vector<int> v;
		for (int x = i; x; x /= 10)
			v.push_back(x % 10);
		bool pal = true;
		for (int j = 0; j < v.size(); j++)
			if (v[j] != v[v.size() - 1 - j])
				pal = false;
		rub[i] = rub[i - 1] + pal;
	}
	int p, q; cin >> p >> q;
	int ans;
	for (int i = 0; i < n; i++)
		if ((ll)pi[i] * q <= (ll)rub[i] * p)
			ans = i;
	cout << ans << endl;
}