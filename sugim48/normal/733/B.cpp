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

#define rep(i, N) for (int i = 0; i < N; i++)

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int N; cin >> N;
	vector<int> a(N), b(N);
	rep(i, N) cin >> a[i] >> b[i];
	int A = 0, B = 0;
	rep(i, N) A += a[i], B += b[i];
	int ma = abs(A - B), index = -1;
	rep(i, N) {
		int x = abs((A - a[i] + b[i]) - (B - b[i] + a[i]));
		if (x > ma) {
			ma = x;
			index = i;
		}
	}
	cout << index + 1 << endl;
}