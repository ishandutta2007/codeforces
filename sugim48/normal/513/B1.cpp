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
struct edge { int u; ll V; int v; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n; ll m;
	cin >> n >> m;
	m--;
	vector<int> v;
	v.push_back(n - 1);
	for (int i = n - 2; i >= 0; i--) {
		if ((m >> (n - i - 2)) & 1)
			v.push_back(i);
		else
			v.insert(v.begin(), i);
	}
	for (int i = 0; i < n; i++)
		cout << v[i] + 1 << ' ';
	cout << endl;
}