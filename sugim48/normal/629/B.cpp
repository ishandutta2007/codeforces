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
	vector<int> m(366), f(366);
	int N; cin >> N;
	while (N--) {
		string s; int a, b;
		cin >> s >> a >> b;
		a--;
		if (s == "M")
			for (int i = a; i < b; i++)
				m[i]++;
		if (s == "F")
			for (int i = a; i < b; i++)
				f[i]++;
	}
	int ma = 0;
	for (int i = 0; i < 366; i++)
		ma = max(ma, min(m[i], f[i]));
	cout << ma * 2 << endl;
}