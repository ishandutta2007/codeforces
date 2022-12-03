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
double EPS = 1e-10;

int main() {
	random_device rd;
	mt19937 mt(rd());
	int N; cin >> N;
	int N2 = N * 2;
	vector<int> a(N), b(N);
	rep(i, N) {
		scanf("%d%d", &a[i], &b[i]);
		a[i]--; b[i]--;
	}
	vector<int> p(N2);
	rep(i, N) {
		p[a[i]] = b[i];
		p[b[i]] = a[i];
	}
	vector<bool> x(N2);
	rep(i, N) {
		if (true && mt() % 2) x[a[i]] = true;
		else x[b[i]] = true;
	}
	vector<int> v;
	rep(i, N2) v.pb(i);
	while (!v.empty()) {
		int V = v.size();
		swap(v[V - 1], v[mt() % V]);
		int i = v[V - 1];
		v.pop_back();
		bool ok = true;
		if (x[i] && x[(i + 1) % N2] && x[(i + 2) % N2]) ok = false;
		if (!x[i] && !x[(i + 1) % N2] && !x[(i + 2) % N2]) ok = false;
		if (ok) continue;
		int j = (i + mt() % 3) % N2;
		x[j] = !x[j];
		v.pb(j);
		v.pb((j + N2 - 1) % N2);
		v.pb((j + N2 - 2) % N2);
		int k = p[j];
		x[k] = !x[k];
		v.pb(k);
		v.pb((k + N2 - 1) % N2);
		v.pb((k + N2 - 2) % N2);
	}
	rep(i, N) printf("%d %d\n", x[a[i]] ? 1 : 2, x[b[i]] ? 1 : 2);
}