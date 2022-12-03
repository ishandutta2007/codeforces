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
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

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
int INF = INT_MAX / 10;
double EPS = 1e-10;

bool f(int x) {
	cout << x << endl;
	string s; cin >> s;
	return s == "yes";
}

int main() {
	vector<bool> p(51, true);
	p[0] = p[1] = false;
	for (int i = 2; i <= 50; i++)
		if (p[i])
			for (int j = i * 2; j <= 50; j += i)
				p[j] = false;
	vector<int> v;
	for (int x = 2; x <= 50; x++)
		if (p[x] && f(x))
			v.pb(x);
	if (v.size() >= 2) {
		cout << "composite" << endl;
		return 0;
	}
	if (f(4) || f(9) || f(25) || f(49)) {
		cout << "composite" << endl;
		return 0;
	}
	cout << "prime" << endl;
}