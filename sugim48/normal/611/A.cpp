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
double INF = FLT_MAX;

int a[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int b[7] = {52, 52, 52, 52, 53, 53, 52};

int main() {
	int x; string of, s; cin >> x >> of >> s;
	if (s == "week") cout << b[x - 1] << endl;
	if (s == "month") {
		int cnt = 0;
		for (int i = 0; i < 12; i++)
			if (x <= a[i])
				cnt++;
		cout << cnt << endl;
	}
}