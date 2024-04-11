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
#include <unordered_map>
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
struct edge { int u, v; ll w; };

int const MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-12;
int INF = INT_MAX / 2;

int f(int N, int x, vector<int> a, vector<int> b) {
	int t = 0, ans = 0;
	rep(i, N) {
		t += b[i];
		ans += max(0, a[i] - t * x);
	}
	return ans;
}

int main() {
	int N, x; cin >> N >> x;
	vector<int> a(N), b(N);
	rep(i, N) cin >> a[i];
	rep(i, N) cin >> b[i];
	int f1 = f(N, x, a, b);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int f2 = f(N, x, a, b);
	if (f1 > f2) cout << "Limak" << endl;
	if (f1 < f2) cout << "Radewoosh" << endl;
	if (f1 == f2) cout << "Tie" << endl;
}