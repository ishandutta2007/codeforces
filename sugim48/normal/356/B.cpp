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

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	ll n, m; cin >> n >> m;
	string s, t; cin >> s >> t;
	ll d = gcd(s.length(), t.length()), unko = (ll)s.length() * t.length() / d;
	vector<vector<int> > a(d, vector<int>(26)), b = a;
	for (int i = 0; i < s.length(); i++)
		a[i % d][s[i] - 'a']++;
	for (int j = 0; j < t.length(); j++)
		b[j % d][t[j] - 'a']++;
	ll sum = 0;
	for (int k = 0; k < d; k++) {
		sum += (s.length() / d) * (t.length() / d);
		for (int c = 0; c < 26; c++)
			sum -= (ll)a[k][c] * b[k][c];
	}
	cout << n / (unko / s.length()) * sum << endl;
}