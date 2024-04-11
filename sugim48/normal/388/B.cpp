#define _USE_MATH_DEFINES
#include <algorithm>
#include <bitset>
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

vector<int> a, b;

void f(int u, int v) {
	a.pb(u); b.pb(v);
}

int main() {
	int N = 50;
	for (int u = 0; u + 1 < N * 2; u++) f(u, u + 1);
	for (int i = 0; i < N; i++) {
		f(N*2 + i * 3, N*2 + i * 3 + 1);
		f(N*2 + i * 3, N*2 + i * 3 + 2);
		f(N*2 + i * 3 + 1, N*2 + i * 3 + 3);
		f(N*2 + i * 3 + 2, N*2 + i * 3 + 3);
	}
	ll x; cin >> x;
	for (int i = 0; i < N; i++)
		if (N - 1 - i < 32 && (x>>(N - 1 - i) & 1)) f(i * 2, N*2 + i * 3);
	int M = N * 5 + 1;
	vector<vector<bool> > A(M, vector<bool>(M));
	for (int i = 0; i < a.size(); i++) {
		int u = a[i], v = b[i];
		if (u == 1) u = M - 4;
		else if (u == M - 4) u = 1;
		if (v == 1) v = M - 4;
		else if (v == M - 4) v = 1;
		A[u][v] = A[v][u] = true;
	}
	cout << M << endl;
	rep(u, M) {
		rep(v, M) cout << (A[u][v] ? 'Y' : 'N');
		cout << endl;
	}
}