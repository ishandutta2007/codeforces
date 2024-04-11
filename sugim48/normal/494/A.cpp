#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <fstream>
#include <list>
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
	string s; cin >> s;
	int n = s.length();
	int j;
	for (j = n - 1; s[j] != '#'; j--);
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		a[i] = (s[i] == '(' ? 1 : -1);
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (i != j)
			sum += a[i];
	a[j] = -sum;
	if (a[j] >= 0) {
		cout << -1 << endl;
		return 0;
	}
	int x = 0;
	for (int i = 0; i < n; i++) {
		x += a[i];
		if (x < 0) {
			cout << -1 << endl;
			return 0;
		}
	}
	for (int i = 0; i < n; i++)
		if (s[i] == '#')
			cout << -a[i] << endl;
}