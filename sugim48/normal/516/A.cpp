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
int INF = INT_MAX / 4;

int p[10][4] = {
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{1, 0, 0, 0},
	{1, 1, 0, 0},
	{3, 1, 0, 0},
	{3, 1, 1, 0},
	{4, 2, 1, 0},
	{4, 2, 1, 1},
	{7, 2, 1, 1},
	{7, 4, 1, 1}
};

int main() {
	int n; cin >> n;
	string a; cin >> a;
	vector<int> q(4);
	for (int i = 0; i < n; i++) {
		int x = a[i] - '0';
		for (int j = 0; j < 4; j++)
			q[j] += p[x][j];
	}
	for (;;) {
		int x;
		if (q[3]) x = 7;
		else if (q[2]) x = 5;
		else if (q[1]) x = 3;
		else if (q[0]) x = 2;
		else break;
		cout << x;
		for (int j = 0; j < 4; j++)
			q[j] -= p[x][j];
	}
	cout << endl;
}