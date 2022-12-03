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
	int N, M; cin >> N >> M;
	vector<vector<int> > a(N, vector<int>(4));
	for (int j = 0; j < M; j++)
		if (j < N * 2) a[j / 2][j % 2 * 3] = j + 1;
		else a[j / 2 - N][j % 2 + 1] = j + 1;
	for (int i = 0; i < N; i++) {
		if (a[i][1]) cout << a[i][1] << ' ';
		if (a[i][0]) cout << a[i][0] << ' ';
		if (a[i][2]) cout << a[i][2] << ' ';
		if (a[i][3]) cout << a[i][3] << ' ';
	}
	cout << endl;
}