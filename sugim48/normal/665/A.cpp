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
	int a, ta; cin >> a >> ta;
	int b, tb; cin >> b >> tb;
	int hh, mm; scanf("%d:%d", &hh, &mm);
	int x1 = hh * 60 + mm, x2 = x1 + ta;
	int cnt = 0;
	for (int t1 = 300; t1 < 1440; t1 += b) {
		int t2 = t1 + tb;
		if (t1 < x2 && x1 < t2) cnt++;
	}
	cout << cnt << endl;
}