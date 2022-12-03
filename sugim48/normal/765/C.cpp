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
#include <unordered_set>
#include <complex>
using namespace std;
 
#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int v; ll w; };
// typedef complex<double> C;
 
ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 2;
double EPS = 1e-10;

int solve(int k, int a, int b) {
	if (a < k && b < k) return -1;
	if (a < k && b % k) return -1;
	if (a % k && b < k) return -1;
	return a / k + b / k;
}

int main() {
	int k, a, b; cin >> k >> a >> b;
	cout << solve(k, a, b) << endl;
}