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
#include <random>
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
typedef pair<int, ll> i_ll;
struct edge { int u, v; ll w; };

ll INF = LLONG_MAX / 2;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	set<int> st;
	map<int, int> mp;
	int N; cin >> N;
	while (N--) {
		int x; scanf("%d", &x);
		auto it = st.insert(x).first;
		int ma = 0, y = -1;
		if (it != st.begin()) {
			it--;
			int h = mp[*it] + 1;
			if (h > ma) {
				ma = h;
				y = *it;
			}
			it++;
		}
		it++;
		if (it != st.end()) {
			int h = mp[*it] + 1;
			if (h > ma) {
				ma = h;
				y = *it;
			}
		}
		it--;
		mp[*it] = ma;
		if (y != -1) printf("%d ", y);
	}
	cout << endl;
}