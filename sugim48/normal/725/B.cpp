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
	char c = s.back();
	s.pop_back();
	stringstream ss(s);
	ll x; ss >> x;
	x--;
	ll ans;
	if (x % 2 == 0) ans = x / 4 * 16;
	else ans = x / 4 * 16 + 7;
	if (c == 'f') ans += 1;
	if (c == 'e') ans += 2;
	if (c == 'd') ans += 3;
	if (c == 'a') ans += 4;
	if (c == 'b') ans += 5;
	if (c == 'c') ans += 6;
	cout << ans << endl;
}