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
short INF = 20000;
double EPS = 1e-10;

int main() {
	int N; cin >> N;
	int y = 0;
	while (N--) {
		int d; cin >> d;
		string s; cin >> s;
		if (s[0] == 'S') {
			y += d;
			if (y > 20000) {
				cout << "NO" << endl;
				return 0;
			}
		}
		if (s[0] == 'N') {
			y -= d;
			if (y < 0) {
				cout << "NO" << endl;
				return 0;
			}
		}
		if (s[0] == 'E' || s[0] == 'W')
			if (y == 0 || y == 20000) {
				cout << "NO" << endl;
				return 0;
			}
	}
	cout << (y == 0 ? "YES" : "NO") << endl;
}