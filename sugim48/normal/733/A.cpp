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
	string s; cin >> s;
	int N = s.length();
	vector<int> a;
	a.push_back(-1);
	for (int i = 0; i < N; i++) {
		char c = s[i];
		if (c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='Y')
			a.push_back(i);
	}
	a.push_back(N);
	int ma = 0;
	for (int k = 0; k + 1 < a.size(); k++)
		ma = max(ma, a[k + 1] - a[k]);
	cout << ma << endl;
}