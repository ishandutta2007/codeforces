#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
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
	int n, m; cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int cnt = 0;
	for (int i = 0; i + 1 < n; i++)
		for (int j = 0; j + 1 < m; j++) {
			string s(4, ' ');
			s[0] = a[i][j];
			s[1] = a[i][j + 1];
			s[2] = a[i + 1][j];
			s[3] = a[i + 1][j + 1];
			sort(s.begin(), s.end());
			if (s == "acef") cnt++;
		}
	cout << cnt << endl;
}