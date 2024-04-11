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
double INF = FLT_MAX;

int main() {
	set<ll> st;
	for (int n = 1; n <= 61; n++) {
		ll x = (1LL<<n) - 1;
		for (int i = 0; i < n - 1; i++)
			st.insert(x - (1LL<<i));
	}
	ll a, b; cin >> a >> b;
	int cnt = 0;
	for (auto it = st.begin(); it != st.end(); it++) {
		ll x = *it;
		if (a<=x && x<=b) cnt++;
	}
	cout << cnt << endl;
}