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
	vector<int> a(N - 1), b(N - 1);
	rep(i, N - 1) scanf("%d%d", &a[i], &b[i]), a[i]--, b[i]--;
	vector<int> c(N);
	rep(u, N) scanf("%d", &c[u]);
	int cnt = 0;
	vector<int> d(N);
	rep(i, N - 1) if (c[a[i]] != c[b[i]])
		cnt++, d[a[i]]++, d[b[i]]++;
	rep(u, N) if (d[u] == cnt) {
		cout << "YES" << endl;
		cout << u + 1 << endl;
		return 0;
	}
	cout << "NO" << endl;
}