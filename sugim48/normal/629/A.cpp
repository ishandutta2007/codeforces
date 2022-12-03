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
	int N; cin >> N;
	vector<string> a(N);
	for (int y = 0; y < N; y++)
		cin >> a[y];
	int ans = 0;
	for (int y = 0; y < N; y++) {
		int n = 0;
		for (int x = 0; x < N; x++)
			if (a[y][x] == 'C')
				n++;
		ans += n * (n - 1) / 2;
	}
	for (int x = 0; x < N; x++) {
		int n = 0;
		for (int y = 0; y < N; y++)
			if (a[y][x] == 'C')
				n++;
		ans += n * (n - 1) / 2;
	}
	cout << ans << endl;
}