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
	int N; cin >> N;
	vector<int> x(N + 1), y(N + 1);
	for (int i = 0; i <= N; i++)
		cin >> x[i] >> y[i];
	vector<int> dx(N), dy(N);
	for (int i = 0; i < N; i++) {
		dx[i] = x[i + 1] - x[i];
		dy[i] = y[i + 1] - y[i];
	}
	int a = 0, b = 0;
	for (int i = 0; i < N; i++) {
		int j = (i + 1) % N;
		if (dx[i] * dy[j] - dx[j] * dy[i] > 0) a++;
		else b++;
	}
	cout << min(a, b) << endl;
}