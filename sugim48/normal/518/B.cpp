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
struct edge { ll B, T, F, P; };

unsigned MOD = 1234567891;
ll _MOD = 1000000009;
double EPS = 1e-10;
int INF = INT_MAX / 10;

int main() {
	string s, t; cin >> s >> t;
	vector<int> a(128), b(128);
	for (int i = 0; i < s.length(); i++)
		a[s[i]]++;
	for (int j = 0; j < t.length(); j++)
		b[t[j]]++;
	int x = 0, y = 0;
	for (char C = 'A', c = 'a'; C <= 'Z' && c <= 'z'; C++, c++) {
		int K = min(a[C], b[C]), k = min(a[c], b[c]);
		a[C] -= K; b[C] -= K; x += K;
		a[c] -= k; b[c] -= k; x += k;
		y += min(a[C], b[c]) + min(a[c], b[C]);
	}
	cout << x << ' ' << y << endl;
}