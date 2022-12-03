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
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<int, ll> i_ll;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 10;
double EPS = 1e-10;

int main() {
	int N; cin >> N;
	vector<int> a(N);
	rep(i, N) cin >> a[i];
	int sum = 0;
	rep(i, N) sum += a[i];
	if (sum) {
		cout << "YES" << endl;
		cout << 1 << endl;
		cout << 1 << ' ' << N << endl;
		return 0;
	}
	int i;
	for (i = 0; i < N && !a[i]; i++);
	if (i == N) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	cout << 2 << endl;
	cout << 1 << ' ' << i + 1 << endl;
	cout << i + 2 << ' ' << N << endl;
}