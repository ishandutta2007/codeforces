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
#include <random>
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
struct edge { int v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-8;
ll INF = LLONG_MAX / 2;

int main() {
	cout << 2000 << endl;
	for (int i = 1; i <= 1000; i++)
		cout << i << ' ' << 1 << ' ' << i << ' ' << 2 << endl;
	for (int i = 1000; i >= 1; i--)
		cout << i << ' ' << 1 << ' ' << i << ' ' << 2 << endl;
}