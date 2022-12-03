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
#include <list>
#include <numeric>
using namespace std;
 
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<int, ll> i_ll;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };
 
#define rep(i, N) for (int i = 0; i < (int)(N); i++)
#define pb push_back
 
int INF = INT_MAX / 10;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	string s; cin >> s;
	vector<int> a(26);
	for (char c: s) a[c - 'A']++;
	int k;
	for (k = 0; k < 26; k++)
		if (a[k] == 2)
			break;
	vector<int> v;
	for (int i = 0; i < 27; i++)
		if (s[i] - 'A' == k)
			v.push_back(i);
	int l = v[0], r = v[1];
	if (r - l == 1) {
		cout << "Impossible" << endl;
		return 0;
	}
	int d = l + (r - l + 1) / 2;
	int t = 0;
	vector<string> ans(2, string(13, ' '));
	for (int i = 0; i < 27; i++) {
		if (i == r) continue;
		int z = (t - d + 26) % 26;
		int y, x;
		if (z < 13) y = 1, x = 12 - z;
		else y = 0, x = z - 13;
		ans[y][x] = s[i];
		t++;
	}
	cout << ans[0] << endl;
	cout << ans[1] << endl;
}