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
struct edge { int src, dst; };

int const MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-9;
ll INF = LLONG_MAX / 2;

bool f(int N, vector<int> a) {
	vector<ll> pre(N + 1), suf(N + 1);
	for (int i = 1; i <= N; i++)
		pre[i] = pre[i - 1] + a[i - 1];
	for (int i = N - 1; i >= 0; i--)
		suf[i] = suf[i + 1] + a[i];
	set<ll> st;
	for (int i = 0; i <= N; i++) {
		ll x = pre[i] - suf[i];
		if (x % 2 == 0 && st.count(x / 2)) return true;
		if (i < N) st.insert(a[i]);
	}
	return false;
}

int main() {
	int N; cin >> N;
	vector<int> a(N);
	rep(i, N) scanf("%d", &a[i]);
	bool yes = false;
	if (f(N, a)) yes = true;
	reverse(a.begin(), a.end());
	if (f(N, a)) yes = true;
	cout << (yes ? "YES" : "NO") << endl;
}